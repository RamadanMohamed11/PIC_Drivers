/**
* @file    ecu_LCD.c
* @author  Eng_Ramadan_Mohamed
* @brief   Source file for the LCD driver.
* @version 0.1
* @date    2025-09-24
*/

#include "ecu_lcd.h"

static Std_ReturnType lcd_send_4bits(const lcd_4bit_t *lcd_4bit, uint8 data_or_command);
static Std_ReturnType lcd_4bit_send_enable_signal(const lcd_4bit_t *lcd_4bit);
static Std_ReturnType lcd_send_8bits(const lcd_8bit_t *lcd_8bit, uint8 data_or_command);
static Std_ReturnType lcd_8bit_send_enable_signal(const lcd_8bit_t *lcd_8bit);
static Std_ReturnType lcd_convert_number_to_string(sint32 value, uint8 *str);
static void reverse_string(uint8 *str, uint8 len);
static Std_ReturnType lcd_send_higher_nibble(const lcd_4bit_t *lcd_4bit, uint8 data);

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
        __delay_ms(20);
        state &= lcd_send_higher_nibble(lcd_4bit, LCD_8BIT_MODE);
        __delay_ms(5);
        state &= lcd_send_higher_nibble(lcd_4bit, LCD_8BIT_MODE);
        __delay_us(150);
        state &= lcd_send_higher_nibble(lcd_4bit, LCD_8BIT_MODE);
        state &= lcd_send_higher_nibble(lcd_4bit, LCD_4BIT_MODE);

        state &= lcd_4bit_send_command(lcd_4bit, LCD_4BIT_MODE);
        state &= lcd_4bit_send_command(lcd_4bit, LCD_CLEAR);
        state &= lcd_4bit_send_command(lcd_4bit, LCD_RETURN_HOME);
        state &= lcd_4bit_send_command(lcd_4bit, LCD_DISPLAY_ON_CURSOR_OFF);
        state &= lcd_4bit_send_command(lcd_4bit, LCD_ENTRY_MODE_INC_SHIFT_OFF);

        // __delay_ms(35);
		// state &= lcd_4bit_send_command(lcd_4bit, LCD_RETURN_HOME);
		// __delay_ms(1);
		// state &= lcd_4bit_send_command(lcd_4bit, LCD_4BIT_MODE);
		// __delay_ms(1);
		// state &= lcd_4bit_send_command(lcd_4bit, LCD_DISPLAY_ON_CURSOR_OFF);
		// __delay_ms(1);
		// state &= lcd_4bit_send_command(lcd_4bit, LCD_ENTRY_MODE_INC_SHIFT_OFF);
		// __delay_ms(1);
		// state &= lcd_4bit_send_command(lcd_4bit, LCD_CLEAR);
		// __delay_ms(2);
		// state &= lcd_4bit_send_command(lcd_4bit,0x80);
    }
    return state;
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
        pin_config_t rs_pin={.port=lcd_4bit->lcd_rs_pin.port,.pin=lcd_4bit->lcd_rs_pin.pin,.direction=GPIO_OUTPUT,.logic=GPIO_LOW};
        state &= gpio_pin_write_logic(&rs_pin,GPIO_LOW);

        state &= lcd_send_4bits(lcd_4bit,command >> FOUR_DATA_PINS_NUMBER);
        state &= lcd_4bit_send_enable_signal(lcd_4bit);
        state &= lcd_send_4bits(lcd_4bit,command);
        state &= lcd_4bit_send_enable_signal(lcd_4bit);
    }
    return state;
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
        pin_config_t rs_pin={.port=lcd_4bit->lcd_rs_pin.port,.pin=lcd_4bit->lcd_rs_pin.pin,.direction=GPIO_OUTPUT,.logic=GPIO_LOW};
        state &= gpio_pin_write_logic(&rs_pin,GPIO_HIGH);

        state &= lcd_send_4bits(lcd_4bit,ch >> FOUR_DATA_PINS_NUMBER);
        state &= lcd_4bit_send_enable_signal(lcd_4bit);
        state &= lcd_send_4bits(lcd_4bit,ch);
        state &= lcd_4bit_send_enable_signal(lcd_4bit);
    }
    return state;
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
        state &= lcd_4bit_set_position(lcd_4bit,row,col);
        state &= lcd_4bit_send_char_data(lcd_4bit,ch);
    }
    return state;
}

Std_ReturnType lcd_4bit_send_string_data(const lcd_4bit_t* lcd_4bit, const char* str)
{
    Std_ReturnType state = E_OK;
    if(lcd_4bit == NULL || str == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        while(*str != '\0')
        {
            state &= lcd_4bit_send_char_data(lcd_4bit, *str);
            str++;
        }
    }
    return state;
}

Std_ReturnType lcd_4bit_send_string_at_position(const lcd_4bit_t* lcd_4bit, const uint8 row, const uint8 col, const char* str)
{
    Std_ReturnType state = E_OK;
    if(lcd_4bit == NULL || row > 4 || col > 80 || str == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        state &= lcd_4bit_set_position(lcd_4bit, row, col);
        state &= lcd_4bit_send_string_data(lcd_4bit, str);
    }
    return state;
}

Std_ReturnType lcd_4bit_send_custome_char(const lcd_4bit_t* lcd_4bit, const uint8 row, const uint8 col, const char* str, uint8 mem_pos)
{
    Std_ReturnType state = E_OK;
    if(lcd_4bit == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        state &= lcd_4bit_send_command(lcd_4bit, LCD_CGRAM_START + (mem_pos * 8));
        for(uint8 local_index=0; local_index<8; local_index++)
        {
            state &= lcd_4bit_send_char_data(lcd_4bit, str[local_index]);
        }
        state &= lcd_4bit_send_char_at_position(lcd_4bit, row, col, mem_pos);
    }
    return state;
}

Std_ReturnType lcd_4bit_set_position(const lcd_4bit_t* lcd_4bit, uint8 row, uint8 col)
{
    Std_ReturnType state = E_OK;
    if(lcd_4bit == NULL || row > 4 || col > 80)
    {
        state = E_NOT_OK;
    }
    else
    {
        col--;
        switch(row)
        {
            case ROW1:
                state &= lcd_4bit_send_command(lcd_4bit, (ROW1_BEGIN + col));
                break;
            case ROW2:
                state &= lcd_4bit_send_command(lcd_4bit, (ROW2_BEGIN + col));
                break;
            case ROW3:
                state &= lcd_4bit_send_command(lcd_4bit, (ROW3_BEGIN + col));
                break;
            case ROW4:
                state &= lcd_4bit_send_command(lcd_4bit, (ROW4_BEGIN + col));
                break;
        }
    }
    return state;
}

Std_ReturnType lcd_4bit_send_number_data(const lcd_4bit_t* lcd_4bit, sint32 value)
{
    Std_ReturnType state = E_OK;
    if(lcd_4bit == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
         uint8 str[12] = {0};
         state &= lcd_convert_number_to_string(value, str);
         state &= lcd_4bit_send_string_data(lcd_4bit, str);
    }
    return state;
}

Std_ReturnType lcd_4bit_send_number_at_position(const lcd_4bit_t* lcd_4bit, const uint8 row, const uint8 col, sint32 value)
{
    Std_ReturnType state = E_OK;
    if(lcd_4bit == NULL || row > 4 || col > 80)
    {
        state = E_NOT_OK;
    }
    else
    {
         uint8 str[12] = {0};
         state &= lcd_convert_number_to_string(value, str);
         state &= lcd_4bit_send_string_at_position(lcd_4bit, row, col, str);
        
    }
    return state;
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
        __delay_ms(20);
        state &= lcd_8bit_send_command(lcd_8bit, LCD_8BIT_MODE);
        __delay_ms(5);
        state &= lcd_8bit_send_command(lcd_8bit, LCD_8BIT_MODE);
        __delay_us(150);
        state &= lcd_8bit_send_command(lcd_8bit, LCD_8BIT_MODE);

        state &= lcd_8bit_send_command(lcd_8bit, LCD_CLEAR);
        state &= lcd_8bit_send_command(lcd_8bit, LCD_RETURN_HOME);
        state &= lcd_8bit_send_command(lcd_8bit, LCD_DISPLAY_ON_CURSOR_OFF);
        state &= lcd_8bit_send_command(lcd_8bit, LCD_ENTRY_MODE_INC_SHIFT_OFF);
    }
    return state;
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
        pin_config_t rs_pin={.port=lcd_8bit->lcd_rs_pin.port,.pin=lcd_8bit->lcd_rs_pin.pin,.direction=GPIO_OUTPUT,.logic=GPIO_LOW};
        state &= gpio_pin_write_logic(&rs_pin,GPIO_LOW);

        state &= lcd_send_8bits(lcd_8bit,command);
        state &= lcd_8bit_send_enable_signal(lcd_8bit);
    }
    return state;
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
        pin_config_t rs_pin={.port=lcd_8bit->lcd_rs_pin.port,.pin=lcd_8bit->lcd_rs_pin.pin,.direction=GPIO_OUTPUT,.logic=GPIO_LOW};
        state &= gpio_pin_write_logic(&rs_pin,GPIO_HIGH);

        state &= lcd_send_8bits(lcd_8bit,ch);
        state &= lcd_8bit_send_enable_signal(lcd_8bit);
    }
    return state;
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
        state &= lcd_8bit_set_position(lcd_8bit,row,col);
        state &= lcd_8bit_send_char_data(lcd_8bit,ch);
    }
    return state;
}

Std_ReturnType lcd_8bit_send_string_data(const lcd_8bit_t* lcd_8bit, const char* str)
{
    Std_ReturnType state = E_OK;
    if(lcd_8bit == NULL || str == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        while(*str != '\0')
        {
            state &= lcd_8bit_send_char_data(lcd_8bit, *str);
            str++;
        }
    }
    return state;
}

Std_ReturnType lcd_8bit_send_string_at_position(const lcd_8bit_t* lcd_8bit, const uint8 row, const uint8 col, const char* str)
{
    Std_ReturnType state = E_OK;
    if(lcd_8bit == NULL || row > 4 || col > 80 || str == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        state &= lcd_8bit_set_position(lcd_8bit, row, col);
        state &= lcd_8bit_send_string_data(lcd_8bit, str);
    }
    return state;
}

Std_ReturnType lcd_8bit_send_custome_char(const lcd_8bit_t* lcd_8bit, const uint8 row, const uint8 col, const char* str, uint8 mem_pos)
{
    Std_ReturnType state = E_OK;
    if(lcd_8bit == NULL || row > 4 || col > 80 || str == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        state &= lcd_8bit_send_command(lcd_8bit, LCD_CGRAM_START + (mem_pos * 8));
        for(uint8 local_index=0; local_index<8; local_index++)
        {
            state &= lcd_8bit_send_char_data(lcd_8bit, str[local_index]);
        }
        state &= lcd_8bit_send_char_at_position(lcd_8bit, row, col, mem_pos);
    }
    return state;
}

Std_ReturnType lcd_8bit_set_position(const lcd_8bit_t* lcd_8bit, uint8 row, uint8 col)
{
    Std_ReturnType state = E_OK;
    if(lcd_8bit == NULL || row > 4 || col > 80)
    {
        state = E_NOT_OK;
    }
    else
    {
        col--;
        switch(row)
        {
            case ROW1:
                state &= lcd_8bit_send_command(lcd_8bit, (ROW1_BEGIN + col));
                break;
            case ROW2:
                state &= lcd_8bit_send_command(lcd_8bit, (ROW2_BEGIN + col));
                break;
            case ROW3:
                state &= lcd_8bit_send_command(lcd_8bit, (ROW3_BEGIN + col));
                break;
            case ROW4:
                state &= lcd_8bit_send_command(lcd_8bit, (ROW4_BEGIN + col));
                break;
        }
    }
    return state;
}

Std_ReturnType lcd_8bit_send_number_data(const lcd_8bit_t* lcd_8bit, sint32 value)
{
    Std_ReturnType state = E_OK;
    if(lcd_8bit == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
         uint8 str[12] = {0};
         state &= lcd_convert_number_to_string(value, str);
         state &= lcd_8bit_send_string_data(lcd_8bit, str);
    }
    return state;
}

Std_ReturnType lcd_8bit_send_number_at_position(const lcd_8bit_t* lcd_8bit, const uint8 row, const uint8 col, sint32 value)
{
    Std_ReturnType state = E_OK;
    if(lcd_8bit == NULL || row > 4 || col > 80)
    {
        state = E_NOT_OK;
    }
    else
    {
        uint8 str[12] = {0};
        state &= lcd_convert_number_to_string(value, str);
        state &= lcd_8bit_send_string_at_position(lcd_8bit, row, col, str);
    }
    return state;
}

static Std_ReturnType lcd_send_higher_nibble(const lcd_4bit_t* lcd_4bit, uint8 data)
{
    Std_ReturnType state = E_OK;
    if(lcd_4bit == NULL) return E_NOT_OK;

    pin_config_t rs_pin = {
        .port = lcd_4bit->lcd_rs_pin.port,
        .pin  = lcd_4bit->lcd_rs_pin.pin,
        .direction = GPIO_OUTPUT,
        .logic = GPIO_LOW
    };
    gpio_pin_write_logic(&rs_pin, GPIO_LOW);

    state &= lcd_send_4bits(lcd_4bit, data >> FOUR_DATA_PINS_NUMBER);
    state &= lcd_4bit_send_enable_signal(lcd_4bit);
    return state;
}


static Std_ReturnType lcd_send_4bits(const lcd_4bit_t *lcd_4bit, uint8 data_or_command)
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
                                     .pin = lcd_4bit->lcd_data_pins[local_index].pin};
            state &= gpio_pin_write_logic(&data_pin, (data_or_command >> local_index) & 0x01);
        }   
    }
    return state;
}

static Std_ReturnType lcd_4bit_send_enable_signal(const lcd_4bit_t *lcd_4bit)
{
    Std_ReturnType state = E_OK;
    if(lcd_4bit == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        pin_config_t en_pin={.port=lcd_4bit->lcd_en_pin.port,.pin=lcd_4bit->lcd_en_pin.pin,.direction=GPIO_OUTPUT,.logic=GPIO_LOW};
        state &= gpio_pin_write_logic(&en_pin,GPIO_HIGH);
        __delay_ms(1);
        state &= gpio_pin_write_logic(&en_pin,GPIO_LOW);
        __delay_us(100);
    }
    return state;
}

static Std_ReturnType lcd_convert_number_to_string(sint32 value, uint8 *str)
{
    Std_ReturnType state = E_OK;
    if (str == NULL) {
        state = E_NOT_OK;
    } else {
        uint8 local_index = 0;
        uint8 is_negative = 0;
        uint32 temp_val;

        if (value < 0) {
            is_negative = 1;
            temp_val = -value;
        } else {
            temp_val = value;
        }

        if (temp_val == 0) {
            str[local_index++] = '0';
        } else {
            while (temp_val > 0) {
                str[local_index++] = (temp_val % 10) + '0';
                temp_val /= 10;
            }
        }

        if (is_negative) {
            str[local_index++] = '-';
        }

        reverse_string(str, local_index);
        str[local_index] = '\0';
    }
    return state;
}

static void reverse_string(uint8 *str, uint8 len)
{
    uint8 i = 0, j = len - 1, temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// static Std_ReturnType lcd_convert_number_to_string(int value, sint16 *str)
// {
//     Std_ReturnType state = E_OK;
//     if(str == NULL)
//     {
//         state = E_NOT_OK;
//     }
//     else
//     {
//     }
//     return state;
// }

// static Std_ReturnType lcd_convert_number_to_string(int value, sint32 *str)
// {
//     Std_ReturnType state = E_OK;
//     if(str == NULL)
//     {
//         state = E_NOT_OK;
//     }
//     else
//     {
        
//     }
//     return state;
// }

static Std_ReturnType lcd_send_8bits(const lcd_8bit_t *lcd_8bit, uint8 data_or_command)
{
    Std_ReturnType state = E_OK;
    if(lcd_8bit == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        for(uint8 local_index=0; local_index<EIGHT_DATA_PINS_NUMBER; local_index++)
        {
            pin_config_t data_pin = {.port = lcd_8bit->lcd_data_pins[local_index].port,
                                     .pin = lcd_8bit->lcd_data_pins[local_index].pin};
            state &= gpio_pin_write_logic(&data_pin, (data_or_command >> local_index) & 0x01);
        }   
    }
    return state;
}

static Std_ReturnType lcd_8bit_send_enable_signal(const lcd_8bit_t *lcd_8bit)
{
    Std_ReturnType state = E_OK;
    if(lcd_8bit == NULL)
    {
        state = E_NOT_OK;
    }
    else
    {
        pin_config_t en_pin={.port=lcd_8bit->lcd_en_pin.port,.pin=lcd_8bit->lcd_en_pin.pin,.direction=GPIO_OUTPUT,.logic=GPIO_LOW};
        state &= gpio_pin_write_logic(&en_pin,GPIO_HIGH);
        __delay_ms(1);
        state &= gpio_pin_write_logic(&en_pin,GPIO_LOW);
        __delay_us(100);
    }
    return state;
}