/**
 * @file    ecu_dc_motor.h
 * @author  Eng_Ramadan_Mohamed
 * @brief   Header file for the DC Motor driver.
 * @version 0.1
 * @date    2025-08-31
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

#include "../../MCAL/GPIO/hal_gpio.h"

typedef enum
{
    dc_motor_off,
    dc_motor_on
}dc_motor_state_t;

typedef struct
{
    uint8 portIN1 : 3;
    uint8 portIN2 : 3;
    uint8 pin1 : 3;
    uint8 pin2 : 3;
}dc_motor_t;

Std_ReturnType dc_motor_initialize(const dc_motor_t* dc_motor);
Std_ReturnType dc_motor_move_right(const dc_motor_t* dc_motor);
Std_ReturnType dc_motor_move_left(const dc_motor_t* dc_motor);

#endif	/* ECU_DC_MOTOR_H */

