#ifndef Wheelctl_h
#define Wheelctl_h

#define DEFAULT_DIR_PIN 3
#define DEFAULT_STEP_PIN 4
#define DEFAULT_STEP 200
#define STEP_UP_MICRO 20
#define DEFAULT_SPEED 20
#define DEFAULT_STEP_PER_MIL 100
#define DEFAULT_WHEEL_RADIUS 30.0
#define DEFAULT_INVERSED_STATE false

class Wheel{

    public:
        
        Wheel();
        Wheel(int step_Pin, int dir_Pin);

        void MoveWheelByStep(int steps, bool turn, float custom_speed);
        void MoveWheelByRotation(int rotation, bool turn, float custom_speed);
        void MoveWheelByDistance(int distance, bool side, float custom_speed);
    private:

        float wheel_radius;
        int step;
        bool inversed;
        int dir_pin;
        int step_pin;
        float speed;
        float steps_per_mil;
        
        
        

};
#endif