#include "../../config.h"
#if defined IS_DAC || defined IS_DAC_FAKE
#ifndef DacController_h
#define DacController_h

#include <ArduinoJson.h>
#include "DAC_Module.h"
#include "../../pinstruct.h"



class DacController
{
    private:
    #ifdef IS_DAC
    DAC_Module * dacm;
    #endif
    
    public:
    DacController();
    ~DacController();
    bool DEBUG = false;
    DynamicJsonDocument * jsonDocument;
    PINDEF * pins;

    // DAC-specific parameters
    dac_channel_t dac_channel = DAC_CHANNEL_1;

    uint32_t clk_div = 0;
    uint32_t scale = 0;
    uint32_t invert = 2;
    uint32_t phase = 0;

    uint32_t frequency = 1000;

    boolean dac_is_running = false;

    void setup();

    void act();
    void set();
    void get();
    static void drive_galvo(void * parameter);

   
};
static DacController dac;
#endif
#endif