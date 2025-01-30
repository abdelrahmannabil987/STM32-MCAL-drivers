/*****************************************/
/*Author     : Abdelrahman Nabil         */
/*Date       : 9 NOV 2024                */
/*Version    : V01                       */
/*****************************************/

#ifndef STICK_INTERFACE_H_
#define STICK_INTERFACE_H_

/*Apply Clock Choice from Config File AHB OR AHB/8
  Disable SysTick Interrupt
  Disable SysTick
  */
  void MSTICK_voidInit(void);
  
  void MSTICK_voidSetBusyWait(u32 Copy_u32Ticks);
  
  void MSTICK_voidSetIntervalSingle  (u32 Copy_u32Ticks,void (*Copy_ptr)(void));

  void MSTICK_voidSetIntervalPeriodic(u32 Copy_u32Ticks,void (*Copy_ptr)(void));

  void MSTICK_voidStopInterval  (void);

  u32 MSTICK_u32GetElapsedTime  (void);
  
  u32 MSTICK_u32GetRemainingTime(void);


#endif

