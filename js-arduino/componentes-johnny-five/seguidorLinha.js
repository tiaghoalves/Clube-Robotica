var five = require("johnny-five");
var board = new five.Board();

board.on("ready", function() {

  var servos = new five.Servos({
    direita: 10,
    esquerda: 11
  });
  
  var qti = new five.Sensors([0, 1]);

  this.repl.inject({
    on: function(){
      servos.center();
      servos.home();
    },
    off: function(){
      servos.stop();
    }
  });

  qti.within([0, 400], function(){
    servos.min();
  });

  qti.within([500, 1000], function(){
    servos.max();
  });
});
