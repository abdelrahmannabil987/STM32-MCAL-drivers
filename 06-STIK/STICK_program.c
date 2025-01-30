/*****************************************/
/*Author     : Abdelrahman Nabil         */
/*Date       : 9 NOV 2024                */
/*Version    : V01                       */
/*****************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STICK_interface.h"
#include "STICK_config.h"
#include "STICK_private.h"

void (*pv_CallBackFunc)(void);

u8 Type_of_Asynch_Func;

void MSTICK_voidInit(void)
{
	/*Choose Clock Source*/
#if STICK_FREQ ==  AHB_DivBy_8
	STK_CTRL = 0x00000000;
#elif STICK_FREQ ==  AHB
	STK_CTRL = 0x00000004;
#endif
}

void MSTICK_voidSetBusyWait(u32 Copy_u32Ticks)
{

	/*Put #Ticks in Load Register*/
	STK_LOAD = Copy_u32Ticks;
	/*Enable SysTick*/
	SET_BIT(STK_CTRL,0);
	while((GET_BIT(STK_CTRL,16))==0);

	/*Disable SysTick*/
	CLR_BIT(STK_CTRL,0);

	/*Clear Load and Value Registers*/

	STK_LOAD=0;
	STK_VAL=0;



}

void MSTICK_voidSetIntervalSingle  (u32 Copy_u32Ticks,void (*Copy_ptr)(void))
{
	STK_LOAD = Copy_u32Ticks;
	/*Enable SysTick Interrupt*/
	SET_BIT(STK_CTRL,1);
	/*Enable SysTick*/
	SET_BIT(STK_CTRL,0);
	/*Send Func Address to Global */
	pv_CallBackFunc=Copy_ptr;
	Type_of_Asynch_Func=Interval_Single;
}

void MSTICK_voidSetIntervalPeriodic(u32 Copy_u32Ticks,void (*Copy_ptr)(void))
{
	STK_LOAD = Copy_u32Ticks;
	/*Enable SysTick Interrupt*/
	SET_BIT(STK_CTRL,1);
	/*Enable SysTick*/
	SET_BIT(STK_CTRL,0);
	/*Send Func Address to Global */
	pv_CallBackFunc=Copy_ptr;
}

void MSTICK_voidStopInterval  (void)
{
	/*Disable SysTick*/
	CLR_BIT(STK_CTRL,0);
	/*Clear Load and Value Registers*/
	STK_LOAD=0;
	STK_VAL=0;
	/*Disable SysTick Interrupt*/
	CLR_BIT(STK_CTRL,1);
}

u32 MSTICK_u32GetElapsedTime  (void)
{
     return (STK_LOAD - STK_VAL);
}

u32 MSTICK_u32GetRemainingTime(void)
{
	return STK_VAL;
}

void SysTick_Handler(void)
{
	if (Type_of_Asynch_Func==Interval_Single)
	{
		/*Disable SysTick*/
		CLR_BIT(STK_CTRL,0);
		/*Clear Load and Value Registers*/
		STK_LOAD=0;
		STK_VAL=0;
		/*Disable SysTick Interrupt*/
		CLR_BIT(STK_CTRL,1);
	}

	pv_CallBackFunc();


}
