# Comparison with other libraries.

e.g. delay()

As of 2021, September.

### delay(), builtin

* delay() is builtin, Every is a library to install.
* delay() blocks, and stops the whole program.
* Every doesn't block, so you can do many timer related things together. This is the whole motivation.
* Every tries to prevent drift.

### AsyncDelay, Steve Marple <stevemarple@googlemail.com>

* A non-blocking timer.
* You can do periodics by explicitly calling `repeat()`, which tries to prevent drift.

### BlockNot, Michael Sims <sims.mike@gmail.com>

* Combines periodics and a timer, so more similar to Every.
* A little more complex.
* Can try to prevent drift.
* Tries to cover a lot of cases.

### "MyDelay"
  Author: Marshall Gates <mggates@gmail.com>
    Maintainer: Marshall Gates <mggates@gmail.com>
      Sentence: Arduino library that provides a non-blocking repeating timer with callback functionality.

      https://github.com/mggates39/MyDelay

### "NoDelay"
  Author: Mario Avenoso <mario@mtechcreations.com>
    Sentence: Arduino library to make use of the Millis funtion for non Blocking Delays.

      sntence: Arduino library to make use of the Millis funtion for non Blocking Delays.

### Ticker, Stefan Staub <email@domain.com>
  Sentence: A library for creating Tickers which can call repeating functions. Replaces delay() with non-blocking functions.

      https://github.com/sstaub/Ticker


### CMMC Easy, Chiang Mai Maker Club<info@cmmakerclub.com>

* Very thin documentation.
* Has dedicated "blink".

### RBD_Timer"
  Author: Alex Taujenis <alex.taujenis@gmail.com>
    https://github.com/alextaujenis/RBD_Timer

### TimerEvent"
  Author: cygig <rubbish52@hotmail.com>
    Maintainer: cygig <rubbish52@hotmail.com>
      Sentence: TimerEvent is a non-blocking alternative to the delay() function.
https://github.com/cygig/TimerEvent

### UniversalTimer"
  Author: Michael Granz
    Maintainer: Michael Granz <michaelgranzDev@gmail.com>
      Sentence: Easy to use, multifunctional and non-blocking timer.
      https://github.com/michaelgranz/UniversalTimer

### arduino-timer
  Author: Michael Contreras
    Maintainer: Michael Contreras
      Sentence: Timer library for delaying function calls
      https://github.com/contrem/arduino-timer

### avdweb_VirtualDelay"
  Author: Albert van Dalen
    Maintainer: Albert van Dalen <a@maxun.cc>
      Sentence: Allows using (multiple) delays without blocking code execution. Arduino Uno and Zero.
      https://github.com/avandalen/VirtualDelay

### muTimer"
  Author: Michael Uray <mu@spamfence.net>
    Maintainer: Michael Uray <mu@spamfence.net>
      Sentence: Arduino library to easily use on/off delays and cycle timers with non-blocking functions.
      https://github.com/MichaelUray/muTimer

### ptScheduler"
  Author: Vishnu Mohanan
    Maintainer: Vishnu Mohanan
      Sentence: Arduino library for writing non-blocking periodic tasks without using delay or millis routines.
      https://github.com/vishnumaiea/ptScheduler

### SimpleTicker"
  Author: JSC electronics
    Maintainer: JSC electronics, development@jsce.cz
      Sentence: A library for creating Tickers, which will notify user that a given period has elapsed. Replaces delay() and allows user
      s to write non-blocking code.
https://github.com/JSC-electronics/Ticker

### DelayExec"
  Author: Sébastien Millet
    Maintainer: Sébastien Millet <milletseb@laposte.net>

* Different style.

### table

https://cse.google.com/cse?cx=008830049033802121810%3Azgsyidwem5w&q=every
    try "delay" "timer" "period" "millis"
https://www.arduino.cc/reference/en/libraries/category/timing/


| Library | Author | Source | Feature | Example |
| delay() | builtin | | blocking statement | `delay(500);` |
| DMTimer 1.3.0 | Nicolas Simonnet | [Library Manager](https://github.com/toxnico/DMTimer) | style | declare period, if-test-block |
| | | | declare | `DMTimer myTimer(microseconds)` |
| | | | test | `if(myTimer.isTimeReached()) { ... ` |
| | | | change interval | `.setInterval(250000)` |
| | | | auto-repeat | only |
| | | | one-shot | no |
| | | | drift correction | ? |
| everytime 1.0 | Karl Fessel | [Library Manager](https://github.com/kfessel/everytime) | style | macro block |
| | | | declare | none! |
| | | | test | macro block: `every(1500) { ... }` |
| | | | change interval | `.setInterval(250000)` |
| | | | auto-repeat | only |
| | | | one-shot | no |
| | | | drift correction | only large drift, tunable |
| | | | notes: | static vars (like `now456`), so won't work well in objects |
| | | | notes: | lots of explicity variations for types, arguments, etc. |
| EveryTimer 1.1.1 | [Alessio Leoncini](https://technologytourist.com/) | [Library Manager](https://github.com/bluemurder/EveryTimer) | style | register function |
| | | | declare | no period: `EveryTimer timer;` ... register in setup: `timer.Every(some-millis, action-function)` |
| | | | test | `.Update()` |
| | | | change interval | `.setInterval(250000)` |
| | | | auto-repeat | `.Every(msec, fn)` |
| | | | one-shot | `OneShotTimer timer;` ... `timer.OneShot(10000, action);` ... `.Update()` |
| | | | drift correction | no |
| | | | other | `.Stop()`, `.Start()` but can't test if running |
| | | | notes: | period is given at the "use" not declaration |
| | | | notes: | different include for oneshot |
| | | | notes: | different include for oneshot |
| | | | notes: | does the unsigned math the hard way, and wrong |
| | | | notes: | OneShotTImer is sort of a subclass, fails liskov? |
| FireTimer | https://www.arduino.cc/reference/en/libraries/firetimer/ |
| GyverTimer | https://www.arduino.cc/reference/en/libraries/gyvertimer/ |
| IntervalCallback | https://www.arduino.cc/reference/en/libraries/intervalcallback/ |
| ledflasher | https://www.arduino.cc/reference/en/libraries/ledflasher/ |
| MillisTimer | https://www.arduino.cc/reference/en/libraries/millistimer/ |
| MillisStopper | https://www.arduino.cc/reference/en/libraries/millistopper/ |
| MuTimer | https://www.arduino.cc/reference/en/libraries/mutimer/ |
| MyDelay | https://www.arduino.cc/reference/en/libraries/mydelay/ |
| NeoTimer | https://www.arduino.cc/reference/en/libraries/neotimer/ |
| NoDelay | https://www.arduino.cc/reference/en/libraries/nodelay/ |
| ptScheduler | https://www.arduino.cc/reference/en/libraries/ptscheduler/ |
| SandTimer | https://www.arduino.cc/reference/en/libraries/sandtimer/ |
| SimpleTicker | https://www.arduino.cc/reference/en/libraries/simpleticker/ |
| spin-timer | https://www.arduino.cc/reference/en/libraries/spin-timer/ |
| SSVTimer | https://www.arduino.cc/reference/en/libraries/ssvtimer/ |
| StensTimer | https://www.arduino.cc/reference/en/libraries/stenstimer/ | 
| Ticker | https://www.arduino.cc/reference/en/libraries/ticker/ |
| https://www.arduino.cc/reference/en/libraries/timealarms/ |
| https://www.arduino.cc/reference/en/libraries/timedstate/ |
| https://www.arduino.cc/reference/en/libraries/timeoutcallback/ |
| https://www.arduino.cc/reference/en/libraries/timerevent/ |
| https://www.arduino.cc/reference/en/libraries/timerms/ |
| https://www.arduino.cc/reference/en/libraries/universaltimer/ |
| https://www.arduino.cc/reference/en/libraries/utimerlib/ |
| https://www.arduino.cc/reference/en/libraries/variabletimedaction/ |
| https://www.arduino.cc/reference/en/libraries/wiring-timer/ |
| https://www.arduino.cc/reference/en/libraries/elapsedmillis/ |
| https://github.com/avandalen/VirtualDelay |
| https://www.arduinolibraries.info/libraries/tasker |
| https://github.com/cmmakerclub/CMMCEasy |
| https://github.com/RobTillaart/CountDown |
| https://github.com/tfeldmann/Arduino-Timeout |
| https://github.com/Z01NE/MyAlarm|
| https://github.com/SMFSW/SeqTimer |
| https://github.com/kiryanenko/SimpleTimer |

| tons of schedulers |
| https://www.arduino.cc/reference/en/libraries/delayexec/ |
| https://www.arduino.cc/reference/en/libraries/schedtask/ |
| Strober | https://www.arduino.cc/reference/en/libraries/strober/ | leds |
| Switch2_lib | https://www.arduino.cc/reference/en/libraries/switch2_lib/ | digital pins |
| Switch_lib | https://www.arduino.cc/reference/en/libraries/switch_lib/ |
| SoftTimer |
| SoftTimers |
| ScheduleTable | https://www.arduino.cc/reference/en/libraries/scheduletable/ |
| RTCTimer | https://www.arduino.cc/reference/en/libraries/rtctimer/ |
| RBDTimer | https://www.arduino.cc/reference/en/libraries/rbd_timer/ |
| PollingTimer | https://www.arduino.cc/reference/en/libraries/pollingtimer/ |
| MyAlarm | https://www.arduino.cc/reference/en/libraries/myalarm/ |
| msTask | https://www.arduino.cc/reference/en/libraries/mstask/ | Timer1 |
| looper | https://www.arduino.cc/reference/en/libraries/looper/ | scheduler |
| HaCTimers | https://www.arduino.cc/reference/en/libraries/hactimers/ | events |


Other concerns:

* bytes of code per use
* bytes of ram per use (or flash)
* what other issues were taken into consideration? e.g. samd sleeps
* can you ask for the state? toggle, pattern, running?
* do you have to call something to detect expirations? e.g. .update() or the "test"?
* does it fire on the first test, or delay first? settable?




### Other

E.g. Animately, Nicholas Koza: an animation framework.
Several multitasking libraries (CoopTask, AceRoutine, etc).

Other concerns:

* bytes of code per use
* bytes of ram per use (or flash)
* what other issues were taken into consideration? e.g. samd sleeps




### Other

E.g. Animately, Nicholas Koza: an animation framework.
Several multitasking libraries (CoopTask, AceRoutine, etc).
