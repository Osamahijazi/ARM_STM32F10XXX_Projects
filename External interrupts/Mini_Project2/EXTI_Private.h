/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:22/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#include"STD_TYPES.h"



typedef struct {

        volatile   uint32  IMR   ;
        volatile   uint32  EMR   ;
        volatile   uint32  RTSR  ;
        volatile   uint32  FTSR  ;
        volatile   uint32  SWIER ;
        volatile   uint32  PR    ; 

}EXTI_t;

#define EXTI (( volatile EXTI_t *) 0x40010400)   /* Pionter to Struct to acsses any register in the struct*/





                            










#endif