// #include <iostream>
// #include <string.h>
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "driver/rmt_tx.h"
// #include "driver/gpio.h"
// #include "led_strip_encoder.h"

#include "led_controller.h"

extern "C" void app_main();

void app_main()
{
    LedController ledController1;
    ledController1.init(24);
    // ledController1.direct_lamp(true, 3);
    ledController1.direct_lamp(true, Lamp1);
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    ledController1.direct_lamp(true, Lamp2);
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    ledController1.direct_lamp(true, Lamp3);
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    ledController1.direct_lamp(false, Lamp3);
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    ledController1.direct_lamp(false, Lamp2);
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    ledController1.direct_lamp(false, Lamp0);
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    ledController1.direct_lamp(false, Lamp1);
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    ledController1.setBrightness(Level_2);
}
