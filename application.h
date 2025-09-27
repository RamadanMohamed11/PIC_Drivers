/**
 * @file    application.h
 * @author  Eng_Ramadan_Mohamed
 * @brief   Header file for the main application.
 * @version 0.1
 * @date    2025-09-01
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

#include "ECU/LED/ecu_led.h"
#include "ECU/7_Segment/ecu_7_segment.h"
#include "ECU/BUTTON/ecu_button.h"
#include "ECU/DC_MOTOR/ecu_dc_motor.h"
#include "ECU/RELAY/ecu_relay.h"
#include "ECU/Keypad/ecu_keypad.h"
#include "ECU/RGB_LED/ecu_rgb_led.h"
#include "ECU/LCD/ecu_lcd.h"


rgb_led_t rgb_led={.red_channel.port=PORTC_INDEX,.red_channel.pin=PIN0,.green_channel.port=PORTC_INDEX,.green_channel.pin=PIN1,.blue_channel.port=PORTC_INDEX,.blue_channel.pin=PIN2,.state=rgb_led_off};
extern lcd_4bit_t lcd_4bit;
extern lcd_8bit_t lcd_8bit;


Std_ReturnType application_initialize(void);


#endif	/* APPLICATION_H */

