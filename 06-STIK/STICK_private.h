/*****************************************/
/*Author     : Abdelrahman Nabil         */
/*Date       : 9 NOV 2024                */
/*Version    : V01                       */
/*****************************************/

#ifndef STICK_PRIVATE_H_
#define STICK_PRIVATE_H_


#define AHB		     1
#define AHB_DivBy_8  2


#define   STK_CTRL               *((volatile u32*)0xE000E010)
#define   STK_LOAD               *((volatile u32*)0xE000E014)
#define   STK_VAL                *((volatile u32*)0xE000E018)

#define Interval_Single    1
#define Interval_Periodic  2


#endif
