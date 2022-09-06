#ifndef DigitalController_h
#define DigitalController_h

#include <ArduinoJson.h>
#include "../../pinstruct.h"

class DigitalController
{
private:
    /* data */
public:
    DigitalController(/* args */);
    ~DigitalController();

    bool isBusy;
    bool DEBUG = false;
    PINDEF * pins;

    int digital_val_1 = 0;
    int digital_val_2 = 0;
    int digital_val_3 = 0;

    void act(DynamicJsonDocument * jsonDocument);
    void set(DynamicJsonDocument * jsonDocument);
    void get(DynamicJsonDocument * jsonDocument);
    void setup();
};

DigitalController::DigitalController(/* args */)
{
}

DigitalController::~DigitalController()
{
}

DigitalController * digital;

#endif