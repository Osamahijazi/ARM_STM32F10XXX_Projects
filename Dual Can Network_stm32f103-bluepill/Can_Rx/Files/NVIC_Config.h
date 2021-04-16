/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:20/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/
#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H
 /***********************************************************************************************************************************************************************************************************************************************************/
                              /*CHOICES FOR GROUP AND SUB PRIORITIES*/
 
 /* CHOICES:   
                NVIC_GROUP_4_SUB_0      0X05FA0300        4 BITS for Group & 0 Bit for sub Group ,16 Group,0 Sub Group      
                NVIC_GROUP_3_SUB_1      0X05FA0400        3 BITS for Group & 1 BIT for sub Group ,8 Group, 1 Sub Group
                NVIC_GROUP_2_SUB_2      0X05FA0500        2 BITS for Group & 2 BIT for sub Group ,4 Group, 4 Sub Group
                NVIC_GROUP_1_SUB_3      0X05FA0600        1 BITS for Group & 3 BIT for sub Group ,2 Group, 0 Sub Group
                NVIC_GROUP_0_SUB_4      0X05FA0700        0 BITS for Group & 4 BIT for sub Group ,16 Group,0 Sub Group*/ 

#define  GROUP_SUB_PRIOROTY_DISTRIBUTION     NVIC_GROUP_2_SUB_2          /*choose group and sub group distribution*/
/***********************************************************************************************************************************************************************************************************************************************************/
                            /* GROUP OR SUB GROUP PRIORITIES AVAILABLE OF 4BITS OF EACH INTERRUPT OF PERIPHERAL */
/* CHOICES:
#define INTERRUPT_PRIOPITY_0       0
#define INTERRUPT_PRIOPITY_1       1
#define INTERRUPT_PRIOPITY_2       2
#define INTERRUPT_PRIOPITY_3       3
#define INTERRUPT_PRIOPITY_4       4
#define INTERRUPT_PRIOPITY_5       5
#define INTERRUPT_PRIOPITY_6       6
#define INTERRUPT_PRIOPITY_7       7
#define INTERRUPT_PRIOPITY_8       8
#define INTERRUPT_PRIOPITY_9       9
#define INTERRUPT_PRIOPITY_10      10
#define INTERRUPT_PRIOPITY_11      11
#define INTERRUPT_PRIOPITY_12      12
#define INTERRUPT_PRIOPITY_13      13
#define INTERRUPT_PRIOPITY_14      14
#define INTERRUPT_PRIOPITY_15      15 */

#define  GROUP_PRIOROTY_NUMBER                INTERRUPT_PRIOPITY_1          /*choose group and sub group distribution*/
#define  SUB_GROUP_PRIOROTY_NUMBER            INTERRUPT_PRIOPITY_1          /*choose group and sub group distribution*/
/***********************************************************************************************************************************************************************************************************************************************************/




#endif 
/**************************************************************END OF FILE*********************************************************************************************************************************************************************/
