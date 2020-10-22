/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:1/9/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

#include "STD_TYPES.h"
#define NULL   (void*) 0 


typedef struct {

  uint16 Periodicity      ;
	void   (*Fun_Ptr)(void) ;
	uint16 First_Delay      ;
	uint8  STATE            ;
	uint8  ERROR            ;
	
}Task;









#endif