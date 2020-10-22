/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:22/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#include"STD_TYPES.h"

 
typedef struct{   /* Registers used to Alternative Function*/

          uint32 EVCR;
	        uint32 MAPR;
	        uint32 EXTICR[4];
	        uint32 MAPR2;
	
}AFIO_t;

                            /* Pionter to Structure */
#define    AFIO     ((volatile AFIO_t *) 0x40010000)



                                          /* MACROS  OF ALTERNATINE PINS OF EXTI*/






























#endif