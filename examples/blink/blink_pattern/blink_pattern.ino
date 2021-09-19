/*
  Blink an LED in a more complex pattern with Every::Pattern.

  The Every::Toggle can be thought of as a special case.
*/

// use this magic to always get "size of array" right:
template <typename T, unsigned S> inline constexpr unsigned array_size(const T (&v)[S]) {
  return S;
};

#include <Every.h>

// need a pattern
unsigned long _heartbeat[] = {150, 250, 150, 700}; // off, on, off, on

// this is dangerous if you get the count wrong, so use array_size()
Every::Pattern heartbeat(array_size(_heartbeat), _heartbeat);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  // Time to change on/off?
  if ( heartbeat() ) {
    // convert 0,1,2,3 to true/false
    boolean is_on = heartbeat.state % 2; // 0th=false, 1st=true, 2nd=false...
    digitalWrite( LED_BUILTIN, is_on);
  }

  // do other stuff while heartbeat
}
