/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:26/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef LED_DISPLAY_H
#define LED_DISPLAY_H


#define GPIOA_ODR          *((uint32*)(0X40010800+0x0C))

#include "STD_TYPES.h"

 void DISPLAY_AllShiftRight (void);
 void DISPLAY_AllShiftLeft  (void);
 void DISPLAY_HalfShiftRight(void);
 void DISPLAY_AllLedON      (void);






#endif