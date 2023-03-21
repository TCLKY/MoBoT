#include <Wheelctl.h>
#include <time.h>
#include <Arduino.h>
#include <math.h>

Wheel::Wheel(){


    //set default parameter for wheel object
    this->speed = DEFAULT_SPEED;
    this->step = DEFAULT_STEP;
    this->steps_per_mil = DEFAULT_STEP_PER_MIL;
    this->wheel_radius = DEFAULT_WHEEL_RADIUS;
    this->inversed = DEFAULT_INVERSED_STATE;
    this->dir_pin = DEFAULT_DIR_PIN;
    this->step_pin = DEFAULT_STEP_PIN;

}
Wheel::Wheel(int step_Pin, int dir_Pin){

    this->speed = DEFAULT_SPEED;
    this->step = DEFAULT_STEP;
    this->steps_per_mil = DEFAULT_STEP_PER_MIL;
    this->wheel_radius = DEFAULT_WHEEL_RADIUS;
    this->inversed = DEFAULT_INVERSED_STATE;
    this->dir_pin = dir_Pin;
    this->step_pin = step_Pin;
}

void Wheel::MoveWheelByStep(int step, bool turn, float custom_speed){
    this->speed = custom_speed;
    int pulse = (this->speed * this->step * PI)/(30*this->wheel_radius);  
    (this->inversed && !turn) ? digitalWrite(this->dir_pin, HIGH) : digitalWrite(this->dir_pin, LOW);
    
    int i = 0;
    for(i=0;i< this->step;i++){

        digitalWrite(this->step_pin,HIGH);
        delayMicroseconds(STEP_UP_MICRO);
        digitalWrite(this->step_pin, LOW);
        delay(pulse);
    }

}
void Wheel::MoveWheelByRotation(int rotation, bool turn, float custom_speed){

    this->speed = custom_speed;
}
void Wheel::MoveWheelByDistance(int distance, bool side, float custom_speed){

    this->speed = custom_speed;
}