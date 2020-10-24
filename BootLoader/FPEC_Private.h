/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:16/10/2020***********************************/
/***********version:1***************************************/
/*********Description:FLASH DRIVER***********************/
/***********************************************************/
#ifndef FPEC_PRIVATE_H
#define FPEC_PRIVATE_H

#include "STD_TYPES.h"
/***********************************************************************************************************************************************************************************************************************************************************
                                                   *******FLASH Registers Definition**********
***********************************************************************************************************************************************************************************************************************************************************/
typedef struct {
	
	          uint32 FLASH_ACR ;
	          uint32 FLASH_KEYR ;
	          uint32 FLASH_OPTKEYR ;
	          uint32 FLASH_SR ;
	          uint32 FLASH_CR ;
	          uint32 FLASH_AR ;
	          uint32 RESERVED ;
         	  uint32 FLASH_OBR ;
	          uint32 FLASH_WRPR ;
}FPEC_TYPE ;

#define   FPEC   ((volatile FPEC_TYPE *)0x40022000)  /*CREATE PIONTER TO FPEC STRUCTURE INCREMENT BY 4BYTE*/
/***********************************************************************************************************************************************************************************************************************************************************
                                                           *******REGISTERS BITS PRIVATE MACROS**********
***********************************************************************************************************************************************************************************************************************************************************/																																										 
                                                                  /*FLASH_SR PRIVATE BITS*/

#define   BUS         0                 /*SET IN THE BEGIN OF OPERATION AND RESET AT END*/
#define   PG_ERR            2                 /*PROGRAMMING ERROR*/
#define   WR_PRT_ERR        4                /*WRITE PROTECTION ERROR*/ 
#define   OP_END            5                /*END OF OPERATION*/

                                                                  /*FLASH_CR PRIVATE BITS*/

#define   PG            0                 /*Flash programming chosen*/
#define   PER           1                 /*Page Erase chosen*/
#define   MER           2                 /*Erase of all user pages chosen*/
#define   OPTPG         4                 /*Option byte programming choosen*/
#define   OPTER         5                 /*Option byte erase chosen*/
#define   STRT          6                 /*This bit triggers an ERASE operation when set*/
#define   LOCK          7                 /* LOCK FPEC and FLASH_CR when it is set*/
#define   OPTWRE        9                 /*Option bytes write enable */
#define   ERRIE         10                 /*Error interrupt enable*/
#define   EOPIE         12                 /*End of operation interrupt enable*/

                                                                  /*FLASH LOCK KEY VALUE*/

#define   RDPRT_key     0x00A5
#define   FPEC_KEY1     0x45670123  /* TWO KEYS MUST APPLIED IN A CERTAIN SEQUENCE TO UN LOCK FLASH BLOCK*/
#define   FPEC_KEY2     0xCDEF89AB

                                                                    /*CHECK  MACROS*/
#define  WRITE_SUCCES      1																																		
#define  WRITE_FAILED      1			
#define  FIRST_PAGE_BASE   0x08000000
# define PAGE_SIZE         1024
#define  WAIT_FLASH        BIT_IS_SET(FPEC->FLASH_SR,BUS)
#define  LOCK_IS_SET       BIT_IS_SET(FPEC->FLASH_CR,LOCK )
																																		




























#endif
/**************************************************************END OF FILE*********************************************************************************************************************************************************************/
