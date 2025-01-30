/*****************************************/
/*Author     : Abdelrahman Nabil         */
/*Date       : 29 OCT 2024               */
/*Version    : V01                       */
/*****************************************/


#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

typedef struct{
	volatile u32 EXTI_IMR;
	volatile u32 EXTI_EMR;
	volatile u32 EXTI_RTSR;
	volatile u32 EXTI_FTSR;
	volatile u32 EXTI_SWIER;
	volatile u32 EXTI_PR;
	
}EXTI_t;


#define EXTI ((volatile EXTI_t *)0x40010400) //pointer to a struct //0x4001 0400 +> Base Address 


#define LINE0  0
#define LINE1  1
#define LINE2  2 
/*....
  ....
  ....
  to LINE 15*/


#define RISING_EDGE    1
#define FALLING_EDGE   3
#define ON_CHANGE      5
#endif