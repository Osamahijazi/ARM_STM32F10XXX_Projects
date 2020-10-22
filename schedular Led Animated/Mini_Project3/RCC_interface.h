
/************************************************/
/******Author: osama salah hijazi****************/
/******Date: 5 / 8 /2020*************************/
/****** Ver: Version 1***************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#include "STD_TYPES.h"

#define RCC_AHB   0
#define RCC_APB1  1
#define RCC_APB2  2



  void RCC_InitysClock(void);
	
	void RCC_VoidEnableClock(uint8,uint8);

#endif