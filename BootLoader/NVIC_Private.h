/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:20/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H
/***********************************************************************************************************************************************************************************************************************************************************
                                                   *******Base Address Macros**********
***********************************************************************************************************************************************************************************************************************************************************/																																										 
#define NVIC_ISER0      *((volatile uint32*)0XE000E100)
#define NVIC_ISER1      *((volatile uint32*)0XE000E104)


#define NVIC_ICER0      *((volatile uint32*)0XE000E180)
#define NVIC_ICER1      *((volatile uint32*)0XE000E184)


#define NVIC_ISPR0      *((volatile uint32*)0XE000E200)
#define NVIC_ISPR1      *((volatile uint32*)0XE000E204)


#define NVIC_ICPR0      *((volatile uint32*)0XE000E280)
#define NVIC_ICPR1      *((volatile uint32*)0XE000E284)


#define NVIC_IABR0      *((volatile uint32*)0XE000E300)
#define NVIC_IABR1      *((volatile uint32*)0XE000E304)
	

#define NVIC_IPR         ((volatile uint8*)0XE000E400)        /* Pionter to first interrupt of the regiter*/ 
#define SCB_AIRCR       *((volatile uint32*)0XE000ED0C)       /*Registr  to set Group and Sub priority  OF NVIC */
/***********************************************************************************************************************************************************************************************************************************************************
                                                   *******Private Macros**********
***********************************************************************************************************************************************************************************************************************************************************/																																										 

#define MAX_REG_BITS        32
#define MAX_BIT_POS         31
#define MAX_POS_NUM         59
#define MAX_IPR_REG         16
/***********************************************************************************************************************************************************************************************************************************************************/




#endif
/**************************************************************END OF FILE*********************************************************************************************************************************************************************/