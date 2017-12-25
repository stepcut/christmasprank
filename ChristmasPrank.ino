// demonstrate pulse with slow changes in pulse width

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Snooze.h>

#include "AudioSampleStupidtestloop1monowav_.h"

// GUItool: begin automatically generated code
AudioPlayMemory          playMem1;       //xy=430,273
AudioOutputAnalog        dac1;           //xy=669,268
AudioConnection          patchCord1(playMem1, dac1);
// GUItool: end automatically generated code

const int pirPin        = 1;
const int LED   = 13;
volatile boolean motion = false;

/*** Must be global ***/
SnoozeBlock config;

void pirISR ()
{
    cli();
    motion = digitalRead(pirPin);
    sei();
}

void setup(void)
{

  // Set up audio
  AudioMemory(8);

  // Setup PIR
//  pinMode(pirPin, INPUT);
//  attachInterrupt(pirPin, pirISR, CHANGE);

  // setup low power
  pinMode(LED, OUTPUT);
  config.pinMode(pirPin, INPUT, LOW);
}

void loop() {
#if 0
    if (!playMem1.isPlaying() && motion) {
        playMem1.play(AudioSampleStupidtestloop1monowav_);
    }

    if (playMem1.isPlaying() && !motion) {
        playMem1.stop();
    }

    if (!playMem1.isPlaying()) {
#endif
        if (digitalRead(pirPin) == LOW) {
            if (playMem1.isPlaying()) {
                playMem1.stop();
            }
            digitalWrite(LED, HIGH);
            delay(100);
            digitalWrite(LED, LOW);
            delay(100);
            Snooze.sleep( config );
        } else {
            if (!playMem1.isPlaying()) {
                playMem1.play(AudioSampleStupidtestloop1monowav_);
            }
            digitalWrite(LED, HIGH);
        }
#if 0
    }
#endif
}
