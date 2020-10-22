/************************************************/
/******Author: osama salah hijazi****************/
/******Date: 5 / 8 /2020*************************/
/****** Ver: Version 1***************************/
#include "STD_TYPES.h"
#include "MATH_BIT.h"
#include "RCC_private.h"
#include "RCC_interface.h"
#include "RCC_config.h"




void RCC_InitysClock(void){


 #if       (RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL)
	
	           RCC_CR   = 0X00010000 ;/*EXTERNAL WITHOUT BYPASS*/
	           RCC_CFGR = 0X00000001 ;
	           
	
 #elif     (RCC_CLOCK_TYPE == RCC_HSE_RC)
	
	           RCC_CR   = 0X00050000 ;
		         RCC_CFGR = 0X00000001 ;

	
 #elif     (RCC_CLOCK_TYPE == RCC_HSI)
	
	            RCC_CR   = 0X00000081 ;/*ENABLE HSI*/
		          RCC_CFGR = 0X00000000 ;

	
	
	#elif     (RCC_CLOCK_TYPE == RCC_PLL)
	
	                          /*adtusting MUl bits*/
								 RCC_CFGR|= ((RCC_PLL_MAL_VAL - 2 ) >> 17 ) ; 
	
	      #if  (RCC_PLL_INPUT ==  RCC_PLL_IN_HSI_DIV_2)
				 
				      SET_BIT(RCC_CFGR,16);
				 
        #elif  (RCC_PLL_INPUT ==  RCC_PLL_IN_HSE_DIV_2) 
				
              SET_BIT(RCC_CFGR,17);
						 
        #elif  (RCC_PLL_INPUT ==   RCC_PLL_IN_HSE )
				
              CLEAR_BIT(RCC_CFGR,17);
	
	      #endif
				
                SET_BIT(RCC_CR,24);  /*Turning PLL on */
	              SET_BIT(RCC_CFGR,1);   /*PLL selected as system clock*/


 #else 
 
	    #error("you chosed wrong clock type")
	
	#endif
	



}




























void RCC_VoidEnableClock(uint8 Copy_u8BusId , uint8 Copy_u8PerId ){
	 
	
	if (Copy_u8PerId <= 31){

     switch(Copy_u8BusId)
		 { 
			 case   RCC_AHB :  SET_BIT( RCC_AHBENR , Copy_u8PerId);     break;
			 
     	 case   RCC_APB1 : SET_BIT( RCC_APB1ENR , Copy_u8PerId);    break;
		 
		 	 case   RCC_APB2 : SET_BIT( RCC_APB2ENR , Copy_u8PerId);    break;
			 
			 default :           /*RETURN ERROR*/                         break ; 

		 }
		 
		 }

		 else
		 {
		 
		                           /* return error*/
		 }
		 
	 }

		 void RCC_VoidDisableClock(uint8 Copy_u8BusId , uint8 Copy_u8PerId ){
	
	
	if (Copy_u8PerId <= 31){

     switch(Copy_u8BusId)
		 {
			 case    RCC_AHB :  CLEAR_BIT( RCC_AHBENR , Copy_u8PerId);       break;
			 
     	 case    RCC_APB1 : CLEAR_BIT( RCC_APB1ENR , Copy_u8PerId);      break;
		 
		 	 case    RCC_APB2 : CLEAR_BIT( RCC_APB2ENR , Copy_u8PerId);      break;
			 
			 default :                /*RETURN ERROR*/                     break ; 

		 }
		 
		 }

		 else
		 {
		 
		          /* return error*/
		 }
		 
		 
	 }
		 
	 
