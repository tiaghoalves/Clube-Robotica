/* Exemplo usando:
*  LedPwm + Potenciometro + LDR
*/

var five = require("johnny-five"),
    board, ldr, led, pot;
board = new five.Board();

board.on("ready", function() {

  led = new five.Led(9);
  pot = new five.Sensor("A1");
  ldr = new five.Sensor("A0").scale([0, 100]);

  ldr.on("change", function(){
      console.log("Valor: " + this.value);
      if (this.value > 50) {
        led.off();
      }
  });

  pot.on("data", function(){
    led.brightness(this.analog);
  });

});
