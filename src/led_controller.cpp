#include "led_controller.h"

#define RMT_LED_STRIP_RESOLUTION_HZ 10000000
#define RMT_LED_STRIP
// #define RMT_LED_STRIP GPIO_NUM_2
#define EXAMPLE_LED_NUMBERS 24

static uint8_t led_strip_pixels[EXAMPLE_LED_NUMBERS * 3];
void LedController::setPixel(int idx, int green, int red, int blue)
{
    led_strip_pixels[idx * 3 + 0] = green;
    led_strip_pixels[idx * 3 + 1] = red;
    led_strip_pixels[idx * 3 + 2] = blue;
}

void LedController::flushRGB()
{
    rmt_transmit_config_t tx_config = {
        .loop_count = 0,
    };
    ESP_ERROR_CHECK(rmt_transmit(led_chan, led_encoder, led_strip_pixels, sizeof(led_strip_pixels), &tx_config));
    ESP_ERROR_CHECK(rmt_tx_wait_all_done(led_chan, portMAX_DELAY));
}


void LedController::setBrightness(LevelBrightness brightnessLevel)
{
    uint32_t brightness = brightnessLevel;
    for (int i = 0; i < ledNumbers; i++)
    {
        int red = led_strip_pixels[i * 3 + 1];
        int green = led_strip_pixels[i * 3];
        int blue = led_strip_pixels[i * 3 + 2];

        if (red > 0)
        {
            red = brightness;
        }
        else
        {
            red = 0;
        }
        if (green > 0)
        {
            green = brightness;
        }
        else
        {
            green = 0;
        }
        if (blue > 0)
        {
            blue = brightness;
        }
        else
        {
            blue = 0;
        }

        setPixel(i, green, red, blue);
    }
    flushRGB();
}



void LedController::init(int ledsNumber, gpio_num_t pin)
{
    this->ledNumbers = ledsNumber;
    this->pin = pin;
    led_chan = NULL;

    rmt_tx_channel_config_t tx_chan_config = {
        .gpio_num = this -> pin,
        .clk_src = RMT_CLK_SRC_DEFAULT,
        .resolution_hz = RMT_LED_STRIP_RESOLUTION_HZ,
        .mem_block_symbols = 64,
        .trans_queue_depth = 4,
        .flags = 0,
    };

    ESP_ERROR_CHECK(rmt_new_tx_channel(&tx_chan_config, &led_chan));
    led_encoder = NULL;
    
    led_strip_encoder_config_t encoder_config = {
        .resolution = RMT_LED_STRIP_RESOLUTION_HZ,
    };
    ESP_ERROR_CHECK(rmt_new_led_strip_encoder(&encoder_config, &led_encoder));
    ESP_ERROR_CHECK(rmt_enable(led_chan));
}

void LedController::direct_lamp(bool is_right, LevelLamp level)
{
    LevelBrightness brightness = Level_1;
    uint32_t red = 0;
    uint32_t green = 0;
    uint32_t blue = 0;
    int lamp_length = ledNumbers / 2;
    int section = lamp_length / 3;

    for (int i = 0; i < ledNumbers; i++)
    {
        red = 0;
        green = 0;
        blue = 0;
        setPixel(i, green, red, blue);
    }
    if (is_right)
    {
        switch (level)
        {
        case 3:
            for (int j = 0; j < section; j++)
            {
                red = brightness;
                green = 0;
                blue = 0;
                setPixel(j, green, red, blue);
            }
            [[fallthrough]];
        case 2:
            for (int j = section; j < 2 * section; j++)
            {
                red = brightness;
                green = brightness;
                blue = 0;
                setPixel(j, green, red, blue);
            }
            [[fallthrough]];
        case 1:
            for (int j = 2 * section; j < ledNumbers / 2; j++)
            {
                red = 0;
                green = brightness;
                blue = 0;
                setPixel(j, green, red, blue);
            }
            break;
        case 0:
            break;
        }
    }
    else
    {
        switch (level)
        {
        case 3:
            for (int j = ledNumbers / 2 + 2 * section; j < ledNumbers; j++)
            {
                red = brightness;
                green = 0;
                blue = 0;
                setPixel(j, green, red, blue);
            }
            [[fallthrough]];
        case 2:
            for (int j = ledNumbers / 2 + section; j < ledNumbers / 2 + 2 * section; j++)
            {
                red = brightness;
                green = brightness;
                blue = 0;
                setPixel(j, green, red, blue);
            }
            [[fallthrough]];
        case 1:
            for (int j = ledNumbers / 2; j < ledNumbers / 2 + section; j++)
            {
                red = 0;
                green = brightness;
                blue = 0;
                setPixel(j, green, red, blue);
            }
            break;
        case 0:
            break;
        }
    }
    flushRGB();
}

void LedController::turnOffLamp()
{
    uint32_t red = 0;
    uint32_t green = 0;
    uint32_t blue = 0;

    for (int i = 0; i < ledNumbers; i++)
    {
        red = 0;
        green = 0;
        blue = 0;
        setPixel(i, green, red, blue);
    }
    flushRGB();
}