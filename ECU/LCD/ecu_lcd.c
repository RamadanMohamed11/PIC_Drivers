/**
* @file    ecu_LCD.c
* @author  Eng_Ramadan_Mohamed
* @brief   Source file for the LCD driver.
* @version 0.1
* @date    2025-09-24
*/

#include "ecu_lcd.h"

static Std_ReturnType LCD_send_4bits(const lcd_4bit_t *lcd_4bit, uint8 data_or_command);
static Std_ReturnType LCD_send_4bit_enable_signal(const lcd_4bit_t *lcd_4bit);
static Std_ReturnType LCD_convert_number_to_string(int value, uint8 *str);

Std_ReturnType lcd_4bit_initialize(const lcd_4bit_t* lcd_4bit)
{
    Std_ReturnType state = E_OK;
    if(lcd_4bit == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        pin_config_t rs_pin = {.port = lcd_4bit->lcd_rs_pin.port,
                               .pin = lcd_4bit->lcd_rs_pin.pin,
                               .direction = GPIO_OUTPUT,
                               .logic = GPIO_LOW};
        state &= gpio_pin_direction_initialize(&rs_pin);
        pin_config_t en_pin = {.port = lcd_4bit->lcd_en_pin.port,
                               .pin = lcd_4bit->lcd_en_pin.pin,
                               .direction = GPIO_OUTPUT,
                               .logic = GPIO_LOW};
        state &= gpio_pin_direction_initialize(&en_pin);

        for(uint8 local_index=0; local_index<FOUR_DATA_PINS_NUMBER; local_index++)
        {
            pin_config_t data_pin = {.port = lcd_4bit->lcd_data_pins[local_index].port,
                                     .pin = lcd_4bit->lcd_data_pins[local_index].pin,
                                     .direction = GPIO_OUTPUT,
                                     .logic = GPIO_LOW};
            state &= gpio_pin_direction_initialize(&data_pin);
        }

        
    }
}

Std_ReturnType lcd_4bit_send_command(const lcd_4bit_t* lcd_4bit, const uint8 command)
{
    Std_ReturnType state = E_OK;
    if(lcd_4bit == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        
    }
}

Std_ReturnType lcd_4bit_send_char_data(const lcd_4bit_t* lcd_4bit, const uint8 ch)
{
    Std_ReturnType state = E_OK;
    if(lcd_4bit == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        
    }
}

Std_ReturnType lcd_4bit_send_char_at_position(const lcd_4bit_t* lcd_4bit, const uint8 row, const uint8 col, const uint8 ch)
{
    Std_ReturnType state = E_OK;
    if(lcd_4bit == NULL || row > 4 || col > 80)
    {
        state = E_NOT_OK;
    }
    else
    {
        
    }
}

Std_ReturnType lcd_4bit_send_string_data(const lcd_4bit_t* lcd_4bit, const uint8* str)
{
    Std_ReturnType state = E_OK;
    if(lcd_4bit == NULL || str == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        
    }
}

Std_ReturnType lcd_4bit_send_string_at_position(const lcd_4bit_t* lcd_4bit, const uint8 row, const uint8 col, const uint8* str)
{
    Std_ReturnType state = E_OK;
    if(lcd_4bit == NULL || row > 4 || col > 80 || str == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        
    }
}

Std_ReturnType lcd_4bit_send_custome_char(const lcd_4bit_t* lcd_4bit, const uint8 row, const uint8 col, const uint8* str, uint8 mem_pos)
{
    Std_ReturnType state = E_OK;
    if(lcd_4bit == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        
    }
}

Std_ReturnType lcd_4bit_set_position(const lcd_4bit_t* lcd_4bit, const uint8 row, const uint8 col)
{
    Std_ReturnType state = E_OK;
    if(lcd_4bit == NULL || row > 4 || col > 80)
    {
        state = E_NOT_OK;
    }
    else
    {
        
    }
}


Std_ReturnType lcd_8bit_initialize(const lcd_8bit_t* lcd_8bit)
{
    Std_ReturnType state = E_OK;
    if(lcd_8bit == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        
        pin_config_t rs_pin = { .port = lcd_8bit->lcd_rs_pin.port,
                                .pin = lcd_8bit->lcd_rs_pin.pin,
                                .direction = GPIO_OUTPUT,
                                .logic = GPIO_LOW};
        state &= gpio_pin_direction_initialize(&rs_pin);
        pin_config_t en_pin = { .port = lcd_8bit->lcd_en_pin.port,
                                .pin = lcd_8bit->lcd_en_pin.pin,
                                .direction = GPIO_OUTPUT,
                                .logic = GPIO_LOW};
        state &= gpio_pin_direction_initialize(&en_pin);

        for(uint8 local_index=0; local_index<EIGHT_DATA_PINS_NUMBER; local_index++)
        {
            pin_config_t data_pin = { .port = lcd_8bit->lcd_data_pins[local_index].port,
                                      .pin = lcd_8bit->lcd_data_pins[local_index].pin,
                                      .direction = GPIO_OUTPUT,
                                      .logic = GPIO_LOW};
            state &= gpio_pin_direction_initialize(&data_pin);
        }
    }
}

Std_ReturnType lcd_8bit_send_command(const lcd_8bit_t* lcd_8bit, const uint8 command)
{
    Std_ReturnType state = E_OK;
    if(lcd_8bit == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        
    }
}

Std_ReturnType lcd_8bit_send_char_data(const lcd_8bit_t* lcd_8bit, const uint8 ch)
{
    Std_ReturnType state = E_OK;
    if(lcd_8bit == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        
    }
}

Std_ReturnType lcd_8bit_send_char_at_position(const lcd_8bit_t* lcd_8bit, const uint8 row, const uint8 col, const uint8 ch)
{
    Std_ReturnType state = E_OK;
    if(lcd_8bit == NULL || row > 4 || col > 80)
    {
        state = E_NOT_OK;
    }
    else
    {
        
    }
}

Std_ReturnType lcd_8bit_send_string_data(const lcd_8bit_t* lcd_8bit, const uint8* str)
{
    Std_ReturnType state = E_OK;
    if(lcd_8bit == NULL || str == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        
    }
}

Std_ReturnType lcd_8bit_send_string_at_position(const lcd_8bit_t* lcd_8bit, const uint8 row, const uint8 col, const uint8* str)
{
    Std_ReturnType state = E_OK;
    if(lcd_8bit == NULL || row > 4 || col > 80 || str == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        
    }
}

Std_ReturnType lcd_8bit_send_custome_char(const lcd_8bit_t* lcd_8bit, const uint8 row, const uint8 col, const uint8* str, uint8 mem_pos)
{
    Std_ReturnType state = E_OK;
    if(lcd_8bit == NULL || row > 4 || col > 80 || str == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        
    }
}

Std_ReturnType lcd_8bit_set_position(const lcd_8bit_t* lcd_8bit, const uint8 row, const uint8 col)
{
    Std_ReturnType state = E_OK;
    if(lcd_8bit == NULL || row > 4 || col > 80)
    {
        state = E_NOT_OK;
    }
    else
    {
        
    }
}

static Std_ReturnType LCD_send_4bits(const lcd_4bit_t *lcd_4bit, uint8 data_or_command)
{
    Std_ReturnType state = E_OK;
    if(lcd_4bit == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        for(uint8 local_index=0; local_index<FOUR_DATA_PINS_NUMBER; local_index++)
        {
            pin_config_t data_pin = {.port = lcd_4bit->lcd_data_pins[local_index].port,
                                     .pin = lcd_4bit->lcd_data_pins[local_index].pin                        
                                    };
            state &= gpio_pin_write_logic(&data_pin, (data_or_command >> local_index) & 0x01);
        }   
    }
}

static Std_ReturnType LCD_send_4bit_enable_signal(const lcd_4bit_t *lcd_4bit)
{
    Std_ReturnType state = E_OK;
    if(lcd_4bit == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        
    }
}
static Std_ReturnType LCD_convert_number_to_string(int value,uint8 *str)
{
    Std_ReturnType state = E_OK;
    if(str == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        
    }
}