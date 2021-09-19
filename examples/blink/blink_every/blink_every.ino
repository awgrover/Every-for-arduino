/*
  Blink, using an Every.

  The Every::Toggle example is a clearer way to do this.
*/

#include <Every.h>

Every blink(500); // blink every 500msec

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  // this does not block the loop
  if ( blink() ) {
    // opposite of the last digitalWrite()
    int opposite = ! digitalRead( LED_BUILTIN );
    digitalWrite( LED_BUILTIN, opposite);
  }

  // other things can happen
}
