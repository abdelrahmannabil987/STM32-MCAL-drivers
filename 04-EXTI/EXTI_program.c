/*****************************************/
/*Author     : Abdelrahman Nabil         */
/*Date       : 29 OCT 2024               */
/*Version    : V01                       */
/*****************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_condfig.h"
#include "EXTI_private.h"

static void(*EXTI0_CallBack)(void)=NULL;

void MEXTI_voidInit()
{
	/*check Mode and Line*/
	#if EXTI_MODE == RISING_EDGE
	SET_BIT(EXTI -> EXTI_RTSR , EXTI_LINE);
	#elif EXTI_MODE == FALLING_EDGE
	SET_BIT(EXTI -> EXTI_FTSR , EXTI_LINE);
	#elif EXTI_MODE == ON_CHANGE
	SET_BIT(EXTI -> EXTI_RTSR , EXTI_LINE);
	SET_BIT(EXTI -> EXTI_FTSR , EXTI_LINE);
	#else 
		#error ("Wrong Mode and line Choice") 
	#endif
	/*Disable interrupt to not depend on default value*/
	CLR_BIT(EXTI -> EXTI_IMR , EXTI_LINE);

}
void MEXTI_voidEnableEXTI(Copy_u8Line)
{
	SET_BIT(EXTI -> EXTI_IMR , EXTI_LINE);
}     
void MEXTI_voidDisableEXTI(Copy_u8Line)
{
	CLR_BIT(EXTI -> EXTI_IMR , EXTI_LINE);
}
/*
void MEXTI_voidSwTrigger(Copy_u8Line)//firing interrupt by SW even the interrupt didn't come
{
	SET_BIT(EXTI -> EXTI_SWIER , EXTI_LINE);
}*/  
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode)//better to use more Lines with different Modes or change mode during Runtime
{
	SET_BIT(EXTI -> EXTI_IMR , EXTI_LINE); 
	switch(Copy_u8Mode)
	{
		case RISING_EDGE  :	SET_BIT(EXTI -> EXTI_RTSR , EXTI_LINE);break;
		case FALLING_EDGE : SET_BIT(EXTI -> EXTI_FTSR , EXTI_LINE);break;
		case ON_CHANGE    : SET_BIT(EXTI -> EXTI_RTSR , EXTI_LINE); 
		                    SET_BIT(EXTI -> EXTI_FTSR , EXTI_LINE);break;
	}
}




void MEXTI_voidSetCallBack(void(*ptr)(void))
{
	EXTI0_CallBack = ptr;
	 
}


void EXTI0 _IRQHandler(void)
{
	EXTI0_CallBack();
	SET_BIT(EXTI -> EXTI_PR , 0 )//clear Pending bit of EXTI0(Line 0)
}