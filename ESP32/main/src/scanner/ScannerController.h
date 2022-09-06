#ifndef ScannerController_h
#define ScannerController_h

#include <ArduinoJson.h>
#include "../../pinstruct.h"

class ScannerController
{
private:
    PINDEF * pins;
    /* data */
public:
    ScannerController(PINDEF * pins);
    ~ScannerController();

    bool DEBUG = false;


    bool isScanRunning = false;
    int  scannerPinX = 25;
    int  scannerPinY = 26;
    int  scannerPinLaser = 4;

    int  scannerXFrameMax= 5;
    int  scannerXFrameMin= 0;
    int  scannerYFrameMax= 5;
    int  scannerYFrameMin= 0;
    int scannerXStep = 5;
    int scannerYStep = 5;

    int  scannerxMin = 0;
    int  scanneryMin = 0;
    int  scannerxMax = 255;
    int  scanneryMax = 255;
    int  scannertDelay = 0;
    int  scannerEnable = 0;
    int  scannerExposure = 0;
    int  scannerLaserVal = 255;
    int scannerDelay = 0;

int scannernFrames = 1;

    void act(DynamicJsonDocument * jsonDocument);
    void get(DynamicJsonDocument * jsonDocument);
    void set(DynamicJsonDocument * jsonDocument);
    void setup();
    void background();
};

ScannerController *scanner;

ScannerController::ScannerController(PINDEF * p)
{
    pins = p;
}

ScannerController::~ScannerController()
{
    pins = nullptr;
}


#endif