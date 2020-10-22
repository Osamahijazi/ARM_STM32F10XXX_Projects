/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:22/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/
 
#include "STD_TYPES.h"
#include "MATH_BIT.h"
#include "AFIO_Interface.h"
#include "AFIO_Config.h"
#include "AFIO_Private.h"


void  AFIO_VoidSetEXTIConfig( uint8 Copy_uint8Line , uint8 Copy_uint8PortMap){

uint8 Local_uint8RegIndex ;
	
	                                    /* Choosing The Register according to Chosen Line */

	if      (Copy_uint8Line <= 3 ){
	
	Local_uint8RegIndex = 0 ;   /* The Line allocate in First Register*/
	
	}
	
	else if (Copy_uint8Line <= 7){
	
	Local_uint8RegIndex = 1 ;  /* The Line allocate in second Register*/
	 Copy_uint8Line -= 4 ;
	
	}
	
	else if (Copy_uint8Line <= 11){
	
	Local_uint8RegIndex = 2 ;  /* The Line allocate in third Register*/
	 Copy_uint8Line -= 8 ;
	
	}
	
	else if (Copy_uint8Line <= 15){
	
	Local_uint8RegIndex = 3 ;  /* The Line allocate in forth Register*/
	 Copy_uint8Line -= 12 ;
	
	}
	
AFIO->EXTICR[Local_uint8RegIndex] &=~ ((0b1111) << (Copy_uint8Line * 4) ); /*Masking 4 bits for the chosen Line*/
AFIO->EXTICR[Local_uint8RegIndex] |=  ((Copy_uint8PortMap) << (Copy_uint8Line * 4) );





}
