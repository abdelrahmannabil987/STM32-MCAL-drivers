/*****************************************/
/*Author     : Abdelrahman Nabil         */
/*Date       : 22 OCT 2024               */
/*Version    : V01                       */
/*****************************************/

/*no header file guard becuse no one includes c file*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSystemClock(void)
{
	#if   RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR   = 0x00010000;/* Enable HSE WITH NO BYPASS */
		RCC_CFGR = 0x00000001;	
	
	#elif RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR   = 0x00050000;/* Enable HSE WITH BYPASS */
		RCC_CFGR = 0x00000001;
	
	#elif RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR   = 0x00000081; /* Enable HSI + trimming = 16 (default value)*/
		RCC_CFGR = 0x00000000;
	
	#elif RCC_CLOCK_TYPE == RCC_PLL //Assignment
	#if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
	
	#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
	
	#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
	
	#endif

	#else 
		#error("You chosed Wrong CLK Type") 
	#endif
}

void RCC_voidEnableClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID)
{
	if(Copy_u8PeripheralID <= 31)
	{
		switch (Copy_u8BusID)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR, Copy_u8PeripheralID); break ;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR,Copy_u8PeripheralID); break ;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR,Copy_u8PeripheralID); break ;
			//default       : /* Return Error */ break;
		}
	}
	else 
	{
		/* Return Error */
	}
}



void RCC_voidDisableClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID)
{
	if(Copy_u8PeripheralID <= 31)
	{
		switch (Copy_u8BusID)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR, Copy_u8PeripheralID); break ;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR,Copy_u8PeripheralID); break ;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR,Copy_u8PeripheralID); break ;
			//default       : /* Return Error */ break;
		}
	}
	else 
	{
		/* Return Error */
	}
}