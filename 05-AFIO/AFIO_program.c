/*****************************************/
/*Author     : Abdelrahman Nabil         */
/*Date       : 29 OCT 2024               */
/*Version    : V01                       */
/*****************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_condfig.h"
#include "AFIO_private.h"

void MAFIO_voidSetExtiConfiguration(u8 Copy_u8Line , u8 Copy_u8PortMap)
{
	u8 Local_u8RegisterIndex = 0;
	
	if(Copy_u8Line <=3)
	{
		Local_u8RegisterIndex = 0;
	}	
	else if(Copy_u8Line <=7)
	{
		Local_u8RegisterIndex = 1;
		Copy_u8Line -= 4;
	}	
	if(Copy_u8Line <=11)
	{
		Local_u8RegisterIndex = 2;
		Copy_u8Line -= 8;
	}	
	if(Copy_u8Line <=15)
	{
		Local_u8RegisterIndex = 3;
		Copy_u8Line -= 12;
	}	
	AFIO_AFIO_EXTICR[Local_u8RegisterIndex] &~= ((0b1111) << (Copy_u8Line * 4));
	AFIO_AFIO_EXTICR[Local_u8RegisterIndex] |= ((Copy_u8PortMap) << (Copy_u8Line * 4));

}