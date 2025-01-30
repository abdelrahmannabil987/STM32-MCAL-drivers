/*****************************************/
/*Author     : Abdelrahman Nabil         */
/*Date       : 31 OCT 2024               */
/*Version    : V01                       */
/*****************************************/


#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_HNVIC_PRIVATE_H

void MNVIC_voidEnableInterrupt    (u8 Copy_u8InterruptNumber);
void MNVIC_voidDisableInterrupt   (u8 Copy_u8InterruptNumber);
void MNVIC_voidSetPendingFlag     (u8 Copy_u8InterruptNumber);
void MNVIC_voidDisablePendingFlag (u8 Copy_u8InterruptNumber);
u8 MNVIC_u8GetActiveFlag          (u8 Copy_u8InterruptNumber);
void MNVIC_voidInit(void);
void MNVIC_voidSetPriority(u8 Copy_u8PeripheralIdx,u8 Copy_u8Priority);


//void MNVIC_voidSetPriority(s8 Copy_s8InterruptID , u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority , u32 Copy_u8Group);
/*
#define  GROUP3   0x05FA0300 // 4 bits for group (IPR) => group
#define  GROUP4   0x05FA0400 // 3 bits for group and 1 bit for sub (IPR)
#define  GROUP5   0x05FA0500 // 2 bits for group and 2 bit for sub (IPR)
#define  GROUP6   0x05FA0600 // 1 bits for group and 3 bit for sub (IPR)
#define  GROUP7   0x05FA0700 // 0 group and 4 bit for sub (IPR)

*/

/*All External interrupts that NVIC can control them
 * Enable - Disable - Set Pending Flag - Clear Pending Flag , Set SW priority */

#define   WWDG                     0
#define   PVD                      1
#define   TAMPER                   2
#define   RTC                      3
#define   FLASH                    4
#define   RCC                      5
#define   EXTI0                    6
#define   EXTI1                    7
#define   EXTI2                    8
#define   EXTI3                    9
#define   EXTI4                    10
#define   DMA1_Channel1            11
#define   DMA1_Channel2            12
#define   DMA1_Channel3            13
#define   DMA1_Channel4            14
#define   DMA1_Channel5            15
#define   DMA1_Channel6            16
#define   DMA1_Channel7            17
#define   ADC1_2                   18
#define   USB_HP_CAN_TX            19
#define   USB_LP_CAN_RX0           20
#define   CAN_RX1                  21
#define   CAN_SCE                  22
#define   EXTI9_5                  23
#define   TIM1_BRK                 24
#define   TIM1_UP                  25
#define   TIM1_TRG_COM             26
#define   TIM1_CC                  27
#define   TIM2                     28
#define   TIM3                     29
#define   TIM4                     30
#define   I2C1_EV                  31
#define   I2C1_ER                  32
#define   I2C2_EV                  33
#define   I2C2_ER                  34
#define   SPI1                     35
#define   SPI2                     36
#define   USART1                   37
#define   USART2                   38
#define   USART3                   39
#define   EXTI15_10                40
#define   RTCAlarm                 41
#define   USBWakeup                42
#define   TIM8_BRK                 43
#define   TIM8_UP                  44
#define   TIM8_TRG_COM             45
#define   TIM8_CC                  46
#define   ADC3                     47
#define   FSMC                     48
#define   SDIO                     49
#define   TIM5                     50
#define   SPI3                     51
#define   UART4                    52
#define   UART5                    53
#define   TIM6                     54
#define   TIM7                     55
#define   DMA2_Channel1            56
#define   DMA2_Channel2            57
#define   DMA2_Channel3            58
#define   DMA2_Channel4_5          59



#endif
