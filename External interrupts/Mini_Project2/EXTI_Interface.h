/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:22/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


#include"STD_TYPES.h"

                                                    /*MACROS*/
																										
																										
																										/*INTERRUPT NUMBERS*/
																										
#define      EXTTI0              0
																										
																										
																										
																										
																										
																										
																										

                                                    /* INTERRUPT LINES*/

#define      LINE0              0
#define      LINE1              1 
#define      LINE2              2
#define      LINE3              3
#define      LINE4              4 
#define      LINE5              5
#define      LINE6              6 
#define      LINE7              7
#define      LINE8              8
#define      LINE9              9
#define      LINE10             10
#define      LINE11             11
#define      LINE12             12
#define      LINE13             13
#define      LINE14             14
#define      LINE15             15


                   /*INTERRUPT MODES*/

#define   RISING            1
#define   FALING            0
#define   ON_CHANGE         2


 void EXTI_voidInit(void);
 void EXTI_voidEnableEXTI (uint8 Copy_uint8Line);
 void EXTI_voidDisableEXTI(uint8 Copy_uint8Line);
 void EXTI_voidSwTrigger  (uint8 Copy_uint8Line);
 void EXTI_voidSignalLatch(uint8 Copy_uint8Line , uint8 Copy_uint8Mode);/*change EXT Mode at the run time*/
 void EXTI0_voidSetCallBack(void (*ptr)(void));  /*EXTI0 CALL BACK FUNCTION*/
 void EXTI1_voidSetCallBack(void (*ptr)(void));  /*EXTI1 CALL BACK FUNCTION*/
 void EXTI2_voidSetCallBack(void (*ptr)(void));  /*EXTI2 CALL BACK FUNCTION*/
 void EXTI0_IRQHandler(void);
 void  EXTI1_IRQHandler(void);
 void  EXTI2_IRQHandler(void);














#endif