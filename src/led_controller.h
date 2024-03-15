#ifndef __LEDCONTROLLER
#define __LEDCONTROLLER

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/rmt_tx.h"
#include "led_strip_encoder.h"

enum LevelLamp
{
    Lamp0 = 0,
    Lamp1 = 1,
    Lamp2 = 2,
    Lamp3 = 3
};
enum LevelBrightness
{
    Level_0 = 0,
    Level_1 = 26,
    Level_2 = 51,
    Level_3 = 77,
    Level_4 = 102,
    Level_5 = 128,
    Level_6 = 153,
    Level_7 = 178,
    Level_8 = 204,
    Level_9 = 230,
    Level_10 = 255
};

class LedController
{
private:
    int ledNumbers = 0;
    rmt_channel_handle_t led_chan = NULL;
    rmt_encoder_handle_t led_encoder = NULL;

    void setPixel(int idx, int green, int red, int blue);
    void flushRGB();

public:
    void setBrightness(LevelBrightness brightnessLevel);
    void init(int ledsNumber);
    void direct_lamp(bool is_right, LevelLamp level);
    void turnOffLamp();
};

#endif