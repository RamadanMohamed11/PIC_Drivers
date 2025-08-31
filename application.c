/**
 * @file    application.c
 * @author  Eng_Ramadan_Mohamed
 * @brief   Main application file.
 * @version 0.1
 * @date    2025-09-01
 */

#include "application.h"


/*
 * 
 */


void application_initialize(void);

int main(void) 
{
    leds_in_port_t LEDs1={.port=PORTD_INDEX,.state=GPIO_LOW};
    led_port_initialize(&LEDs1);
    keypad_t keypad={
                        .Keypad_row_pins[0].port=PORTB_INDEX,.Keypad_row_pins[0].pin=PIN0,.Keypad_row_pins[0].direction=GPIO_OUTPUT,.Keypad_row_pins[0].logic=GPIO_LOW,
                        .Keypad_row_pins[1].port=PORTB_INDEX,.Keypad_row_pins[1].pin=PIN1,.Keypad_row_pins[1].direction=GPIO_OUTPUT,.Keypad_row_pins[1].logic=GPIO_LOW,
                        .Keypad_row_pins[2].port=PORTB_INDEX,.Keypad_row_pins[2].pin=PIN2,.Keypad_row_pins[2].direction=GPIO_OUTPUT,.Keypad_row_pins[2].logic=GPIO_LOW,
                        .Keypad_row_pins[3].port=PORTB_INDEX,.Keypad_row_pins[3].pin=PIN3,.Keypad_row_pins[3].direction=GPIO_OUTPUT,.Keypad_row_pins[3].logic=GPIO_LOW,
                        
                        .Keypad_col_pins[0].port=PORTB_INDEX,.Keypad_col_pins[0].pin=PIN4,.Keypad_col_pins[0].direction=GPIO_INPUT,
                        .Keypad_col_pins[1].port=PORTB_INDEX,.Keypad_col_pins[1].pin=PIN5,.Keypad_col_pins[1].direction=GPIO_INPUT,
                        .Keypad_col_pins[2].port=PORTB_INDEX,.Keypad_col_pins[2].pin=PIN6,.Keypad_col_pins[2].direction=GPIO_INPUT,
                        .Keypad_col_pins[3].port=PORTB_INDEX,.Keypad_col_pins[3].pin=PIN7,.Keypad_col_pins[3].direction=GPIO_INPUT,
                    };
    uint8 keypad_chars[KEYPAD_ROW][KEYPAD_COL]={{'7','8','9','/'},{'4','5','6','X'},{'1','2','3','-'},{'#','0','=','+'}};
//    uint8 keypad_chars[][4]={"789/","456X","123-","#0=+"};
    keypad_initialize(&keypad,keypad_chars);
//    application_initialize();
//    segment_multi_pin_t MultiSegPins[]={{.port=PORTC_INDEX,.pin=PIN4},{.port=PORTC_INDEX,.pin=PIN5}};
//    segment_multi_initialize(&MultiSegPins[0]);
//    segment_multi_initialize(&MultiSegPins[1]);
//    segment_t seg1={
//        .segment_pins[0].port=PORTC_INDEX,.segment_pins[0].pin=PIN0,
//        .segment_pins[1].port=PORTC_INDEX,.segment_pins[1].pin=PIN1,
//        .segment_pins[2].port=PORTC_INDEX,.segment_pins[2].pin=PIN2,
//        .segment_pins[3].port=PORTC_INDEX,.segment_pins[3].pin=PIN3,
//        .segment_type=segment_common_cathode
//    };
//    segment_initialize(&seg1);
//    dc_motor_t M1={.portIN1=PORTB_INDEX,.portIN2=PORTB_INDEX,.pin1=PIN0,.pin2=PIN1};
//    dc_motor_t M2={.portIN1=PORTB_INDEX,.portIN2=PORTB_INDEX,.pin1=PIN2,.pin2=PIN3};
//    dc_motor_initialize(&M1);
//    dc_motor_initialize(&M2);
//    Relay_t R1={.port=PORTA_INDEX,.pin=PIN0};
//    Relay_initialize(&R1);
    
    
//    uint8 ButState;
//    pin_config_t LED0={.port=PORTC_INDEX,.direction=GPIO_OUTPUT,.pin=PIN0,.logic=GPIO_LOW};
//    pin_config_t LED1={.port=PORTC_INDEX,.direction=GPIO_OUTPUT,.pin=PIN,.logic=GPIO_LOW};
//    pin_config_t But={.port=PORTC_INDEX,.direction=GPIO_INPUT,.pin=PIN1};
//    gpio_pin_direction_initialize(&LED0);
//    gpio_pin_direction_initialize(&LED1);
//    gpio_pin_direction_initialize(&But);
//    TRISB=0x11;
    //gpio_port_direction_initialize(PORTC_INDEX,0xAA);
    //gpio_port_write_logic(PORTC_INDEX,0x01);
    
    
//    led_t LED1={.port=PORTC_INDEX,.pin=PIN4,.state=STD_LOW};
//    led_initialize(&LED1);
//    
//    button_t b1={.port=PORTD_INDEX,.pin=PIN0,.button_config=BUTTON_ACTIVE_HIGH};
//    button_initialize(&b1);
//    button_t b2={.port=PORTD_INDEX,.pin=PIN1,.button_config=BUTTON_ACTIVE_HIGH};
//    button_initialize(&b2);
//    button_state_t s1b1;
//    button_state_t s2b1;
////    
//    button_state_t s1b2;
//    button_state_t s2b2; 
//    sint8 number=0;
//    uint8 counter1=0;
//    uint8 counter2=0;
    uint8 chr;
    uint8 ledNUm;
    while(1)
    {
        keypad_get_char(&keypad,&chr);
        ledNUm=chr-48;
        if(chr!='\0')
            led_port_write(&LEDs1,&ledNUm);
        
//        segment_write(&seg1,number/10);
//        segment_multi_enable(&MultiSegPins[0]);
//        segment_multi_disable(&MultiSegPins[1]);
//        __delay_ms(500);
//        segment_multi_disable(&MultiSegPins[0]);
//        segment_multi_disable(&MultiSegPins[1]);
//        segment_write(&seg1,number%10);
//        segment_multi_enable(&MultiSegPins[1]);
//        segment_multi_disable(&MultiSegPins[0]);
//        __delay_ms(500);
//        segment_multi_disable(&MultiSegPins[0]);
//        segment_multi_disable(&MultiSegPins[1]);
//        __delay_ms(1);
//        button_read_state(&b1,&s1b1);
//        if(s1b1==BUTTON_PRESSED)
//        {
//            counter1++;
//        }
//        if(counter1>20)
//        {
//            counter1=0;
//            s2b1=BUTTON_PRESSED;
//        }
//        else
//            s2b1=BUTTON_RELEASED;
//        
//        if(s2b1==BUTTON_PRESSED)
//            number++;
//        if(number>99)
//            number=0;
//        button_read_state(&b2,&s1b2);
//        if(s1b2==BUTTON_PRESSED)
//        {
//            counter2++;
//        }
//        if(counter2>20)
//        {
//            counter2=0;
//            s2b2=BUTTON_PRESSED;
//        }
//        else
//            s2b2=BUTTON_RELEASED;
//        
//        if(s2b2==BUTTON_PRESSED)
//            number--;
//        if(number<0)
//            number=99;
        
        
//        dc_motor_move_right(&M1);
//        dc_motor_move_right(&M2);
//        __delay_ms(1000);
//        dc_motor_move_left(&M1);
//        dc_motor_move_left(&M2);
//        __delay_ms(1000);
//        button_read_state(&b1,&s1b1);
//        __delay_ms(15);
//        button_read_state(&b1,&s2b1);
//        
//        button_read_state(&b2,&s1b2);
//        __delay_ms(15);
//        button_read_state(&b2,&s2b2);
//        if(s1b1&&s2b1)
//            Relay_turn_on(&R1);
//        else if(s1b2&&s2b2)
//            Relay_turn_on(&R1);
//        else
//            Relay_turn_off(&R1);
        
//        gpio_port_toggle_logic(PORTC_INDEX);
//        gpio_pin_read_logic(&But,&ButState);
//        __delay_ms(15);
//        gpio_pin_write_logic(&LED0,ButState);
        
//        gpio_pin_toggle_logic(&LED1);
//        __delay_ms(500);
    }
    return (EXIT_SUCCESS);
}

void application_initialize(void)
{
    
}

