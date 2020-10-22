
/************************************************/
/******Author: osama salah hijazi****************/
/******Date: 5 / 8 /2020*************************/
/****** Ver: Version 1***************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#include "STD_TYPES.h"

#define RCC_AHB   10
#define RCC_APB1  11
#define RCC_APB2  12

#define RCC_GPIOA  2 
#define RCC_GPIOB  3 
#define RCC_GPIOC  4 
#define RCC_AFIO   0 






  void RCC_InitysClock(void);
	
	void RCC_VoidEnableClock(uint8,uint8);

#endif

