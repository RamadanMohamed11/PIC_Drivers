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
Std_ReturnType rgb_led_turn_on(const rgb_led_t* RGB_LED, rgb_color_t color)
{
    Std_ReturnType state=E_OK;
    if(RGB_LED==NULL)
    {
        state=E_NOT_OK;
    }
    else
    {
        pin_config_t red={.port=RGB_LED->red_channel.port,.pin=RGB_LED->red_channel.pin,.direction=GPIO_OUTPUT,.logic=RGB_LED->state};
        pin_config_t green={.port=RGB_LED->green_channel.port,.pin=RGB_LED->green_channel.pin,.direction=GPIO_OUTPUT,.logic=RGB_LED->state};
        pin_config_t blue={.port=RGB_LED->blue_channel.port,.pin=RGB_LED->blue_channel.pin,.direction=GPIO_OUTPUT,.logic=RGB_LED->state};

        switch(color)
        {
            case RED:
                gpio_pin_write_logic(&red, GPIO_HIGH);
                gpio_pin_write_logic(&green,GPIO_LOW);
                gpio_pin_write_logic(&blue,GPIO_LOW);
                break;
            case GREEN:
                gpio_pin_write_logic(&green,GPIO_HIGH);
                gpio_pin_write_logic(&red,GPIO_LOW);
                gpio_pin_write_logic(&blue,GPIO_LOW);
                break;
            case BLUE:
                gpio_pin_write_logic(&blue,GPIO_HIGH);
                gpio_pin_write_logic(&red,GPIO_LOW);
                gpio_pin_write_logic(&green,GPIO_LOW);
                break;
            case YELLOW:
                gpio_pin_write_logic(&red,GPIO_HIGH);
                gpio_pin_write_logic(&green,GPIO_HIGH);
                gpio_pin_write_logic(&blue,GPIO_LOW);
                break;
            case ORANGE:
                gpio_pin_write_logic(&red,GPIO_HIGH);
                gpio_pin_write_logic(&green,GPIO_HIGH);
                gpio_pin_write_logic(&blue,GPIO_LOW);
                break;
            case PURPLE:
                gpio_pin_write_logic(&red,GPIO_HIGH);
                gpio_pin_write_logic(&blue,GPIO_HIGH);
                gpio_pin_write_logic(&green,GPIO_LOW);
                break;
            case WHITE:
                gpio_pin_write_logic(&red,GPIO_HIGH);
                gpio_pin_write_logic(&green,GPIO_HIGH);
                gpio_pin_write_logic(&blue,GPIO_HIGH);
                break;
            default:
                break;
        }
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
        pin_config_t red={.port=RGB_LED->red_channel.port,.pin=RGB_LED->red_channel.pin,.direction=GPIO_OUTPUT,.logic=RGB_LED->state};
        pin_config_t green={.port=RGB_LED->green_channel.port,.pin=RGB_LED->green_channel.pin,.direction=GPIO_OUTPUT,.logic=RGB_LED->state};
        pin_config_t blue={.port=RGB_LED->blue_channel.port,.pin=RGB_LED->blue_channel.pin,.direction=GPIO_OUTPUT,.logic=RGB_LED->state};
        gpio_pin_write_logic(&red,GPIO_LOW);
        gpio_pin_write_logic(&green,GPIO_LOW);
        gpio_pin_write_logic(&blue,GPIO_LOW); 
    }
    return state;
}