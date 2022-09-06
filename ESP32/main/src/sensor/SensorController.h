#ifndef SensorController_h
#define SensorController_h

#include <ArduinoJson.h>
#include "../../pinstruct.h"

class SensorController
{
private:
    /* data */
public:
    SensorController(/* args */);
    ~SensorController();
    bool DEBUG = false;
    DynamicJsonDocument * jsonDocument;
    PINDEF * pins;

    int N_sensor_avg; //no idea if it should be equal to that that one inside PidController.h 

    void setup();
    void act();
    void set();
    void get();
};

SensorController::SensorController(/* args */)
{
}

SensorController::~SensorController()
{
}

SensorController * sensor;


#endif