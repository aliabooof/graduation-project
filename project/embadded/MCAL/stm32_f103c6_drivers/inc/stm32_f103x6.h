/*
 * stm32_f103x6.h
 *
 *  Created on: Dec 22, 2022
 *      Author: aliab
 */

#ifndef INC_STM32_F103X6_H_
#define INC_STM32_F103X6_H_

//-----------------------------
//Includes
//-----------------------------
#include <stdlib.h>
#include <stdint.h>


//-----------------------------
//Base addresses for Memories
//-----------------------------

#define Flash_Memory_BASE 						0x08000000UL
#define System_Memory_BASE						0x1FFFF000UL
#define SRam_BASE								0x20000000UL

#define Peripherals_BASE						0x40000000UL
#define Cortex_m3_Internal_peripherals_BASE		0xE0000000UL

//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------

#define RCC_BASE		0x40021000UL

//*****

//-----------------------------
//Base addresses for APB1 Peripherals
//-----------------------------

//TIMERS
#define TIM2_BASE								(Peripherals_BASE + 0x00000000UL)
#define TIM3_BASE								(Peripherals_BASE + 0x00000400UL)
#define TIM4_BASE								(Peripherals_BASE + 0x00000800UL)
#define TIM5_BASE								(Peripherals_BASE + 0x00000C00UL)
#define TIM6_BASE								(Peripherals_BASE + 0x00001000UL)
#define TIM7_BASE								(Peripherals_BASE + 0x00001400UL)
#define TIM12_BASE								(Peripherals_BASE + 0x00001800UL)
#define TIM13_BASE								(Peripherals_BASE + 0x00001C00UL)
#define TIM14_BASE								(Peripherals_BASE + 0x00002000UL)



//*****
///Base addresses for APB2 Peripherals

//GPIO

//GPIO A and GPIO B are totally included in LQFP48 package
#define GPIOA_BASE		0x40010800UL
#define GPIOB_BASE		0x40010C00UL

//GPIO C and GPIO D are partially included in LQFP48 package
#define GPIOC_BASE		0x40011000UL
#define GPIOD_BASE		0x40011400UL

//GPIO E are not included in LQFP48 package
#define GPIOE_BASE		0x40011800UL

//------
//EXTI
#define EXTI_BASE 								(Peripherals_BASE + 0x00010400UL)

//TIMERS
//TIM1
#define TIM1_BASE								(Peripherals_BASE + 0x00012C00UL)
#define TIM8_BASE								(Peripherals_BASE + 0x00013400UL)
#define TIM9_BASE								(Peripherals_BASE + 0x00014C00UL)
#define TIM10_BASE								(Peripherals_BASE + 0x00015000UL)
#define TIM11_BASE								(Peripherals_BASE + 0x00015400UL)

//AFIO
#define AFIO_BASE 								(Peripherals_BASE + 0x00010000UL)


//=============================================================================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register GPIO:
//-*-*-*-*-*-*-*-*-*-*-*

typedef	struct{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register RCC:
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register EXTI:
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register AFIO:
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	uint32_t 		  RESERVED0;
	volatile uint32_t MAPR2;
}AFIO_TypeDef;


//Timer1 and timer8
typedef struct
{
	volatile uint32_t TIMx_CR1;
	volatile uint32_t TIMx_CR2;
	volatile uint32_t TIMx_SMCR;
	volatile uint32_t TIMx_DIER;
	volatile uint32_t TIMx_SR;
	volatile uint32_t TIMx_EGR;
	volatile uint32_t TIMx_CCMR1;
	volatile uint32_t TIMx_CCMR2;
	volatile uint32_t TIMx_CCER;
	volatile uint32_t TIMx_CNT;
	volatile uint32_t TIMx_PSC;
	volatile uint32_t TIMx_ARR;
	volatile uint32_t TIMx_RCR;
	volatile uint32_t TIMx_CCR1;
	volatile uint32_t TIMx_CCR2;
	volatile uint32_t TIMx_CCR3;
	volatile uint32_t TIMx_CCR4;
	volatile uint32_t TIMx_BDTR;
	volatile uint32_t TIMx_DCR;  
	volatile uint32_t TIMx_DMAR;
}TIMER1_8_Typedef_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register TIMERS 2-->5:
//-*-*-*-*-*-*-*-*-*-*-*

typedef	struct{
	volatile uint32_t TIMx_CR1;
	volatile uint32_t TIMx_CR2;
	volatile uint32_t TIMx_SMCR;
	volatile uint32_t TIMx_DIER;
	volatile uint32_t TIMx_SR;
	volatile uint32_t TIMx_EGR;
	volatile uint32_t TIMx_CCMR1;
	volatile uint32_t TIMx_CCMR2;
	volatile uint32_t TIMx_CCMR2;
	volatile uint32_t TIMx_CCER;
	volatile uint32_t TIMx_CNT;
	volatile uint32_t TIMx_PSC;
	volatile uint32_t TIMx_ARR;
	uint32_t 		  RESERVED0;
	volatile uint32_t TIMx_CCR1;
	volatile uint32_t TIMx_CCR2;
	volatile uint32_t TIMx_CCR3;
	volatile uint32_t TIMx_CCR4;
	uint32_t 		  RESERVED0;
	volatile uint32_t TIMx_DCR;
	volatile uint32_t TIMx_DMAR;

}TIM2t5_TypeDef_t;



//============================================================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-

#define RCC 							 ((RCC_TypeDef *)RCC_BASE)


#define GPIOA 							 ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB 							 ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC 							 ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD 							 ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE 							 ((GPIO_TypeDef *)GPIOE_BASE)


#define EXTI 							 ((EXTI_TypeDef *)EXTI_BASE)

#define AFIO 							 ((AFIO_TypeDef *)AFIO_BASE)

//=================================================================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define RCC_GPIOA_CLK_EN()				(RCC->APB2ENR |= (1<<2))
#define RCC_GPIOB_CLK_EN()				(RCC->APB2ENR |= (1<<3))
#define RCC_GPIOC_CLK_EN()				(RCC->APB2ENR |= (1<<4))
#define RCC_GPIOD_CLK_EN()				(RCC->APB2ENR |= (1<<5))
#define RCC_GPIOE_CLK_EN()				(RCC->APB2ENR |= (1<<6))
#define RCC_TIM1_CLK_EN()				(RCC->APB2ENR |= (1<<11))
#define RCC_TIM2_CLK_EN()				(RCC->APB1ENR |= (1<<0))
#define RCC_TIM3_CLK_EN()				(RCC->APB1ENR |= (1<<1))
#define RCC_TIM4_CLK_EN()				(RCC->APB1ENR |= (1<<2))
#define RCC_TIM5_CLK_EN()				(RCC->APB1ENR |= (1<<3))
#define RCC_TIM6_CLK_EN()				(RCC->APB1ENR |= (1<<4))
#define RCC_TIM7_CLK_EN()				(RCC->APB2ENR |= (1<<5))
#define RCC_AFIO_CLK_EN()				(RCC->APB2ENR |= (1<<0))





#endif /* INC_STM32_F103X6_H_ */
