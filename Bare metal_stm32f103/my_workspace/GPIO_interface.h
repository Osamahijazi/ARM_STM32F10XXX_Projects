/*****************************************************/
 /* Author      : Abdelrhman Mosad                   */
 /* Version     : v01 (Bl)                           */
 /* date        : 21/10/2020                         */
/*****************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/*********************************************************************************/
/******************************   Macros     *************************************/
/*********************************************************************************/

/************* GPIO IDS ***************/
#define 	PORTA         0
#define 	PORTB         1
#define 	PORTC         2

/********* GPIO pins number ***********/
#define     PIN0          0
#define     PIN1          1
#define     PIN2          2
#define     PIN3          3
#define     PIN4          4
#define     PIN5          5
#define     PIN6          6
#define     PIN7          7
#define     PIN8          8
#define     PIN9          9
#define     PIN10         10
#define     PIN11         11
#define     PIN12         12
#define     PIN13         13
#define     PIN14         14
#define     PIN15         15

/***************** GPIO pins mode *******************/
/*****   Input modes    *****/
#define  	GPIO_INPUT_ANALOG              0B0000 
#define 	GPIO_INPUT_FLOATING            0B0100 
#define 	GPIO_INPUT_PULL_UP_DOWN        0B1000             	
/******   Output modes   *****/
/* 10 MGZ */
#define 	GPIO_OUTPUT_10MHZ_PP           0B0001 
#define 	GPIO_OUTPUT_10MHZ_OD           0B0101 
#define 	GPIO_OUTPUT_10MHZ_AFPP         0B1001 
#define 	GPIO_OUTPUT_10MHZ_AFOD         0B1101 
/* 2  MGZ */	
#define 	GPIO_OUTPUT_2MHZ_PP            0B0010 
#define 	GPIO_OUTPUT_2MHZ_OD            0B0110 
#define 	GPIO_OUTPUT_2MHZ_AFPP          0B1010 
#define 	GPIO_OUTPUT_2MHZ_AFOD          0B1110 
/* 50 MGZ */	
#define 	GPIO_OUTPUT_50MHZ_PP           0B0011 
#define 	GPIO_OUTPUT_50MHZ_OD           0B0111 
#define 	GPIO_OUTPUT_50MHZ_AFPP         0B1011 
#define 	GPIO_OUTPUT_50MHZ_AFOD         0B1111 

/************* pins value **************/
#define     GPIO_HIGH           1
#define     GPIO_LOW            0

/************* pull types ***************/
#define     GPIO_PULL_UP        1
#define     GPIO_PULL_DOWN      0

/*********************************************************************************/
/******************************  Functions  **************************************/
/*********************************************************************************/

/*****************************************************************************
* Function       : MGPIO_voidSetPinMode()
* Description    : This function is used to initialize the GPIO pins based on the 
*                  mode the user will pass to the function .
* PRE-CONDITION  : RCC must be enabled for the GPIO peripheral 
* POST-CONDITION : None
* @param [in]    : (u8) ID of the port , (u8) number of pin , (u8) mode
* @return        :  void
* Examble        : MGPIO_voidSetPinMode (PORTA , PIN0 , GPIO_OUTPUT_2MHZ_PP );
*****************************************************************************/
void MGPIO_voidSetPinMode (u8 copyPortId , u8 copyPinNumber , u8 copyMode  );

/*****************************************************************************
* Function       : MGPIO_voidSetPinValue()
* Description    : This function is used to change the GPIO pins value 
* PRE-CONDITION  : Pin must be initialized first using GPIO_voidSetPinMode()
* POST-CONDITION : None
* @param [in]    : (u8) ID of the port , (u8) number of pin , (u8) value [ 1 or 0]
* @return        :  void
* Examble        : MGPIO_voidSetPinValue (PORTA , PIN0 , GPIO_HIGH );
*****************************************************************************/
void MGPIO_voidSetPinValue (u8 copyPortId , u8 copyPinNumber , u8 copy_u8Value);

/*****************************************************************************
* Function       : MGPIO_u8GetPinValue()
* Description    : This function is used to get the pin value in case it was input
* PRE-CONDITION  : Pin must be initialized first using GPIO_voidSetPinMode()
* POST-CONDITION : None
* @param [in]    : (u8) ID of the port , (u8) number of pin 
* @return        : (u8) Pin value [1 or 0]
* Examble        : u8 x = MGPIO_u8GetPinValue (PORTA , PIN0);
*****************************************************************************/
u8 MGPIO_u8GetPinValue (u8 copyPortId , u8 copyPinNumber);


#endif
