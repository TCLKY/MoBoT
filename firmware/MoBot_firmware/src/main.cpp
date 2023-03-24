#include <Arduino.h>
#include <time.h>
#include <SoftwareSerial.h>
#include <Wheelctl.h>


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

    Wheel maroue(2,4);


    maroue.MoveWheelByStep(100,true, 10.0);
}