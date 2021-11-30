/* Demonstrate a sequence of times.
    NOTE: serial is baud rate 115200 ! Adjust your serial window!
    Blinks led and prints time.
*/

#include <every.h>

// useful util: gives the array-size of a static array, usable at "const expression" time
template <typename T, unsigned S> inline constexpr unsigned array_size(const T (&v)[S]) {
  return S;
};


// a sequence of times (msec)
static const unsigned long pattern[] = { 300, 600, 1000, 1500 }; // even for repeat on,off,...
Every::Pattern timed_pattern(array_size(pattern), pattern);

unsigned long elapsed = 0;

void setup() {
  // The samd based arduinos need to wait for serial, can take over 1 sec!
  // but, we should timeout, and what do we do if we aren't connected to usb?
  while (!Serial) { delay(20); } // pause for usb interrupt/reload
  Serial.begin(115200);
  Serial.print("Start ");
  Serial.println(__FILE__);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); // start on

  // Look at the first output to see how long it can take to get here (over 1 sec on a Zero (Metro M0))
  Serial.print(millis());
  Serial.println(" ->On ");
  elapsed = millis();
  
  // Time has already passed since global construction, reset to count from now
  timed_pattern.reset();
}

void loop() {

  // has a time period expired?
  if ( timed_pattern() ) {
    
    // Should the LED be on or off for the NEXT period?
    boolean polarity = timed_pattern.state % 2; // 0=off, 1=on, 2=off, 3=on
    digitalWrite(LED_BUILTIN, polarity);

    // beginning of a sequence:
    if ( timed_pattern.state == 0) Serial.println();

    Serial.print(millis() - elapsed);
    Serial.print(polarity ? " ->On " : " ->Off ");
    Serial.print(timed_pattern.state); Serial.print(" "); Serial.print(timed_pattern.state == 0); Serial.print(" ");
    Serial.println();
    elapsed = millis();
  }

}
