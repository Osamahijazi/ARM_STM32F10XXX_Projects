/*******************************************************/
/*************Author: osama salah hijazi****************/
/***************Date: 5 / 8 /2020*************************/
/*************** Ver: Version 1***************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* OPTIONS:        RCC_HSE_CRYSTAL
                   RCC_HSE_RC
									 RCC_HSI
									 RCC_PLL
									 
									                  */


# define RCC_CLOCK_TYPE     RCC_HSE_CRYSTAL



/*  OPTIONS:         RCC_PLL_IN_HSI_DIV_2
                     RCC_PLL_IN_HSE_DIV_2 
                     RCC_PLL_IN_HSE

                                      */
																			
#if   (  RCC_CLOCK_TYPE == RCC_PLL )  /*select value incase of PPL input*/

   # define RCC_PLL_INPUT  RCC_PLL_IN_HSI_DIV_2
	 

#endif


/* NOTE: dONT USE HIS PAR WITHOUT USING PLL TYPE*/
                    /*OPTIONS 2 TO 16*/
										
#if   (  RCC_CLOCK_TYPE == RCC_PLL ) 
#define RCC_PLL_MAL_VAL    4
#endif









#endif
