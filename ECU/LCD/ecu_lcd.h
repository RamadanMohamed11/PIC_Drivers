/**
* @file    ecu_LCD.h
* @author  Eng_Ramadan_Mohamed
* @brief   Header file for the LCD driver.
* @version 0.1
* @date    2025-09-24
*/

#ifndef ECU_LCD_H
#define	ECU_LCD_H

#include "../../MCAL/GPIO/hal_gpio.h"

#define ROW1 1
#define ROW2 2
#define ROW3 3
#define ROW4 4
#define FOUR_DATA_PINS_NUMBER 4
#define EIGHT_DATA_PINS_NUMBER 8

#define LCD_CLEAR 						0x01
#define LCD_RETURN_HOME 				0x02
#define LCD_ENTRY_MODE_DEC_SHIFT_OFF 	0x04
#define LCD_ENTRY_MODE_DEC_SHIFT_ON 	0x05
#define LCD_ENTRY_MODE_INC_SHIFT_OFF	0x06
#define LCD_ENTRY_MODE_INC_SHIFT_ON		0x07

#define LCD_DISPLAY_OFF_CURSOR_OFF		0x08
#define LCD_DISPLAY_ON_CURSOR_OFF		0x0c
#define LCD_DISPLAY_ON_UNDERLINE_CURSOR	0x0e
#define LCD_DISPLAY_ON_CURSOR_ON		0x0d

#define LCD_CURSOR_MOVE_SHIFT_LEFT		0x10
#define LCD_CURSOR_MOVE_SHIFT_RIGHT		0x14
#define LCD_DISPLAY_SHIFT_LEFT			0x18
#define LCD_DISPLAY_SHIFT_RIGHT			0x1c

#define LCD_8BIT_MODE					0x38
#define LCD_4BIT_MODE					0x28

#define LCD_CGRAM_START					0x40
#define LCD_DDRAM_START					0x80

typedef struct
{
    uint8 port:3;
    uint8 pin:3;
}lcd_pin_t;

typedef struct
{
    lcd_pin_t lcd_rs_pin;
    lcd_pin_t lcd_en_pin;
    lcd_pin_t lcd_data_pins[FOUR_DATA_PINS_NUMBER]
}lcd_4bit_t;

typedef struct
{
    lcd_pin_t lcd_rs_pin;
    lcd_pin_t lcd_en_pin;
    lcd_pin_t lcd_data_pins[EIGHT_DATA_PINS_NUMBER]
}lcd_8bit_t;

Std_ReturnType lcd_4bit_initialize(const lcd_4bit_t* lcd_4bit);
Std_ReturnType lcd_4bit_send_command(const lcd_4bit_t* lcd_4bit, const uint8 command);
Std_ReturnType lcd_4bit_send_char_data(const lcd_4bit_t* lcd_4bit, const uint8 ch);
Std_ReturnType lcd_4bit_send_char_at_position(const lcd_4bit_t* lcd_4bit, const uint8 row, const uint8 col, const uint8 ch);
Std_ReturnType lcd_4bit_send_string_data(const lcd_4bit_t* lcd_4bit, const uint8* str);
Std_ReturnType lcd_4bit_send_string_at_position(const lcd_4bit_t* lcd_4bit, const uint8 row, const uint8 col, const uint8* str);
Std_ReturnType lcd_4bit_send_custome_char(const lcd_4bit_t* lcd_4bit, const uint8 row, const uint8 col, const uint8* str, uint8 mem_pos);
Std_ReturnType lcd_4bit_set_position(const lcd_4bit_t* lcd_4bit, const uint8 row, const uint8 col);


Std_ReturnType lcd_8bit_initialize(const lcd_8bit_t* lcd_8bit);
Std_ReturnType lcd_8bit_send_command(const lcd_8bit_t* lcd_8bit, const uint8 command);
Std_ReturnType lcd_8bit_send_char_data(const lcd_8bit_t* lcd_8bit, const uint8 ch);
Std_ReturnType lcd_8bit_send_char_at_position(const lcd_8bit_t* lcd_8bit, const uint8 row, const uint8 col, const uint8 ch);
Std_ReturnType lcd_8bit_send_string_data(const lcd_8bit_t* lcd_8bit, const uint8* str);
Std_ReturnType lcd_8bit_send_string_at_position(const lcd_8bit_t* lcd_8bit, const uint8 row, const uint8 col, const uint8* ch);
Std_ReturnType lcd_8bit_send_custome_char(const lcd_8bit_t* lcd_8bit, const uint8 row, const uint8 col, const uint8* str, uint8 mem_pos);
Std_ReturnType lcd_8bit_set_position(const lcd_8bit_t* lcd_8bit, const uint8 row, const uint8 col);

 #endif	/* ECU_LCD_H */