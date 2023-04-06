#include <Arduino.h>
#include <time.h>
#include <SoftwareSerial.h>
#include <WheelAxle.h>

#define DIR_PIN_R  8
#define DIR_PIN_L  6
#define STEP_PIN_R  7
#define STEP_PIN_L  9
#define STEP 200
#define STEP_UP_MICRO 20

SoftwareSerial btlink(2,10);
WheelAxle essieu(6,7,8,9);
int err = 0;
int i = 0;
    

void setup(){
    pinMode(3,INPUT);
    pinMode(10,OUTPUT);
    btlink.begin(38400);
    pinMode(DIR_PIN_R, OUTPUT);
    pinMode(DIR_PIN_L, OUTPUT);
    pinMode(STEP_PIN_R, OUTPUT);
    pinMode(STEP_PIN_L, OUTPUT);
    digitalWrite(STEP_PIN_R,HIGH);
    delay(1500);
    digitalWrite(STEP_PIN_R,LOW);
    Serial.begin(38400);
    essieu.WheelInvert(WheelAxle::axle_side::LEFT);
    for(i=0;i<10;i++){      
        digitalWrite(LED_BUILTIN,HIGH);
        delay(250);
        digitalWrite(LED_BUILTIN,LOW);
        delay(250);
    }
    Serial.println("hello");
    Serial.println(essieu.GetInverted());
}
void loop(){

    int i = 0;
    char text[32] = {0};
    
    Serial.println("hello");
    //Serial.println(essieu.GetInverted());
    while(Serial.available() == 0){

    }
    if(Serial.available()){

        do{
            text[i++] = Serial.read();
            delay(3);        
            }while(Serial.available() >1);
        i = Serial.read();
        btlink.println(text);
        i=0;
    }
    while(!btlink.available()){

        Serial.println("btlink en attente");
        delay(1000);
        if(i >= 15){
            Serial.println("no response");
            delay(500);
            break;
        }
        i++;
    }
    
    if(btlink.available()){
        i = 0;
        do{
            text[i++] = btlink.read();
            delay(3);
        }while(btlink.available() > 0);

        Serial.print("bt response : ");
        Serial.println(text);
    }
    
    /*
    err = essieu.AxleMove(400,25);
   
    delay(250);
    err = essieu.AxleMove(-400,25);
    delay(250);
    err = essieu.AxleRotate(90,10);
    delay(250);
    err = essieu.AxleRotate(-90,10);
    */
   
   
}
