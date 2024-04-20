/*
  Title: Clap Activated Relay System
  Description: This Arduino program activates a relay when it detects two claps in quick succession using a sound sensor. 
  It also triggers a buzzer sound for an indication.
  
  Libraries:
  - Arduino.h: Standard Arduino library for basic functionality.
  
  Pins:
  - SOUND_SENSOR: Pin connected to the sound sensor's output.
  - RELAY: Pin connected to the relay module for control.
  - BUZZER: Pin connected to the buzzer module for sound indication.
  
  Variables:
  - number: Integer to count the number of claps detected.
  - start_of_timer: Long variable to store the starting time of the clap detection.
  - timer: Long variable to track the current time for clap detection.
  - buzzer: Boolean variable to indicate whether the buzzer has been activated.
  
  Setup:
  - Configures pin modes for SOUND_SENSOR, BUZZER, and RELAY.
  - Sets the initial state of the RELAY to HIGH.

  Loop:
  - Reads the status of the sound sensor.
  - If a sound is detected (status LOW):
    - If it's the first clap, record the starting time and increment the clap count.
    - If it's not the first clap and it occurs within 50 milliseconds of the previous clap, increment the clap count.
  - If more than 400 milliseconds have passed since the first clap:
    - If two claps have been detected:
      - Activate the buzzer for an indication by generating a 4KHz sound signal three times.
    - Reset the clap count.
*/

//include necessary libraries
#include <Arduino.h>

//define pins
#define SOUND_SENSOR 12
#define RELAY 5
#define BUZZER 13

//define variables
int number = 0; //number of claps
long start_of_timer = 0;
long timer = 0;
boolean buzzer = false;

//things that program does on the start of the program
void setup() {
    pinMode(SOUND_SENSOR, INPUT);
    pinMode(BUZZER, OUTPUT);
    pinMode(RELAY, OUTPUT);
    digitalWrite(RELAY, HIGH);
}

//things that program does in a loop
void loop() {
    int sound_sens_status = digitalRead(SOUND_SENSOR);
    if (sound_sens_status == 0){ //when sound sensor records sound
        if (number == 0){
            start_of_timer = timer = millis();
            number++;
        }
        else if (number > 0 && millis() - timer >= 200){ //check if both claps were in short period of time
            timer = millis();
            number++;
        }
    }
    if (millis() - start_of_timer >= 400){ //if more than 400 miliseconds have elapsed since the first clap
        if (number == 2){ //if two claps have been done in short period of time
            if (!buzzer){
                buzzer = true;
                for (int i = 0; i < 3; i++){ //play sound 3 times
                    tone(BUZZER, 4000); //send 4KHz sound signal
                    delay(1000); //wait for 1 second
                }
            }
        }
        number = 0;
    }
}