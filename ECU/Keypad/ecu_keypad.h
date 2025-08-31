/**
 * @file    ecu_keypad.h
 * @author  Eng_Ramadan_Mohamed
 * @brief   Header file for the Keypad driver.
 * @version 0.1
 * @date    2025-08-31
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

#include "../../MCAL/GPIO/hal_gpio.h"

#define KEYPAD_ROW 4
#define KEYPAD_COL 4

uint8 local_keypad_chars[KEYPAD_ROW][KEYPAD_COL];

typedef struct
{
    pin_config_t Keypad_row_pins[KEYPAD_ROW];
    pin_config_t Keypad_col_pins[KEYPAD_COL];
}keypad_t;

Std_ReturnType keypad_initialize(const keypad_t* keypad , const uint8 keypad_chars[KEYPAD_ROW][KEYPAD_COL]);
Std_ReturnType keypad_get_char(const keypad_t* keypad , uint8* chr);

#endif	/* ECU_KEYPAD_H */

