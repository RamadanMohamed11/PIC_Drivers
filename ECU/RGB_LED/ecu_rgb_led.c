#include "ecu_rgb_led.h"

Std_ReturnType rgb_led_initialize(const rgb_led_t* RGB_LED)
{
    Std_ReturnType state=E_OK;
    if(RGB_LED==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        pin_config_t red={.port=RGB_LED->red_channel.port,.pin=RGB_LED->red_channel.pin,.direction=GPIO_OUTPUT,.logic=RGB_LED->state};
        gpio_pin_direction_initialize(&red);
        pin_config_t green={.port=RGB_LED->green_channel.port,.pin=RGB_LED->green_channel.pin,.direction=GPIO_OUTPUT,.logic=RGB_LED->state};
        gpio_pin_direction_initialize(&green);
        pin_config_t blue={.port=RGB_LED->blue_channel.port,.pin=RGB_LED->blue_channel.pin,.direction=GPIO_OUTPUT,.logic=RGB_LED->state};
        gpio_pin_direction_initialize(&blue);
    }
    return state;
}
Std_ReturnType rgb_led_turn_on(const rgb_led_t* RGB_LED)
{
    Std_ReturnType state=E_OK;
    if(RGB_LED==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        
    }
    return state;
}
Std_ReturnType rgb_led_turn_off(const rgb_led_t* RGB_LED)
{
    Std_ReturnType state=E_OK;
    if(RGB_LED==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        
    }
    return state;
}
Std_ReturnType rgb_led_toggle(const rgb_led_t* RGB_LED)
{
    Std_ReturnType state=E_OK;
    if(RGB_LED==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        
    }
    return state;
}