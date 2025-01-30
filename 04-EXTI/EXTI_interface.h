/*****************************************/
/*Author     : Abdelrahman Nabil         */
/*Date       : 29 OCT 2024               */
/*Version    : V01                       */
/*****************************************/


#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/*Line and Mode*/
void MEXTI_voidInit(void );
void MEXTI_voidEnableEXTI(Copy_u8Line);
void MEXTI_voidDisableEXTI(Copy_u8Line);
void MEXTI_voidSwTrigger(Copy_u8Line);
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode);

void MEXTI_voidSetCallBack(void(*ptr)(void));

#endif