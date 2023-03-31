

#ifndef Wheelctl_h
#define Wheelctl_h




#ifndef AXLE_DRIVER
#define AXLE_DRIVER 2
#endif

#if AXLE_DRIVER == 1
    #include "A4988.h"
    #define DRIVER A4988
#elif AXLE_DRIVER == 2
    #include"DRV8825.h"
    #define DRIVER DRV8825
#elif AXLE_DRIVER == 3
    #include"DRV8834.h"
    #define DRIVER DRV8834
#elif AXLE_DRIVER == 4
    #include"DRV8880.h"
    #define DRIVER DRV8880
#endif

#include "SyncDriver.h"


/*define the driver used to build the robot axle.

add manually the required driver lib for your project.


WheelAxle use cylindrical coordinate system as instructions.
*/

#define DEFAULT_DIR_PIN 3
#define DEFAULT_STEP_PIN 4
#define DEFAULT_STEP 200
#define DEFAULT_SPEED 10
#define DEFAULT_STEP_PER_MIL 100
#define DEFAULT_WHEEL_RADIUS 22.1
#define DEFAULT_INVERSED_STATE 1
#define DEFAULT_MAX_WHEEL_SPEED 70

class WheelAxle{

    public:

        WheelAxle();
        WheelAxle(unsigned int stepL,unsigned int stepRS);

        enum axle_side {RIGHT , LEFT};
        enum axle_state{STOPPED,TRANSLATING,ROTATING,BOTH};


        int AxleRotate(float rotation, float custom_speed);
        int AxleMove(float distance, float custom_speed);
        int GetInverted(void);
        void WheelInvert(enum axle_side side);
        enum axle_state GetAxleState();
    private:

        float wheel_radius;
        int step;
        int inversedR;
        int inversedL;
        float speed;
        float train_entraxe;
        float steps_per_mil;
        float max_speed;
        
        DRIVER* motorL;
        DRIVER* motorR;      
          
        
        SyncDriver* Axle;
        

};
#endif