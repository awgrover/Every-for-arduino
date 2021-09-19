*
Blink, using an Every::Toggle.

The Every::Toggle example is a clearer way to do this.
  * /

#include <Every.h>

  Every::Toggle t1(200); // Like Every, but has .state

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  // this does not block the loop
  if ( t1() ) {
    // t1 keeps track of HIGH/LOW (true/false) for us:
    // state goes true,false,true,false...
    digitalWrite( LED_BUILTIN, t1.state );
  }

  // .state can be checked anytime
  if (t1.state) {
    // do something
  }

  // other things can happen
}
