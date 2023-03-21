#include <arduino.h>
#include <time.h>

#define DIR_PIN_R  2
#define DIR_PIN_L  3
#define STEP_PIN_R  4
#define STEP_PIN_L  5

#define STEP 200
#define STEP_UP_MICRO 20



void setup(){

    pinMode(DIR_PIN_R, OUTPUT);
    pinMode(DIR_PIN_L, OUTPUT);
    pinMode(STEP_PIN_R, OUTPUT);
    pinMode(STEP_PIN_L, OUTPUT);


}
void loop(){

    int N = 2;
    int speed = 100;
    int i = 0;
    for(i=0;i< N*STEP;i++){

        digitalWrite(STEP_PIN_R,HIGH);
        delayMicroseconds(STEP_UP_MICRO);
        digitalWrite(STEP_PIN_R, LOW);
        delay(speed);
    }
}