#ifndef FocusMotor_h
#define FocusMotor_h

#include "AccelStepper.h"
#include <ArduinoJson.h>

class FocusMotor
{
    public:
        bool DEBUG = false;

        // for stepper.h
        #define MOTOR_STEPS 200
        #define SLEEP 0
        #define MS1 0
        #define MS2 0
        #define MS3 0
        #define RPM 120

        bool isaccel = false;
        bool isforever = false;
        bool motor_enable = false;
        bool isBusy = false;

        // global variables for the motor
        long mspeed0 = 1000;
        long mspeed1 = 1000;
        long mspeed2 = 1000;
        long mspeed3 = 1000;
        long mposition0 = 0;
        long mposition1 = 0;
        long mposition2 = 0;
        long mposition3 = 0;
        boolean isstop = 0;

        long POSITION_MOTOR_A = 0;
        long POSITION_MOTOR_X = 0;
        long POSITION_MOTOR_Y = 0;
        long POSITION_MOTOR_Z = 0;

        int MOTOR_ACCEL = 5000;
        int MOTOR_DECEL = 5000;
        
        int isabs = true;
        int isen = false;
        bool isactive = false;

        // direction
        int SIGN_A = 1;
        int SIGN_X = 1;
        int SIGN_Y = 1;
        int SIGN_Z = 1;
        static const int FULLSTEPS_PER_REV_A = 200;
        static const int FULLSTEPS_PER_REV_X = 200;
        static const int FULLSTEPS_PER_REV_Y = 200;
        static const int FULLSTEPS_PER_REV_Z = 200;

        long MAX_VELOCITY_A = 20000;
        long MAX_VELOCITY_X = 20000;
        long MAX_VELOCITY_Y = 20000;
        long MAX_VELOCITY_Z = 20000;
        long MAX_ACCELERATION_A = 100000;
        long MAX_ACCELERATION_X = 100000;
        long MAX_ACCELERATION_Y = 100000;
        long MAX_ACCELERATION_Z = 100000;

        // Stepper Motor pins
        int STEP_A = 0; // ATTENTION I2C SCL: 22;
        int STEP_X = 2;
        int STEP_Y = 27;
        int STEP_Z = 12;
        int DIR_A = 0; // ATTENTION I2C SDA 21;
        int DIR_X = 33;
        int DIR_Y = 16;
        int DIR_Z = 14;
        int ENABLE = 13;

        AccelStepper stepper_A = AccelStepper(AccelStepper::DRIVER, STEP_A, DIR_A);
        AccelStepper stepper_X = AccelStepper(AccelStepper::DRIVER, STEP_X, DIR_X);
        AccelStepper stepper_Y = AccelStepper(AccelStepper::DRIVER, STEP_Y, DIR_Y);
        AccelStepper stepper_Z = AccelStepper(AccelStepper::DRIVER, STEP_Z, DIR_Z);

        DynamicJsonDocument jsonDocument;

        void motor_act_fct();
        void setEnableMotor(bool enable);
        bool getEnableMotor();
        void motor_set_fct();
        void motor_get_fct();
        void setup_motor();
        bool drive_motor_background();

        #ifdef IS_WIFI
        void motor_act_fct_http();
        void motor_get_fct_http();
        void motor_set_fct_http();
        #endif

};

#endif