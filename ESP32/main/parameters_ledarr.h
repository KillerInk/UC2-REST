#include <Adafruit_NeoPixel.h>
#include <Adafruit_NeoMatrix.h>

int LED_COUNT = 64; // this is the maximum number of LEDs per matrix 

int NLED4x4=16;
int NLED8x8=64;

int LED_PATTERN_DPC_TOP_8x8 [] = {1,1,1,1,1,1,1,1,
                                  1,1,1,1,1,1,1,1,
                                  1,1,1,1,1,1,1,1,
                                  1,1,1,1,1,1,1,1,      
                                  0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0};

int LED_PATTERN_DPC_LEFT_8x8 []= {1,1,1,1,0,0,0,0,
                                  0,0,0,0,1,1,1,1,
                                  1,1,1,1,0,0,0,0,
                                  0,0,0,0,1,1,1,1,
                                  1,1,1,1,0,0,0,0,
                                  0,0,0,0,1,1,1,1,
                                  1,1,1,1,0,0,0,0,
                                  0,0,0,0,1,1,1,1};
                                  
int LED_PATTERN_DPC_TOP_4x4 []=   {1,1,1,1,
                                   1,1,1,1,
                                   0,0,0,0,
                                   0,0,0,0};

int LED_PATTERN_DPC_LEFT_4x4 []=  {1,1,0,0,
                                   0,0,1,1,
                                   1,1,0,0,
                                   0,0,1,1};
