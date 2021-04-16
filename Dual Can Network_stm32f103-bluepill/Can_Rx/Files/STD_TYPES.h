/************************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H

#include "stm32f10x.h"

/*
typedef unsigned char           u8  ;
typedef unsigned short int      u16 ;
typedef unsigned long int       u32 ;
typedef unsigned long long int  u64 ;
/*typedef signed char             s8  ;
typedef signed short int        s16 ;
typedef signed long int         s32 ;
typedef signed long long int    s64 ;*/

typedef unsigned char         uint8;          /*           0 .. 255             */
typedef signed char           sint8;          /*        -128 .. +127            */
typedef unsigned short        uint16;         /*           0 .. 65535           */
typedef signed short          sint16;         /*      -32768 .. +32767          */
typedef unsigned long         uint32;         /*           0 .. 4294967295      */
typedef signed long           sint32;         /* -2147483648 .. +2147483647     */
typedef unsigned long long    uint64;         /*       0..18446744073709551615  */
typedef signed long long      sint64;
typedef float                 float32;
typedef double                float64;



#endif
