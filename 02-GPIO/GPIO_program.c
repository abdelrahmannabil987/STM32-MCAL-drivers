/*****************************************/
/*Author     : Abdelrahman Nabil         */
/*Date       : 24 OCT 2024               */
/*Version    : V01                       */
/*****************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"



void MGPIO_voidSetPinDirection(u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8MODE)
{
	switch(Copy_u8PORT)
	{
		case GPIOA :
					if(Copy_u8PIN <= 7)
					{
			         GPIOA_CRL  &= ~((0b1111)<< (Copy_u8PIN*4)); //clear the 4 bits of the pin before writing the mode of it 
				     GPIOA_CRL  |= ((Copy_u8MODE)<< (Copy_u8PIN*4));
					}
					else if(Copy_u8PIN <= 15)
					{
					 Copy_u8PIN-=8;//to start from zero in the register
			         GPIOA_CRH  &= ~((0b1111)<< (Copy_u8PIN*4));
				     GPIOA_CRH  |= ((Copy_u8MODE)<< (Copy_u8PIN*4));
					}
					break;
		case GPIOB :
					if(Copy_u8PIN <= 7)
					{
			         GPIOB_CRL  &= ~((0b1111)<< (Copy_u8PIN*4));
				     GPIOB_CRL  |= ((Copy_u8MODE)<< (Copy_u8PIN*4));
					}
					else if(Copy_u8PIN <= 15)
					{
					 Copy_u8PIN-=8;
			         GPIOB_CRH  &= ~((0b1111)<< (Copy_u8PIN*4));
				     GPIOB_CRH  |= ((Copy_u8MODE)<< (Copy_u8PIN*4));
					}
					break;
		case GPIOC :
					if(Copy_u8PIN <= 7)
					{
			         GPIOC_CRL  &= ~((0b1111)<< (Copy_u8PIN*4));
				     GPIOC_CRL  |= ((Copy_u8MODE)<< (Copy_u8PIN*4));
					}
					else if(Copy_u8PIN <= 15)
					{
					 Copy_u8PIN-=8;
			         GPIOC_CRH  &= ~((0b1111)<< (Copy_u8PIN*4));
				     GPIOC_CRH  |= ((Copy_u8MODE)<< (Copy_u8PIN*4));
					}
					break;
		default : break;
	}
	
}

void MGPIO_voidSetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Value)
{
	switch(Copy_u8PORT)
	{
		case GPIOA : 
					if(Copy_u8Value == GPIO_HIGH)
					{
						SET_BIT(GPIOA_ODR,Copy_u8PIN);
					}
					else if(Copy_u8Value == GPIO_LOW)
					{
						CLR_BIT(GPIOA_ODR,Copy_u8PIN);
					}
					break;
		case GPIOB : 
					if(Copy_u8Value == GPIO_HIGH)
					{
						SET_BIT(GPIOB_ODR,Copy_u8PIN);
					}
					else if(Copy_u8Value == GPIO_LOW)
					{
						CLR_BIT(GPIOB_ODR,Copy_u8PIN);
					}
					break;
		case GPIOC : 
					if(Copy_u8Value == GPIO_HIGH)
					{
						SET_BIT(GPIOC_ODR,Copy_u8PIN);
					}
					else if(Copy_u8Value == GPIO_LOW)
					{
						CLR_BIT(GPIOC_ODR,Copy_u8PIN);
					}
					break;
		default :break;
	}
}

u8 MGPIO_voidGetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN )
{
	u8 Local_u8Result=0;
	switch(Copy_u8PORT)
	{
		case GPIOA : Local_u8Result = GET_BIT(GPIOA_IDR,Copy_u8PIN);break;			
		case GPIOB : Local_u8Result = GET_BIT(GPIOB_IDR,Copy_u8PIN);break;		
		case GPIOC : Local_u8Result = GET_BIT(GPIOC_IDR,Copy_u8PIN);break;			
		default :break;
	}
	return Local_u8Result;
	
	
}

