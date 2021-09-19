# Library "Every": Periodic actions and timers for Arduino.

    #include <Every.h> // Every for Arduino, by Alan Grover

(For earlier commit history, see https://github.com/awgrover/misc_arduino_tools/commits/master/every )

(For a Processing version, see )

(For a circuitpythong version, see )

Non-blocking replacements for delay().  Several convenient ways to use them.

* `Every` will let you act _at_ every `n` `millis()`.
* `Timer` will let you act _once_ when `n` `millis()` has gone by.
* `Every::Toggle` will keep track of a toggling `boolean` for you.
* `Every::Pattern` is like `Every` but you can have a sequence of different intervals.

## Every: every n milliseconds

Replaces `delay(n)`, without blocking. So multiple things can run together.

See `examples`.

    static Every t1(100);  // every 100 msec
    
    if ( t1() ) { do it; }

### Details

The `Every` object has to be static/global, since it needs to remember the "last" time.

The `t1()` (the instance + ()) is convenient magic: returns a boolean meaning "just expired?" (and restarts for the next interval). Note that `t1()` is true only once, till the next interval. All the classes in this library follow that pattern to test for an interval's expiration.

The initial event does not happen immediately, it happens in n msec. If you want an immediate first
event, supply "true" for the "now" argument in the constructors: 
    
    Every t1(100, true) // t1() is true on first test, i.e. immediately

The interval can be up to 2^32 msecs (full range of millis()). Sadly, that's 4 bytes. 
Remember to provide "UL" on numbers larger than 32000, e.g. 

    Every t1(50000UL) // "UL" for large numbers

Takes 8 bytes of RAM for `Every` object.

Resists drift by "re-aligning" when it detects that the interval has expired. E.g. if it should
happen every 100 msec, but you don't test till 30msec late (i.e. at 130msec), it will fire, and
re-align to fire at 200msec. Thus, it's not an interval, it's "_on_ every n msec". For small
amounts of drift, this is probably nice. For larger amounts, might be confusing (see Timer). 

There's no suspend/stop. That would add at least 1 boolean more memory!

You can change the interval:

    t1.reset(1000); // now it's 1 second

## Every::Toggle: keep track of on/off alternation

Like `Every`, but keeps track of alternation. E.g. for a blink.

See `examples`.

    // "blink" example using EveryToggle
    Every::Toggle t1(200); // adds the .state() method
    void setup() { pinMode(LED_BUILTIN, OUTPUT); }

    void loop() {
      if ( t1() ) {
        digitalWrite( LED_BUILTIN, t1.state ); // state goes true,false,true,false...
        }
    }

### Details

Adds the `.state` variable. It keeps the true/false state till the next interval.

## Timer: tell when an interval has expired (once).

Like `Every`, but only happens once. E.g. "2 seconds after a button push, make a sound".
You can restart a timer.

See `examples`.

    static Timer t1(1000); // and starts running

    // once, after start of program
    if ( t1() ) { 
        Serial.println("1 second"); 
    }

Don't run till .reset()

      static Timer t1(1000, false); // will never expire, unless you reset()

Restart the timer 

    if ( digitalRead(SwitchPin) ) t1.reset()

Is timer running? `.running`

    if (t1.running) { it's running now, not expired yet }

Pause the timer `.running`

    t1.running = false; // .reset() will start over, = true will continue

Are we after an expiration? `.after` `.until`

    // you only see true for t1() once, but .after() is persistent
    if ( t1.after() ) ... // careful, this is really testing .running

    // .until is the opposite, i.e. still running
    if ( t1.until() ) ...

## Every::Pattern: a sequence of intervals.

Easier than stringing together a series of Timers. Repeats the sequence.

See `examples/blink`.

    template <typename T, unsigned S> inline constexpr unsigned array_size(const T (&v)[S]) { return S; };

    unsigned long _heartbeat[] = {150, 250, 150, 700}; // off, on, off, on

    // this is dangerous if you get the count wrong, so use array_size()
    Every::Pattern heartbeat(array_size(_heartbeat), _heartbeat);

    if ( heartbeat() ) {
        // convert 0,1,2,3 to true/false
        boolean is_on = heartbeat.state % 2; // 0th=false, 1st=true, 2nd=false...
        digitalWrite( LED_BUILTIN, is_on);
    } 

Expire on first test

    Every::Pattern heartbeat(array_size(_heartbeat), _heartbeat, true); // like Every's 2nd arg

What step in the sequence?

    heartbeat.state; // 0,1,2,3

Restart to the beginning of the first interval

    heartbeat.reset() // You can't change the intervals via reset()

## lambda

Instead of the `if ()` pattern to test for interval, you can use lambdas

    // inline function, aka lambda:
    // (also returns true when the interval happens)
    t1( []() { // magic "lambda" syntax
        // put code here, like
        digitalWrite( LED_BUILTIN, ! digitalRead( LED_BUILTIN ) );
        } );

### Details

You can use a lambda that has a capture. But you don't need that to refer to global/static objects.
