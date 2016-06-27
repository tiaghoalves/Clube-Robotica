var five = require("johnny-five");
var board = new five.Board();

board.on("ready", function() {

  var servo = new five.Servo(10);

  // Sweep from 0-180 and repeat.
  servo.sweep();
});