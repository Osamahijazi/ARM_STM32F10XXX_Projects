/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:1/9/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

#include "STD_TYPES.h"

void OS_voidCreateTask(uint8 Copy_uint8Periority,uint16 Copy_uint8Priodicity,void (* Task_ptr)(void),uint8 Copy_uint8FirstDelay);
void OS_voidStart(void);
void OS_voidStop (void);
void Scheduler_Begin (void);
void OS_voidSuspenTask(uint8 Copy_uint8Periority); /*Pause a specific Task*/
void OS_voidResumeTask(uint8 Copy_uint8Periority); /* Resume a specific Task*/
void OS_voidKillTask  (uint8 Copy_uint8Periority);       /*Delete the Task*/


                                                     /*PRIORITIES MACROS*/

#define  PRIORITY_ZERO     0
#define  PRIORITY_ONE      1
#define  PRIORITY_TWO      2
#define  PRIORITY_THREE    3
#define  PRIORITY_FOUR     4
#define  PRIORITY_FIVE     5
#define  PRIORITY_SIX      6
#define  PRIORITY_SEVEN    7
#define  PRIORITY_EIGHT    8


                                                     /*FIRST DELAY MACROS*/


#define  DELAY_ZERO        0 
#define  DELAY_ONE         1 
#define  DELAY_TWO         2 
#define  DELAY_THREE       3 
#define  DELAY_FOUR        4 
#define  DELAY_FIVE        5 
#define  DELAY_SIX         6 
#define  DELAY_SEVEN       7 
#define  DELAY_EIGHT       8 





                                                     /*Periodicity MACROS*/

#define  Periodicity_TASK_ZERO          1000 
#define  Periodicity_TASK_ONE           2000 
#define  Periodicity_TASK_TWO           3000  
/*
#define  Periodicity_TASK_THREE         4000 
#define  Periodicity_TASK_FOUR          5000 
#define  Periodicity_TASK_FIVE          6000 
#define  Periodicity_TASK_SIX           7000 
#define  Periodicity_TASK_SEVEN         8000 
#define  Periodicity_TASK_EIGHT         9000 

*/


                                                      /*ERROR MACROS*/

#define   ERROR_SCH_TOO_MANY_TASKS          0
#define   ERROR_SCH_IS_DELETED_TASK         1
#define   ERROR_SCH_IS_PAUSED_TASK          2












#endif
