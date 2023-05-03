#include <every.h> // Every by Alan Grover

/* short version

  unsigned long serial_start = millis();
  while ( ! Serial && (millis() - serial_start < 1000) ) { delay(10); }

*/

void setup() {
  // Standard block to wait for serial on "USB CDC", aka native usb, e.g. samd21 etc's
  // if not plugged in to usb, continue eventually
  // This also gives you 3 seconds to upload if you program has a hard-hang in it
  static Every serial_wait(3*1000); // how long before continuing
  static Every fast_flash(50);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  // always wait, assume serial will work after serial_wait time
  while(! (Serial || serial_wait()) ) {
    if (fast_flash()) digitalWrite( LED_BUILTIN, ! digitalRead(LED_BUILTIN) );
    delay(10); // the delay allows upload to interrupt
    } 
  Serial.println(F("Start " __FILE__ " " __DATE__ " " __TIME__));

  // your other setup code goes here
}

void loop() {
  static Every::Pattern heartbeat; // default pattern is a heartbeat
  static Every hello(2000);
  if (heartbeat()) {
    digitalWrite( LED_BUILTIN, heartbeat.state % 2);
  }

  // put your main code here, to run repeatedly:

  // replace this, just to show serial
  if (hello()) Serial.println(millis());
  

}
