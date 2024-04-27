/* 
 * File:   ecu_7_segment.h
 * Author: Eng_Ramadan_Mohamed
 *
 * Created on 25 ????, 2024, 04:20 ?
 */

#ifndef ECU_7_SEGMENT_H
#define	ECU_7_SEGMENT_H

#include "../../MCAL/GPIO/hal_gpio.h"

typedef enum
{
    segment_common_cathode,
    segment_common_anode
}segment_type_t;

typedef struct
{
    uint8 port : 3;
    uint8 pin : 3;
}segment_pin_t;

typedef struct
{
    segment_pin_t segment_pins[4];
    segment_type_t segment_type;
}segment_t;

typedef struct
{
    uint8 port : 3;
    uint8 pin : 3;
}segment_multi_pin_t;

Std_ReturnType segment_initialize(const segment_t* segment);
Std_ReturnType segment_write(const segment_t* segment,uint8 number);

Std_ReturnType segment_multi_initialize(const segment_multi_pin_t* segment);
Std_ReturnType segment_multi_enable(const segment_multi_pin_t* segment);
Std_ReturnType segment_multi_disable(const segment_multi_pin_t* segment);

#endif	/* ECU_7_SEGMENT_H */

