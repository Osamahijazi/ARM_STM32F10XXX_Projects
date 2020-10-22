/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:14/8/2020***********************************/
/***********version:2***************************************/
/*********Description:GPIO REGISTERS***********************/
/***********************************************************/


#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/***********************************************************************************************************************************************************************************************************************************************************
                                                   *******Base Address Macros**********
***********************************************************************************************************************************************************************************************************************************************************/																																										 

#define GPIOA_BASE_ADDRESS         0X40010800
#define GPIOB_BASE_ADDRESS         0X40010C00
#define GPIOC_BASE_ADDRESS         0X40011000

/***********************************************************************************************************************************************************************************************************************************************************
                                                   *******GPIOA Register Definition**********
***********************************************************************************************************************************************************************************************************************************************************/																																										 

#define GPIOA_CRL          *((uint32*)(GPIOA_BASE_ADDRESS+0x00))
#define GPIOA_CRH          *((uint32*)(GPIOA_BASE_ADDRESS+0x04))
#define GPIOA_IDR          *((uint32*)(GPIOA_BASE_ADDRESS+0x08))
#define GPIOA_ODR          *((uint32*)(GPIOA_BASE_ADDRESS+0x0C))
#define GPIOA_BSR          *((uint32*)(GPIOA_BASE_ADDRESS+0x10))
#define GPIOA_BRR          *((uint32*)(GPIOA_BASE_ADDRESS+0x14))
#define GPIOA_LCK          *((uint32*)(GPIOA_BASE_ADDRESS+0x18))


/***********************************************************************************************************************************************************************************************************************************************************
                                                   *******GPIOB Register Definition**********
***********************************************************************************************************************************************************************************************************************************************************/																																										 
													
#define GPIOB_CRL          *((uint32*)(GPIOB_BASE_ADDRESS+0x00))
#define GPIOB_CRH          *((uint32*)(GPIOB_BASE_ADDRESS+0x04))
#define GPIOB_IDR          *((uint32*)(GPIOB_BASE_ADDRESS+0x08))
#define GPIOB_ODR          *((uint32*)(GPIOB_BASE_ADDRESS+0x0C))
#define GPIOB_BSR          *((uint32*)(GPIOB_BASE_ADDRESS+0x10))
#define GPIOB_BRR          *((uint32*)(GPIOB_BASE_ADDRESS+0x14))
#define GPIOB_LCK          *((uint32*)(GPIOB_BASE_ADDRESS+0x18))

/***********************************************************************************************************************************************************************************************************************************************************
                                                   *******GPIOC Register Definition**********
***********************************************************************************************************************************************************************************************************************************************************/																																										 

#define GPIOC_CRL          *((uint32*)(GPIOC_BASE_ADDRESS+0x00))
#define GPIOC_CRH          *((uint32*)(GPIOC_BASE_ADDRESS+0x04))
#define GPIOC_IDR          *((uint32*)(GPIOC_BASE_ADDRESS+0x08))
#define GPIOC_ODR          *((uint32*)(GPIOC_BASE_ADDRESS+0x0C))
#define GPIOC_BSR          *((uint32*)(GPIOC_BASE_ADDRESS+0x10))
#define GPIOC_BRR          *((uint32*)(GPIOC_BASE_ADDRESS+0x14))
#define GPIOC_LCK          *((uint32*)(GPIOC_BASE_ADDRESS+0x18))

/***********************************************************************************************************************************************************************************************************************************************************
                                                   *******Private Macros**********
***********************************************************************************************************************************************************************************************************************************************************/																																										 
#define  BITS_CLEAR_MASK                  	0X00000001							 
#define  BITS_SHIFT_NUMBER                      4
#define  LOW_BIT_POS                            7
#define  UP_BIT_POS                             15
#define  REG_DIGITS                              8
#define  CONFIG_ACTIVATED                   0x00010000  
#define  WRONG_PIN_NUMBER_SET_MODE               1
#define  WRONG_PIN_NUMBER_SET_PIN                2
#define  WRONG_PORT_NUMBER_SET_PORT              3
#define  WRONG_PIN_NUMBER_GET_PIN                4
#define  WRONG_PORT_NUMBER_GET_PORT              5
#define  WRONG_PIN_NUMBER_TOGGLE_PIN             6
#define  WRONG_PIN_NUMBER_LOCK_PIN               7

/***********************************************************************************************************************************************************************************************************************************************************/
#endif