/**
 * @file    std_types.h
 * @author  Eng_Ramadan_Mohamed
 * @brief   Contains standard data type definitions.
 * @version 0.1
 * @date    2025-08-31
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H

#include "compiler.h"
#include "std_libraries.h"

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;

typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;

typedef uint8 Std_ReturnType;

#define STD_HIGH (Std_ReturnType)1
#define STD_LOW (Std_ReturnType)0

#define STD_ON  1
#define STD_OFF 0

#define STD_ACTIVE  1
#define STD_IDLE    0

#define E_OK (Std_ReturnType)1
#define E_NOT_OK (Std_ReturnType)0

#endif	/* STD_TYPES_H */

