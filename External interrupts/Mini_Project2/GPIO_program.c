/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:14/8/2020***********************************/
/***********version:2***************************************/
/*********Description:GPIOS REGISTERS***********************/
/***********************************************************/
#include "STD_TYPES.h"
#include "MATH_BIT.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"
#include "GPIO_config.h"
/***********************************************************************************************************************************************************************************************************************************************************/
void GPIO_VoidSetPinDirection(uint8 Copy_u8Port,                    /*SET THE MODE OF CERTAIN PIN OF PORT*/
	                            uint8 Copy_u8Pin ,
                              uint8 Copy_u8Mode ){

 switch (Copy_u8Port)                                                 /*CHOOSE A CERTAIN PORT {A,B,C}*/
  {
  
  	case GPIOA :                                                                             /*SET MODE OF PINS OF PORT A*/
			 
                    if (Copy_u8Pin <= LOW_BIT_POS ){               /*IF PIN NUMBER IS LESS THAN 8*/
								
								   	 GPIOA_CRL &= ~((BITS_CLEAR_MASK) << (Copy_u8Pin * BITS_SHIFT_NUMBER));  /*CLEAR 4 BITS OF MODE TO SET A NEW ONE */
								  	 GPIOA_CRL |=  ((Copy_u8Mode)<< (Copy_u8Pin * BITS_SHIFT_NUMBER ));     /*CLEAR 4 BITS OF MODE TO SET A NEW ONE */
								} 
										
              else   
                    if (Copy_u8Pin <= UP_BIT_POS){               /*IF PIN NUMBER IS LESS THAN 15 */
											
											Copy_u8Pin =    Copy_u8Pin - REG_DIGITS ;  /*SUBTRACT 8 TO SET IN LOWER REGISTER*/
											GPIOA_CRH &= ~((BITS_CLEAR_MASK)<< (Copy_u8Pin * BITS_SHIFT_NUMBER));  /*CLEAR 4 BITS OD MODE TO SET A NEW ONE */
									    GPIOA_CRH |=  ((Copy_u8Mode)<< (Copy_u8Pin * BITS_SHIFT_NUMBER ));		/*CLEAR 4 BITS OF MODE TO SET A NEW ONE */
	 							}
	                 break;
													
								
   case GPIOB :                                                                               /*SET MODE OF PINS OF PORT B*/
		
	                  if (Copy_u8Pin <= LOW_BIT_POS ){                   /*IF PIN NUMBER IS LESS THAN 8*/
								
								   	  GPIOB_CRL &= ~((BITS_CLEAR_MASK)<< (Copy_u8Pin * BITS_SHIFT_NUMBER));   /*CLEAR 4 BITS OF MODE TO SET A NEW ONE */
								  	  GPIOB_CRL |=  ((Copy_u8Mode)<< (Copy_u8Pin * BITS_SHIFT_NUMBER ));     /*CLEAR 4 BITS OF MODE TO SET A NEW ONE */
								} 
										
              else   
                    if (Copy_u8Pin <= UP_BIT_POS){                 /*IF PIN NUMBER IS LESS THAN 15 */
											
											Copy_u8Pin =    Copy_u8Pin - REG_DIGITS ;  /*SUBTRACT 8 TO SET IN LOWER REGISTER*/ 
											GPIOB_CRH &= ~((BITS_CLEAR_MASK)<< (Copy_u8Pin * BITS_SHIFT_NUMBER));    /*CLEAR 4 BITS OF MODE TO SET A NEW ONE */
									    GPIOB_CRH |=  ((Copy_u8Mode)<< (Copy_u8Pin * BITS_SHIFT_NUMBER ));			/*CLEAR 4 BITS OF MODE TO SET A NEW ONE */
	 							}
	
								     break;
	
   case GPIOC :                                                                                  /*SET MODE OF PINS OF PORT B*/
		 
                  if ((Copy_u8Pin <= 15) && (Copy_u8Pin >=13)){ 		 /*PORT C PINS IS {13,14,15} SO WE NEED TO USE CONDITION HERE*/      
	 
						  				Copy_u8Pin =    Copy_u8Pin - REG_DIGITS ;  /*SUBTRACT 8 TO SET IN LOWER REGISTER*/
											GPIOC_CRH &= ~((BITS_CLEAR_MASK)<< (Copy_u8Pin * BITS_SHIFT_NUMBER));     /*CLEAR 4 BITS OF MODE TO SET A NEW ONE */
									    GPIOC_CRH |=  ((Copy_u8Mode)<< (Copy_u8Pin * BITS_SHIFT_NUMBER ));		   /*CLEAR 4 BITS OF MODE TO SET A NEW ONE */
	 							
									}
                      break;

	default   :				
                		ERROR = WRONG_PIN_NUMBER_SET_MODE ;                    /* IF THERE IS ANY RUNTIME ERROR , WATCH THIS VAR IN DEBUG SESSION */
		                break;
	 
                                                 /*END OF SWITCH CASE*/
  }

}
/*****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  
void GPIO_voidSetPortDirection (uint8 Copy_u8Pin,
	                              uint8 Copy_u8Mode ){               /*SET THE MODE OF ALL PORT AT ONCE*/
	
	   for (uint8 PIN_NUMBER = PIN0 ; PIN_NUMBER <= PIN15 ; PIN_NUMBER++){  /*BEGIN OF LOOP AT PINS OF THE PORT*/
				

		    GPIO_VoidSetPinDirection(Copy_u8Pin , PIN_NUMBER , Copy_u8Mode);  /*SET MODE OF EACH PIN ONE BY ONE*/
		
	 }                                                /*END OF FOR LOOP*/
}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  																 																
void GPIO_VoidSetPinValue(uint8 Copy_u8Port ,
	                        uint8 Copy_u8Pin  ,                   /*SET A VALUE OF A CERTAIN PIN*/
                          uint8 Copy_u8Value ){
                    
  switch (Copy_u8Port)                                            /*CHOOSE A CERTAIN PORT {A,B,C}*/
    {
  
  	 case GPIOA :                                                /*SET VALUE TO A PIN OF PORT A*/
                    if (Copy_u8Value == GPIO_HIGH ){             /* IF Copy_u8Value = 1 SET CHOOSEN PIN */
											
											SET_BIT(GPIOA_ODR,Copy_u8Pin);
											
								} 
										
              else   
                    if (Copy_u8Value == GPIO_LOW){               /*RESET VALUE TO A PIN OF PORT A*/
											                                           /* IF Copy_u8Value = 0 CLEAR CHOOSEN PIN */
										  CLEAR_BIT(GPIOA_ODR,Copy_u8Pin);			
	 							}
	                 break;


    case GPIOB :                                                 /*SET VALUE TO A PIN OF PORT B*/
                    if (Copy_u8Value == GPIO_HIGH ){             /* IF Copy_u8Value = 1 SET CHOOSEN PIN */
											
											SET_BIT(GPIOB_ODR,Copy_u8Pin);
											
								} 
										
              else   
                    if (Copy_u8Value == GPIO_LOW){               /*RESET VALUE TO A PIN  OF PORT B*/
											                                           /* IF Copy_u8Value = 0 CLEAR CHOOSEN PIN */
										  CLEAR_BIT(GPIOB_ODR,Copy_u8Pin);			
	 							}
	                 break;
								
								
    case GPIOC :                                                  /*SET VALUE TO A PIN OF PORT C*/
                    if (Copy_u8Value == GPIO_HIGH ){              /* IF Copy_u8Value = 1 SET CHOOSEN PIN */
											
											SET_BIT(GPIOC_ODR,Copy_u8Pin);
											
								} 
										
              else   
                    if (Copy_u8Value == GPIO_LOW){                /*RESET VALUE TO A PIN OF PORT C*/
											                                            /* IF Copy_u8Value = 0 CLEAR CHOOSEN PIN */
										  CLEAR_BIT(GPIOC_ODR,Copy_u8Pin);			
	 							}
	                 break;
		default   :				
                		ERROR = WRONG_PIN_NUMBER_SET_PIN ;                    /* IF THERE IS ANY RUNTIME ERROR , WATCH THIS VAR IN DEBUG SESSION */
		                break;						
                                                 /*END OF SWITCH CASE*/
	}

}
/****************************************************************END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                  
void GPIO_voidSetPortValue (uint8  Copy_u8Port,
	                          uint16 Copy_uint16Value ){                           /*SET THE PORT VALUE*/
															
	switch (Copy_u8Port) {                                                  /*CHOOSE A CERTAIN PORT {A,B,C}*/  
		
		case GPIOA :                                                         /*SET VALUE OF PORT A*/
  			GPIOA_ODR = Copy_uint16Value ;  break ;
					
		case GPIOB :                                                         /*SET VALUE OF PORT B*/
			GPIOB_ODR = Copy_uint16Value  ;   break ;
					
		case GPIOC :                                                         /*SET VALUE OF PORT C*/
			GPIOC_ODR = Copy_uint16Value ;    break ;
				
		default    : 
			ERROR = WRONG_PORT_NUMBER_SET_PORT ;   break ;                   /* IF THERE IS ANY RUNTIME ERROR , WATCH THIS VAR IN DEBUG SESSION */
		             
		                                            /*END OF SWITCH CASE*/
	}
}
/**************************************************** *********END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                                                
uint8 GPIO_VoidGetPinValue(uint8 Copy_u8Port,
                           uint8 Copy_u8Pin  ){                                 /*GET THE VALUE OF A CERTAIN PIN IN A CERTAIN PORT*/
uint8 Result_Value = 0 ;                                     /*LOCAL VARIABLE TO SAVE THE VALUE*/
             
         switch (Copy_u8Port)                                                     /*CHOOSE A CERTAIN PORT {A,B,C}*/
                 {
  
  	case GPIOA :                                                                 /*GET VALUE OF A CERTAIN PIN IN PORT A*/
                   Result_Value = GET_BIT(GPIOA_IDR,Copy_u8Pin);                 /* Result_Value = PIN VALUE*/
	                 break;
    case GPIOB :	
                   Result_Value = GET_BIT(GPIOB_IDR,Copy_u8Pin);                  /*GET VALUE OF A CERTAIN PIN IN PORT B*/
	                 break;                                                         /* Result_Value = PIN VALUE*/
    case GPIOC :
                   Result_Value = GET_BIT(GPIOC_IDR,Copy_u8Pin);                  /*GET VALUE OF A CERTAIN PIN IN PORT C*/
	                 break;                                                         /* Result_Value = PIN VALUE*/
	      
		default   :				
                		ERROR = WRONG_PIN_NUMBER_GET_PIN ;                    /* IF THERE IS ANY RUNTIME ERROR , WATCH THIS VAR IN DEBUG SESSION */
		                break;
       	}		
                   return Result_Value;
				                                     /*END OF SWITCH CASE*/	
}
/**************************************************** *********END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                                                													 
uint16 GPIO_VoidGetPortValue      (uint8  Copy_u8Port  ){                                

uint16 Result_Value = 0 ;                                     /*LOCAL VARIABLE TO SAVE THE VALUE*/
             
         switch (Copy_u8Port)                                                     /*CHOOSE A CERTAIN PORT {A,B,C}*/
                 {
  
  	case GPIOA :                                                      /*SET VALUE OF A CERTAIN PIN IN PORT A*/
                   Result_Value = GPIOA_IDR;  break;                      /* Result_Value = PIN VALUE*/
	                 
    case GPIOB :	
                   Result_Value = GPIOB_IDR;  break;                   /*SET VALUE OF A CERTAIN PIN IN PORT B*/
	                                                                        /* Result_Value = PIN VALUE*/
    case GPIOC :
                   Result_Value = GPIOC_IDR;  break;                  /*SET VALUE OF A CERTAIN PIN IN PORT C*/
	                                                                        /* Result_Value = PIN VALUE*/
	      
                   return Result_Value;
		default   :				
                		ERROR = WRONG_PORT_NUMBER_GET_PORT ;                    /* IF THERE IS ANY RUNTIME ERROR , WATCH THIS VAR IN DEBUG SESSION */
		                break;				
	}	                                     /*END OF SWITCH CASE*/
}															 
/**************************************************** *********END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                                                
void GPIO_voidTogglePinValue (uint8 Copy_u8Port,
	                            uint8 Copy_u8Pin  ){                                /*TOOGLE THE VALUE OF A CERTAIN PIN*/
	
	switch (Copy_u8Port) {                                                         /*CHOOSE A CERTAIN PORT {A,B,C}*/
		
		case GPIOA :                                                          /*TOOGLE THE VALUE OF A CERTAIN PIN IN PORT A*/
			            TOGGLE_BIT (GPIOA_ODR , Copy_u8Pin) ;                            /*THE PIN = Copy_u8Pin */
			            break ;
	 case GPIOB :
		            	TOGGLE_BIT (GPIOB_ODR , Copy_u8Pin) ;                   /*TOOGLE THE VALUE OF A CERTAIN PIN IN PORT A*/
			            break ;                                                          /*THE PIN = Copy_u8Pin */
	 case GPIOC : 
		            	TOGGLE_BIT (GPIOC_ODR , Copy_u8Pin) ;                    /*TOOGLE THE VALUE OF A CERTAIN PIN IN PORT A*/
			            break ; 
                                                                                  /*THE PIN = Copy_u8Pin */
		default   :   ERROR = WRONG_PIN_NUMBER_TOGGLE_PIN ;
            			break ;	 				                                     
	}
	                                              /*END OF SWITCH CASE*/
}
/**************************************************** *********END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                                                	
 void  GPIO_voidTogglePortValue   (uint8  Copy_u8Port  ){
 
    for (uint8 PIN_NUMBER = PIN0 ; PIN_NUMBER <= PIN15 ; PIN_NUMBER++){  /*BEGIN OF LOOP AT PINS OF THE PORT*/
				
		    GPIO_voidTogglePinValue(Copy_u8Port , PIN_NUMBER);  /*SET MODE OF EACH PIN ONE BY ONE*/
		
	 }                                                /*END OF FOR LOOP*/
 }	                              
															
/**************************************************** *********END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                                                

void GPIO_voidLockPinConfig(uint8 Copy_u8Port,                          /*LOCK A CERTAIN PIN IN A CERTAIN PORT*/
	                    uint8 Copy_u8Pin   ){
	
	uint32 LCK_VALUE = CONFIG_ACTIVATED;       /*SET BIT 16 TO AVTIVATE PORT CONFIGURATION*/
	
	 switch (Copy_u8Port) {                          /*CHOOSE A CERTAIN PORT {A,B,C}*/
		
		 case GPIOA :
			 
			LCK_VALUE |=  (1 << Copy_u8Pin);               /*ACTIVATE THE CHOOSEN PIN BIT ,LCK BIT = 1 , CHOOSEN PIN = 1/
		
		                                                           /* APPLY A SEQUENCE REQUIREDE TO LOCK THE BIT ,NOTE: DONT CHANGE LCK[0:15]*/
			GPIOA_LCK = LCK_VALUE;                   /*WRITE ONE*/ 
			GPIOA_LCK =  (1 << Copy_u8Pin);         /*WRITE ZERO*/
			GPIOA_LCK = LCK_VALUE;                  /*WRITE ONE*/
  		LCK_VALUE = GPIOA_LCK;                   /*READ ONE*/
			LCK_VALUE = GPIOA_LCK;                   /*READ ZERO*/
			break ;
		
		case GPIOB :
			
			LCK_VALUE |=  (1 << Copy_u8Pin);         /*ACTIVATE THE CHOOSEN PIN BIT*/
		
		                                                           /*APPLY A SEQUENCE REQUIREDE TO LOCK THE BIT ,NOTE: DONT CHANGE LCK[0:15]*/
			GPIOB_LCK = LCK_VALUE;                   /*WRITE ONE*/ 
			GPIOB_LCK =  (1 << Copy_u8Pin);         /*WRITE ZERO*/
			GPIOB_LCK = LCK_VALUE;                  /*WRITE ONE*/
  		LCK_VALUE = GPIOB_LCK;                   /*READ ONE*/
			LCK_VALUE = GPIOB_LCK;                   /*READ ZERO*/
			
		
			break ;
		
		case GPIOC : 
			LCK_VALUE |=  (1 << Copy_u8Pin);         /*ACTIVATE THE CHOOSEN PIN BIT*/
		
		                                                           /*APPLY A SEQUENCE REQUIREDE TO LOCK THE BIT , DONT CHANGE LCK[0:15]*/
			GPIOA_LCK = LCK_VALUE;                   /*WRITE ONE*/ 
			GPIOA_LCK =  (1 << Copy_u8Pin);         /*WRITE ZERO*/
			GPIOA_LCK = LCK_VALUE;                  /*WRITE ONE*/
  		LCK_VALUE = GPIOA_LCK;                   /*READ ONE*/
			LCK_VALUE = GPIOA_LCK;                   /*READ ZERO*/
			
		  break ;
		
		default   :
       ERROR = WRONG_PIN_NUMBER_LOCK_PIN ;			
       break ;
		
	}
	                                                /*END OF SWITCH CASE*/
}
/**************************************************** *********END OF FUNCTION**************************************************************************************************************************************************************************************************************************/																                                                                
											