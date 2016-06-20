var http = require('http').createServer(servidor);
var fs = require('fs');
var io = require('socket.io').listen(http);
var five = require('johnny-five');
var plotly = require('plotly')("TiagoAlves", "mampp5bmwd"); 	// API de graficos para o LDR

var token = '18zisse30t';
var board = new five.Board();

var init_data = [{
    x : [],
    y : [],
    stream : {
        token : token,
        maxpoints : 500
    }
}];

var layout = {fileopt : "extend", filename : "photoresistor nodey arduino!"};

board.on('ready', function(){
 	console.log("Arduino Pronto!");
 	var sensorLuz = new five.Sensor({ pin: "A0", freq: 100 });
 	var sensorPot = new five.Sensor("A1");
 	var led = new five.Led("9");

 	plotly.plot(init_data,layout,function (err, res) {
 		if (err) console.log(err);
    	console.log(res);

        var stream = plotly.stream(token, function (err, res) {
        	      if (err) console.log(err);
      			  console.log(res);
        });
        
        sensorLuz.scale([0, 100]).on("data", function() {
            var data = { x : Date(), y : this.value };
            stream.write(JSON.stringify(data)+'\n');
        });

        sensorLuz.scale([ 0, 100 ]).on("data", function() {
      		data = {
      		  x : getDateString(),
      		  y : 0,
      		  marker : {
      		    size : this.value
      		  }
      		};
      		// write the data to the plotly stream
      		stream.write(JSON.stringify(data)+'\n');
    	  });
  });

 	sensorLuz.on('change', function(){
 		io.emit('sensorLuz', this.value.toFixed() + '%');
 	});

	sensorPot.on('change', function(){
 		io.emit('sensorPot', this.analog);
 	});

 	sensorPot.on('data', function(){
 		led.brightness(this.analog);
 	});

  io.on("connection", function(socket){
  socket.on('click', function(botao){
      console.log(botao);
      $(botao).onclick(function(){
        led.toggle();
      });
    })
  });
});

// little helper function to get a nicely formatted date string
function getDateString () {
  var time = new Date();
  // 14400000 is (GMT-4 Montreal)
  // for your timezone just multiply +/-GMT by 3600000
  var datestr = new Date(time - 14400000).toISOString().replace(/T/, ' ').replace(/Z/, '');
  return datestr;
}

function servidor(req, res){
	console.log(req.url);
	res.writeHead(200);
	res.end(fs.readFileSync('view/index.html'));
};

http.listen(4000, function(){
	console.log("Servidor Online em http://localhost:4000");
	console.log("Para sair Ctrl+C");
});
