/* 
 * File:   ecu_rgb_led.h
 * Author: Eng_Ramadan_Mohamed
 *
 * Created on 16 ????, 2024, 02:17 ?
 */

 #ifndef ECU_LED_H
 #define ECU_LED_H

 #include "../../MCAL/GPIO/hal_gpio.h"

 typedef enum
 {
    rgb_led_on,
    rgb_led_off
 }rgb_led_stutes;
 
 typedef enum
 {
     OFF
    RED,
    GREEN,
    BLUE,
    YELLOW,
    ORANGE,
    PURPLE,
    WHITE,
 }rgb_color_t;

 typedef struct
 {
    uint8 port : 3;
    uint8 pin : 3;
 }rgb_led_channel_t;

 typedef struct
 {
    rgb_led_channel_t red_channel;
    rgb_led_channel_t green_channel;
    rgb_led_channel_t blue_channel;
    rgb_led_stutes state;
 }rgb_led_t;

 Std_ReturnType rgb_led_initialize(const rgb_led_t* RGB_LED);
 Std_ReturnType rgb_led_turn_on(const rgb_led_t* RGB_LED);
 Std_ReturnType rgb_led_turn_off(const rgb_led_t* RGB_LED);
 Std_ReturnType rgb_led_toggle(const rgb_led_t* RGB_LED);

 #endif