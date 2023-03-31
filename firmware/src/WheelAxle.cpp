#include <WheelAxle.h>
#include <time.h>
#include <Arduino.h>
#include <math.h>

WheelAxle::WheelAxle()
{

    // set default parameter for wheel object
    this->speed = DEFAULT_SPEED;
    this->step = DEFAULT_STEP;
    this->steps_per_mil = DEFAULT_STEP_PER_MIL;
    this->wheel_radius = DEFAULT_WHEEL_RADIUS;
    this->inversedR = this->inversedL = DEFAULT_INVERSED_STATE;
    this->train_entraxe = 100;
    this->max_speed = 10;

    this->motorL = new DRIVER(200, 3, 5);
    this->motorR = new DRIVER(200, 2, 8);

    this->Axle = new SyncDriver(*motorL, *motorR);
    this->Axle->begin(60.0f, 16);
}

WheelAxle::WheelAxle(unsigned int stepL, unsigned int stepR)
{

    // set default parameter for wheel object
    this->speed = DEFAULT_SPEED;
    this->step = DEFAULT_STEP;
    this->steps_per_mil = DEFAULT_STEP_PER_MIL;
    this->wheel_radius = DEFAULT_WHEEL_RADIUS;
    this->inversedR = this->inversedL = DEFAULT_INVERSED_STATE;
    this->train_entraxe = 100;
    this->max_speed = 10;

    this->motorL = new DRIVER(200, 3, stepL);
    this->motorR = new DRIVER(200, 2, stepR);

    this->Axle = new SyncDriver(*motorL, *motorR);
    this->Axle->begin(60.0f, 16);
}

int WheelAxle::AxleRotate(float rotation, float custom_speed)
{

    this->speed = custom_speed;
    float rot = rotation * this->train_entraxe / (this->wheel_radius);
    Axle->rotate((double)(this->inversedL * rot), (double)(this->inversedR * (-rot)));
    return 0;
}
int WheelAxle::AxleMove(float distance, float custom_speed)
{

    Axle->move((double)(this->inversedL * distance), (double)(this->inversedR * distance));

    return 0;
}
void WheelAxle::WheelInvert(enum axle_side side)
{

    side ? (this->inversedL > 0 ? this->inversedL = -1 : (this->inversedL = 1)) : (this->inversedR > 0 ? this->inversedR = -1 : (this->inversedR = 1));
}
int WheelAxle::GetInverted(void)
{
    return this->inversedR;
}
enum WheelAxle::axle_state WheelAxle::GetAxleState()
{

    if ((motorL->getCurrentState() == motorR->getCurrentState()) == BasicStepperDriver::State::STOPPED)
    {
        return STOPPED;
    }
    if (motorL->getRPM() == motorR->getRPM())
    {
        return TRANSLATING;
    }
    else if (motorL->getRPM() == (-1) * motorR->getRPM())
    {
        return ROTATING;
    }
    else
    {
        return BOTH;
    }
}