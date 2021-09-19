/*
  Blink several LEDs, using Every.

  The Every::Toggle has a more convenient .state
*/

#include <Every.h>

Every builtin_blink(500); // blink every 500msec
Every external_blink(100);
constexpr int external_led = 9; // put an led on this pin

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(external_led, OUTPUT);
}

void loop() {

  // blink builtin
  // this does not block the loop
  if ( builtin_blink() ) {
    // opposite of the last digitalWrite()
    int opposite = ! digitalRead( LED_BUILTIN );
    digitalWrite( LED_BUILTIN, opposite);
  }

  // blink external WHILE builtin also blinks
  // they don't block each other
  if ( external_blink() ) {
    // opposite of the last digitalWrite()
    int opposite = ! digitalRead( external_led );
    digitalWrite( external_led, opposite);
  }
}
