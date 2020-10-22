/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:26/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef SYSTIMER_PRIVATE_H
#define SYSTIMER_PRIVATE_H


 #include "STD_TYPES.h"

   
typedef struct{   

          uint32 CTRL;
	        uint32 LOAD;
	        uint32 Value;
	
}STK_t;

  /* Pionter to Structure */
#define    STK    ((volatile STK_t*) 0xE000E010)

	




#define  STK_ENABLE                  0
#define  STK_INTERRUPT_ENABLE        1
#define  STK_CLOCK                   2

#define   STK_AHB                    0
#define   STK_AHB_DIV_8              1





#endif