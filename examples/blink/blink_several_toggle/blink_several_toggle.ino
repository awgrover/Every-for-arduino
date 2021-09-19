/*
  Blink several LEDs, using Every.

  The Every::Toggle has a more convenient .state
*/

#include <Every.h>

Every::Toggle builtin_blink(500); // blink every 500msec
Every::Toggle external_blink(100);
constexpr int external_led = 9; // put an led on this pin

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(external_led, OUTPUT);
}

void loop() {

  // blink builtin
  // this does not block the loop
  if ( builtin_blink() ) {
    digitalWrite( LED_BUILTIN, builtin_blink.state);
  }

  // blink external WHILE builtin also blinks
  // they don't block each other
  if ( external_blink() ) {
    digitalWrite( external_led, external_blink.state);
  }
}
