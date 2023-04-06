#include <WheelAxle.h>
#include <time.h>
#include <Arduino.h>
#include <math.h>

WheelAxle::WheelAxle()
:motorL(200,6,7,3,4,5),motorR(200,8,9,3,4,5),Axle(motorL,motorR)
{

    // set default parameter for wheel object
    this->speed = DEFAULT_SPEED;
    this->step = DEFAULT_STEP;
    this->steps_per_mil = DEFAULT_STEP_PER_MIL;
    this->wheel_radius = DEFAULT_WHEEL_RADIUS;
    this->inversedR = this->inversedL = DEFAULT_INVERSED_STATE;
    this->train_entraxe = 141;
    this->max_speed = 10;

   
    
}

WheelAxle::WheelAxle(short dirL, short stepL, short dirR, short stepR)
:motorL(200,dirL,stepL,3,4,5),motorR(200,dirR,stepR,3,4,5),Axle(motorL,motorR)
{

    // set default parameter for wheel object
    this->speed = DEFAULT_SPEED;
    this->step = DEFAULT_STEP;
    this->steps_per_mil = DEFAULT_STEP_PER_MIL;
    this->wheel_radius = DEFAULT_WHEEL_RADIUS;
    this->inversedR = this->inversedL = DEFAULT_INVERSED_STATE;
    this->train_entraxe = 100;
    this->max_speed = 10;

    
    
}

int WheelAxle::AxleRotate(float rotation, float custom_speed)
{
    Axle.begin(custom_speed,16);
    this->speed = custom_speed;
    float rot = rotation * this->train_entraxe / (this->wheel_radius);
    Axle.rotate(this->inversedL * rot, this->inversedR * (-rot));
    return 0;
}
int WheelAxle::AxleMove(float distance, float custom_speed)
{
    long steps = 200*distance/(TWO_PI * this->wheel_radius);
    Serial.println("start moving");
    Serial.println(steps);
    Axle.begin(custom_speed,16);
    Axle.move(this->inversedL * steps*16, this->inversedR * steps*16);

    return 0;
}
void WheelAxle::WheelInvert(enum axle_side side)
{

    side ? (this->inversedL > 0 ? this->inversedL = -1 : (this->inversedL = 1)) : (this->inversedR > 0 ? this->inversedR = -1 : (this->inversedR = 1));
    
}
int WheelAxle::GetInverted()
{
    return this->inversedR;
}
enum WheelAxle::axle_state WheelAxle::GetAxleState()
{

    if ((motorL.getCurrentState() == motorR.getCurrentState()) == BasicStepperDriver::State::STOPPED)
    {
        return STOPPED;
    }
    if (motorL.getRPM() == motorR.getRPM())
    {
        return TRANSLATING;
    }
    else if (motorL.getRPM() == (-1) * motorR.getRPM())
    {
        return ROTATING;
    }
    else
    {
        return BOTH;
    }
}