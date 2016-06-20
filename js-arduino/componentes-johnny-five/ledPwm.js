/*	Exemplo usando:
*	Led + Potenciometro + PWM
*/

var five = require("johnny-five"),
    board, led, pot;
board = new five.Board();

board.on("ready", function() {

  led = new five.Led(9);
  pot = new five.Sensor("A1");

  pot.on("data", function(){
    led.brightness(this.analog);
  });

});
