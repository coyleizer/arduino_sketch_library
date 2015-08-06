//
//Date: 5/31/15
//Version: 1.0
//
//Comments:
//This sketch defines a digital output and blinks the LED on and off. The delay can be used to set how fast the LED flashes. 
//This is based on an Uno board with a LED attached to pin 13 but the pin_led variable can be used to assign a different output for an external LED.

// Global Variables
int delay_led = 50;  // Delay in msec (smaller number flashes LED faster)
int pin_led = 12;    // Define which digital output pin to use that is attached to an LED


// The setup runs once when you press reset or power on the board
void setup() {
  // initialize digital pin as an output
  pinMode(pin_led, OUTPUT);

}

// Main code for Arduino goes in the loop function to be run over and over again
void loop() {
  // write to digital pin output - turn it on and off with a delay which will flash the LED on the Uno board
  digitalWrite(pin_led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(delay_led);              // wait for a defined period of time
  digitalWrite(pin_led, LOW);    // turn the LED off by making the voltage LOW
  delay(delay_led);              // wait for a defined period of time
  
}

