/* 
 * File:   std_types.h
 * Author: Eng_Ramadan_Mohamed
 *
 * Created on 16 ????, 2024, 02:10 ?
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H

#include "compiler.h"
#include "std_libraries.h"

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;

typedef uint8 Std_ReturnType;

#define STD_HIGH (Std_ReturnType)1
#define STD_LOW (Std_ReturnType)0

#define E_OK (Std_ReturnType)1
#define E_NOT_OK (Std_ReturnType)0

#endif	/* STD_TYPES_H */

