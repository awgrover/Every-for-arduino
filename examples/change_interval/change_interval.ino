#include <every.h>
/*
 You can change the interval.
 E.g. start with the default and then set it in setup()
 Or, adjust it due to some event (pot setting, for example).
 */
 
Every default_int; // default interval is 1000msec

void setup() {
  Serial.begin(9600);

  Serial.print("Every default is ");
  Serial.println( default_int.interval );
  Serial.println("So:");
  pinMode(LED_BUILTIN, OUTPUT);
  
  int ct = 0;
  while (1) {
    if ( default_int() ) {
      Serial.println(millis());
      ct += 1;
      if (ct >= 4) break;
    }
  }

  Serial.println("Reset to 300, so:");
  default_int.reset(300, true);
}

void loop() {
  if ( default_int() ) {
    Serial.println(millis());
    digitalWrite(LED_BUILTIN, ! digitalRead(LED_BUILTIN));
  }
}
