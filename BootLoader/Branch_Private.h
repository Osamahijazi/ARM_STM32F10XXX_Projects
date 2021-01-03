/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:29/12/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef BRANCH_PRIVATE_H
#define BRANCH_PRIVATE_H

#define  SCB_VTOR   *((volatile u32*)0xE000ED08)     /*register to degine reset vector and entry piont*/
#define  SCB_AIRCR       *((volatile uint32*)0XE000ED0C)       /*Registr  to request software reset */
#define  SOFT_RESET     0x05FA0004


#endif








