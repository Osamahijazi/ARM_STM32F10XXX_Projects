/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:26/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

#include "STD_TYPES.h"
/***********************************************************************************/
                      /***Registers Defentions***/
/***********************************************************************************/						
 
/**
* Define STK Registers To manage and Control registers        
**/ 
typedef struct{  
  
          u32 CTRL ;        /* CTRL register enables STK features.*/
	        u32 LOAD ;        /* LOAD register specifies the start value to load into the VAL register*/
	        u32 VAL  ;	      /* VAL register contains the current value counter*/
	        u32 CALIB;        /* CALIB register indicates calibration properties.*/
}STK_TYPE;


/**
* STK ; Creating Pionter To Structure To Enable 
*       Access to STK register
**/

#define  STK    ((volatile STK_TYPE*) 0xE000E010)  
	
/***********************************************************************************/
                      /***Private Macros***/
/***********************************************************************************/						
                                       /*CTRL*/
/**
* STK_Init: Init config of STK
* EN      : enable bit of STK
* INT_EN  : enable bit of STK interrupt
* CLK     : Set bit of STK Clock
**/
#define   STK_Init                 0
#define   EN                       0
#define   INT_EN                   1
#define   CLK                      2


                                                     

#endif
