/*****************************************/
/*Author     : Abdelrahman Nabil         */
/*Date       : 31 OCT 2024               */
/*Version    : V01                       */
/*****************************************/


#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

//0xE000E100 Base Address
#define BASE_ADDRESS 

#define NVIC_ISER0   *((u32*)0xE000E100)   /*Enable External Interrupts from 0 to 31 */
#define NVIC_ISER1   *((u32*)0xE000E104)   /*Enable External Interrupts from 32 to 63*/

#define NVIC_ICER0   *((u32*)0xE000E180)  /*Disable External Interrupts from 0 to 31 */
#define NVIC_ICER1   *((u32*)0xE000E184)  /*Disable External Interrupts from 32 to 63*/

#define NVIC_ISPR0   *((u32*)0xE000E200) /*Enable Pending Flag  from 0 to 31  */
#define NVIC_ISPR1   *((u32*)0xE000E204) /*Enable Pending Flag  from 32 to 63*/


#define NVIC_ICPR0   *((u32*)0xE000E280) /*Disable Pending Flag  from 0 to 31  */
#define NVIC_ICPR1   *((u32*)0xE000E284) /*Disable Pending Flag  from 32 to 63*/

#define NVIC_IABR0   *((volatile u32*)0xE000E300) /*Active Bit*/
#define NVIC_IABR1   *((volatile u32*)0xE000E304)


#define  MNVIC_4_GROUPS_0_SUB     0x05FA0300
#define  MNVIC_3_GROUPS_1_SUB     0x05FA0400
#define  MNVIC_2_GROUPS_2_SUB     0x05FA0500
#define  MNVIC_1_GROUPS_3_SUB     0x05FA0600
#define  MNVIC_0_GROUPS_4_SUB     0x05FA0700


#define NVIC_IPR      ((u8*)0xE000E400)  /*Ptr of u8 to base address to access byte by byte (interupt by interupt)*/


#endif
