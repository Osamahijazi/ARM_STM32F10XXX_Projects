/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:1/9/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#include "STD_TYPES.h"
#include "MATH_BIT.h"
#include "SYSTIMER_Interface.h"
#include "OS_Interface.h"
#include "OS_Private.h"
#include "OS_Config.h"


static uint8  ERROR_TYPE ;
                                     /*Array of structures*/

static Task  OS_TASK[TASK_NUMBER] = {NULL} ;


void OS_voidCreateTask(uint8 Copy_uint8Periority,uint16 Copy_uint8Priodicity,void (* Task_ptr)(void),uint8 Copy_uint8FirstDelay){

OS_TASK[Copy_uint8Periority].Periodicity = Copy_uint8Priodicity;
OS_TASK[Copy_uint8Periority].Fun_Ptr     = Task_ptr;   
OS_TASK[Copy_uint8Periority].First_Delay = Copy_uint8FirstDelay;

}

void Scheduler_Begin (void){

for(uint8 i = 0 ; i  < TASK_NUMBER; i++){
	
	
    if ((OS_TASK[i].Fun_Ptr !=  NULL) && (OS_TASK[i].STATE == TASK_READY)){
			
			
		  if( (OS_TASK[i].First_Delay) == 0){
				
				OS_TASK[i].First_Delay = OS_TASK[i].Periodicity ;
			  OS_TASK[i].Fun_Ptr() ;
             }
			else 
			       {
			
						
				   (OS_TASK[i].First_Delay)--;
			
			 }

		}
		
		else 
			{
		
      ERROR_TYPE	=  ERROR_SCH_IS_PAUSED_TASK;	
		
		}
		
 }

	
}

void OS_voidStart(void){

                    /*Init*/
STK_voidInit();
                   /*TICK == 1 mSEC == 1000 uSEC*/
STK_voidSetIntervalPeriodic(1000,Scheduler_Begin);/*Call schedular to order Tasks*/
	
}

void OS_voidStop(void){

	                    /*Stop STK interrupt*/
	STK_voidStopInterval();
	
}

void OS_voidSuspenTask(uint8 Copy_uint8Periority){ /*Pause a specific Task*/
	
	  OS_TASK[Copy_uint8Periority].STATE = TASK_PAUSED;
	
}
void OS_voidResumeTask(uint8 Copy_uint8Periority){ /* Resume a specific Task*/

		OS_TASK[Copy_uint8Periority].STATE = TASK_READY;

}

void OS_voidKillTask  (uint8 Copy_uint8Periority) {   /*Delete the Task*/
	
	 OS_TASK[Copy_uint8Periority].Periodicity = 0;    /*Return the Priority To Zero*/
	 OS_TASK[Copy_uint8Periority].Fun_Ptr = NULL ;   /*Refer The Pionter To Null*/ 
	 OS_TASK[Copy_uint8Periority].First_Delay = 0;   /* Return THE delay To Zero*/
   ERROR_TYPE =	ERROR_SCH_IS_DELETED_TASK      ;

}






