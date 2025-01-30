/*****************************************/
/*Author     : Abdelrahman Nabil         */
/*Date       : 22 OCT 2024               */
/*Version    : V01                       */
/*****************************************/


#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*options : RCC_HSE_CRYSTAL
            RCC_HSE_RC
			RCC_HSI
			RCC_PLL         */
#define RCC_CLOCK_TYPE  RCC_HSE_CRYSTAL




/*Options : RCC_PLL_IN_HSI_DIV_2
			RCC_PLL_IN_HSE_DIV_2
			RCC_PLL_IN_HSE      */
/*Select Value only if you have PLL as Input Clock Source */
#if RCC_CLOCK_TYPE == RCC_PLL

#define RCC_PLL_INPUT  RCC_PLL_IN_HSE_DIV_2

/*Options 2 to 16*/
#define  PLL_MUL_VALUE  4

#endif



#endif