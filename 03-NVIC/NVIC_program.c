/*****************************************/
/*Author     : Abdelrahman Nabil         */
/*Date       : 31 OCT 2024               */
/*Version    : V01                       */
/*****************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidInit(void)
{
	#define SCB_AIRCR    *((u32*)0xE000ED0C)  /*System Control Block*/
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}

void MNVIC_voidSetPriority(u8 Copy_u8PeripheralIdx,u8 Copy_u8Priority)
{
	if (Copy_u8PeripheralIdx < 60)
	{ 
		NVIC_IPR[Copy_u8PeripheralIdx]=Copy_u8Priority;
	}
	else
	{
		/*Report Error*/
	}
	
}



void MNVIC_voidEnableInterrupt(u8 Copy_u8InterruptNumber)
{
	if (Copy_u8InterruptNumber <=31)//u8 so ofcourse it's bigger than or equal 0
	{
		//SET_BIT(NVIC_ISER0,Copy_u8InterruptNumber) too much operations
		NVIC_ISER0 = (1 << Copy_u8InterruptNumber); // 0 has no effect
	}
	else if (Copy_u8InterruptNumber <=59)//59 external interrupts in ST
	{
		Copy_u8InterruptNumber -= 32;
		NVIC_ISER1 = (1 << Copy_u8InterruptNumber);
	}
	else 
	{
		//Return Error
	}
}


void MNVIC_voidDisableInterrupt(u8 Copy_u8InterruptNumber)
{
	if (Copy_u8InterruptNumber <=31)
	{
		NVIC_ICER0 = (1 << Copy_u8InterruptNumber);
	}
	else if (Copy_u8InterruptNumber <=59)
	{
		Copy_u8InterruptNumber -= 32;
		NVIC_ICER1 = (1 << Copy_u8InterruptNumber);
	}
	else 
	{
		//Return Error
	}
}




void MNVIC_voidSetPendingFlag(u8 Copy_u8InterruptNumber)
{
	if (Copy_u8InterruptNumber <=31)
	{
		NVIC_ISPR0 = (1 << Copy_u8InterruptNumber); 
	}
	else if (Copy_u8InterruptNumber <=59)
	{
		Copy_u8InterruptNumber -= 32;
		NVIC_ISPR1 = (1 << Copy_u8InterruptNumber);
	}
	else 
	{
		//Return Error
	}
} 



void MNVIC_voidDisablePendingFlag(u8 Copy_u8InterruptNumber)
{
	if (Copy_u8InterruptNumber <=31)
	{
		NVIC_ICPR0 = (1 << Copy_u8InterruptNumber); 
	}
	else if (Copy_u8InterruptNumber <=59)
	{
		Copy_u8InterruptNumber -= 32;
		NVIC_ICPR1 = (1 << Copy_u8InterruptNumber);
	}
	else 
	{
		//Return Error
	}
} 




u8 MNVIC_u8GetActiveFlag(u8 Copy_u8InterruptNumber)
{
	u8 Local_u8Result=0;
	if (Copy_u8InterruptNumber <=31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0,Copy_u8InterruptNumber);
	}
	else if (Copy_u8InterruptNumber <=59)
	{
		Copy_u8InterruptNumber -= 32;
		Local_u8Result = GET_BIT(NVIC_IABR1,Copy_u8InterruptNumber);
	}
	else 
	{
		//Return Error
	}
	return Local_u8Result;
} 


/*
void MNVIC_voidSetPriority(s8 Copy_s8InterruptID , u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority , u32 Copy_u8Group)
{
	u8 Local_u8Periority = Copy_u8SubPriority|Copy_u8GroupPriority<<((Copy_u32Group - 0x05FA0300)/256);
	// Core prepheral
	
	// External prepheral  ex: 6-EXTI
	if(Copy_s8InterruptID >= 0)
	{
		IPR[Copy_s8InterruptID]=Local_u8Periority << 4;
	}
	SCB_AIRCR = Copy_u8Group;
} 

*/

