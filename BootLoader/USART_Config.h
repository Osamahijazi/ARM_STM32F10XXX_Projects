/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:26/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef  USART_CONFIG_H
#define  USART_CONFIG_H

/***********************************************************************************************************************************************************************************************************************************************************/
                                              /*BRR REGISTER CONFIGURATION*/
																							
																			 /*  THIS CALCULATION ARE MADE FOR 8MHZ
																			 
																			 BRR Register Value :"SPEED_9600,SPEED_4800,SPEED_9600" 
																			                                                          */
#define   BUAD_RATE               SPEED_4800              																																			
																							
												
/***********************************************************************************************************************************************************************************************************************************************************/
                                              /*CR1 REGISTER CONFIGURATION*/

#define    USART1_ENABLE                     ENABLE                               /*ENABLE USART*/
                                                                  /*Choose parity mode "ENABLE OR DISABLE"*/       
#define    PARITY_CONTROL_BIT               DISABLE

#define    PARITY_SELECTION                 ODD                      /*Choose parity selection "odd or even"*/

#define    USART1_TRANS_MODE                ENABLE                /*CHOOSE ENABLE  TO TURN USART AS TRANSMITTER*/

#define    USART1_RECEIV_MODE               ENABLE                 /*CHOOSE ENABLE  TO TURN USART AS RECEIVER */

#define    TRANS_INTERRUPT_ENABLE           DISABLE                   /*TRANSMISSION COMPLETE INTERRRUPT*/

#define    RECEIVE_INTERRUPT_ENABLE         DISABLE                    /*TRECEIVE COMPLETE INTERRRUPT*/

/***********************************************************************************************************************************************************************************************************************************************************/
                                              /*CR2 REGISTER CONFIGURATION*/


#define       STOP_BIT_NUMBER                ONE                   /*STOP BIT NUMBER ---> "ONE  OR TWO"*/

#define       CLOCK_ENABLE                 ENABLE                           /*CLOCK ENABLE */

#define       CLOCK_POLARITY                LOW            /*CLOCK POLARITY : LOW:IDL EDGE IS FALLING IT WORK AT RAISING EDGE
                                                                             HIGH: THE TRANSMIT BEGIN AT RAISING EDGE        
																																								                                          */    
#define       CLOCK_PHASE                   HIGH					 /*CLOCK PHASE :LOW:The first clock transition is the first data capture edge
                                                                          HIGH: the second clock transition is the first data capture edge.        
																																								                                          */																																																					
/***********************************************************************************************************************************************************************************************************************************************************/
                                              /*CR3 REGISTER CONFIGURATION*/

#define       DMA_RECEIVER_ENABLE                DISABLE                  /*DIRECT RECEIVE TO MEMORY ENABLE OR DISABLE"*/

#define       DMA_TRANSMIT_ENABLE                DISABLE                  /*DIRECT TRANSMIT TO MEMORY ENABLE OR DISABLE"*/

#define       ERROR_INTERRUPT_ENABLE             DISABLE                       /*INTERRUPT ENABLE ENABLE OR DISABLE*/








#endif