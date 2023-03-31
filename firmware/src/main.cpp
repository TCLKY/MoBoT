#include <Arduino.h>
#include <time.h>
#include <SoftwareSerial.h>
//#include <WheelAxle.h>

#define DIR_PIN_R  2
#define DIR_PIN_L  3
#define STEP_PIN_R  5
#define STEP_PIN_L  8
/*
#define STEP 200
#define STEP_UP_MICRO 20

WheelAxle essieu(5,8);

DRV8825 motor1(200,1,4);
DRV8825 motor2(200,1,6);

SyncDriver controller(motor1,motor2);

int err = 0;

    
*/
void setup(){

    pinMode(DIR_PIN_R, OUTPUT);
    pinMode(DIR_PIN_L, OUTPUT);
    pinMode(STEP_PIN_R, OUTPUT);
    pinMode(STEP_PIN_L, OUTPUT);
    digitalWrite(STEP_PIN_R,HIGH);
    delay(1500);
    digitalWrite(STEP_PIN_R,LOW);
    Serial.begin(9600);
    /*controller.begin(60,1);
    controller.rotate(90,90);
    essieu.WheelInvert(WheelAxle::axle_side::RIGHT);
*/
    

}
void loop(){

    
    Serial.print("hello");
   // Serial.print(essieu.GetInverted());
      
    digitalWrite(5,HIGH);
    delay(1500);
    digitalWrite(5,LOW);
/*
    err = essieu.AxleMove(400,25);
   
    delay(250);
    err = essieu.AxleMove(-400,25);
    delay(250);
    err = essieu.AxleRotate(90,10);
    delay(250);
    err = essieu.AxleMove(-90,10);

   */
   
}
