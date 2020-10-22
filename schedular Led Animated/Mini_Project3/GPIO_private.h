/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:14/8/2020***********************************/
/***********version:1***************************************/
/*********Description:GPIOS REGISTERS***********************/
/***********************************************************/


#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

                          /****GPIOS  BASE ADDRESSES ****/

#define GPIOA_BASE_ADDRESS         0X40010800
#define GPIOB_BASE_ADDRESS         0X40010C00
#define GPIOC_BASE_ADDRESS         0X40011000

                          /*GPIOA REGISTERS DEFOINITIONS*/

#define GPIOA_CRL          *((uint32*)(GPIOA_BASE_ADDRESS+0x00))
#define GPIOA_CRH          *((uint32*)(GPIOA_BASE_ADDRESS+0x04))
#define GPIOA_IDR          *((uint32*)(GPIOA_BASE_ADDRESS+0x08))
#define GPIOA_ODR          *((uint32*)(GPIOA_BASE_ADDRESS+0x0C))
#define GPIOA_BSR          *((uint32*)(GPIOA_BASE_ADDRESS+0x10))
#define GPIOA_BRR          *((uint32*)(GPIOA_BASE_ADDRESS+0x14))
#define GPIOA_LCK          *((uint32*)(GPIOA_BASE_ADDRESS+0x18))


                          /*GPIOB REGISTERS DEFINITIONS*/
													
#define GPIOB_CRL          *((uint32*)(GPIOB_BASE_ADDRESS+0x00))
#define GPIOB_CRH          *((uint32*)(GPIOB_BASE_ADDRESS+0x04))
#define GPIOB_IDR          *((uint32*)(GPIOB_BASE_ADDRESS+0x08))
#define GPIOB_ODR          *((uint32*)(GPIOB_BASE_ADDRESS+0x0C))
#define GPIOB_BSR          *((uint32*)(GPIOB_BASE_ADDRESS+0x10))
#define GPIOB_BRR          *((uint32*)(GPIOB_BASE_ADDRESS+0x14))
#define GPIOB_LCK          *((uint32*)(GPIOB_BASE_ADDRESS+0x18))

                            /*GPIOC REGISTERS DEFIFTIONS*/

#define GPIOC_CRL          *((uint32*)(GPIOC_BASE_ADDRESS+0x00))
#define GPIOC_CRH          *((uint32*)(GPIOC_BASE_ADDRESS+0x04))
#define GPIOC_IDR          *((uint32*)(GPIOC_BASE_ADDRESS+0x08))
#define GPIOC_ODR          *((uint32*)(GPIOC_BASE_ADDRESS+0x0C))
#define GPIOC_BSR          *((uint32*)(GPIOC_BASE_ADDRESS+0x10))
#define GPIOC_BRR          *((uint32*)(GPIOC_BASE_ADDRESS+0x14))
#define GPIOC_LCK          *((uint32*)(GPIOC_BASE_ADDRESS+0x18))











#endif