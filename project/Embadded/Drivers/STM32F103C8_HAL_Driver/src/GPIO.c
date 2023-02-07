/*
 * GPIO.c
 *
 *  Created on: Feb 7, 2023
 *      Author: aliab
 */


#include "stm32f103x8_xb.h"
#include "GPIO.h"

uint16_t Get_CRLH_position(uint16_t PinNumber){
	switch(PinNumber){
	//position for pins from 0>>>7 in CRL register
	case GPIO_PIN_0  : return 0;
	break;
	case GPIO_PIN_1  : return 4;
	break;
	case GPIO_PIN_2  : return 8;
	break;
	case GPIO_PIN_3  : return 12;
	break;
	case GPIO_PIN_4  : return 16;
	break;
	case GPIO_PIN_5  : return 20;
	break;
	case GPIO_PIN_6  : return 24;
	break;
	case GPIO_PIN_7  : return 28;
	break;
	//position for pins from 8>>>15 in CRH register
	case GPIO_PIN_8  : return 0;
	break;
	case GPIO_PIN_9  : return 4;
	break;
	case GPIO_PIN_10 : return 8;
	break;
	case GPIO_PIN_11 : return 12;
	break;
	case GPIO_PIN_12 : return 16;
	break;
	case GPIO_PIN_13 : return 20;
	break;
	case GPIO_PIN_14 : return 24;
	break;
	case GPIO_PIN_15 : return 28;
	break;
	}
	return 0;
}

/**================================================================
 * @Fn			-MCAL_GPIO_Init
 * @brief 		-Initialize GPIOx and configure its PINy according to specific parameter in PinConfig.
 * @param [in] 	-GPIOx where x can be (A...E depending on device used) to select GPIO peripheral.
 * @param [in] 	-PinConfig pointer to GPIO_PIN_Config_t structure
 * 				 that contains the configuration information for the specified GPIO pin.
 * @param [out] 	- none
 * @retval	 	- none
 * Note			-stm32f103c6 MCU has GPIO A,B,C,D,E modules
 * 				 but LQFPP48 has only GPIO A ,B and part of E,D exported as external pins from THE MCU
 */


void MCAL_GPIO_Init(GPIO_TypeDef * GPIOx , GPIO_PIN_Config_t * PinConfig){
	uint8_t pin_config = 0;
	volatile uint32_t *ConfigRegister = NULL;
	//pins from 0>>>7 in CRL register and from 8>>>15 in CRH register
	ConfigRegister = ((PinConfig->GPIO_PinNumber) < GPIO_PIN_8)?(&GPIOx->CRL) :(&GPIOx->CRH);

	//resets pin state before configure it
	* ConfigRegister &= ~ (0XF << (Get_CRLH_position(PinConfig->GPIO_PinNumber)));
	// if the pin is output
	if(PinConfig->GPIO_PinMode == GPIO_MODE_OUTPUT_PP ||PinConfig->GPIO_PinMode == GPIO_MODE_OUTPUT_OD ||PinConfig->GPIO_PinMode == GPIO_MODE_OUTPUT_AF_PP ||PinConfig->GPIO_PinMode == GPIO_MODE_ANALOG_AF_OD )
	{
		//CNFy[1:0] MODEy[1:0] 4bits for pin configuration
		pin_config = ( (((PinConfig->GPIO_PinMode) - 4) <<2) | ((PinConfig->GPIO_OUTPUT_SPEED) & 0x0F));

	}
	// if the pin is input
	else{ // MODE = 00 :input mode (reset state)

		if(PinConfig->GPIO_PinMode == GPIO_MODE_ANALOG ||PinConfig->GPIO_PinMode == GPIO_MODE_INPUT_FLO)
		{
			pin_config = ( ((PinConfig->GPIO_PinMode) <<2) | (0x0 & 0x0F));

		}
		else if(PinConfig->GPIO_PinMode == GPIO_MODE_INPUT_AF) //works as floating
		{
			pin_config = ( ((GPIO_MODE_INPUT_FLO) <<2) | (0x0 & 0x0F));

		}
		else
		{
			pin_config = ( ((GPIO_MODE_INPUT_PU) <<2) | (0x0 & 0x0F));
			//Table 20. Port bit configuration table
			if(PinConfig->GPIO_PinMode == GPIO_MODE_INPUT_PU)
			{
				//set PxODR register to 1 if its input  pull up mode
				GPIOx->ODR |= (PinConfig->GPIO_PinNumber); // note that pin number already got shifted
			}
			else
			{
				//set PxODR register to 0 if its input  pull up mode
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber); // note that pin number already got shifted
			}

		}



	}
	* ConfigRegister |= ( (pin_config) << Get_CRLH_position(PinConfig->GPIO_PinNumber));
}
/**================================================================
 * @Fn			-MCAL_GPIO_DeInit
 * @brief 		-Resets  GPIOx registers.
 * @param [in] 	-GPIOx where x can be (A...E depending on device used) to select GPIO peripheral.
 * @param [out] 	- none
 * @retval	 	- none
 * Note			-none
 */

void MCAL_GPIO_DeInit(GPIO_TypeDef * GPIOx){
	// using reset controller
	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &= ~(1<<3);

	}
	else if(GPIOx == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4);
		RCC->APB2RSTR &= ~(1<<4);

	}
	else if(GPIOx == GPIOD)
	{
		RCC->APB2RSTR |= (1<<5);
		RCC->APB2RSTR &= ~(1<<5);

	}
	else
	{
		RCC->APB2RSTR |= (1<<6);
		RCC->APB2RSTR &= ~(1<<6);

	}


}
/**================================================================
 * @Fn			-MCAL_GPIO_ReadPin
 * @brief 		-Reads value of specified PIN.
 * @param [in] 	-GPIOx where x can be (A...E depending on device used) to select GPIO peripheral.
 * @param [in] 	-PIN number : set PIN number according @ref GPIO_PINS_define
 * @retval	 	-input PIN value (two values according @ref GPIO_PIN_stat)
 * Note			-none
 */

uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef * GPIOx, uint16_t PinNumber ){
	uint8_t PinStatues ;
	// mask bit number
	if(((GPIOx->IDR) & PinNumber) != (uint32_t)GPIO_PIN_RESET){
		PinStatues = GPIO_PIN_SET;
	}
	else{
		PinStatues = GPIO_PIN_RESET;
	}
	return PinStatues;

}
/**================================================================
 * @Fn			-MCAL_GPIO_ReadPort
 * @brief 		-Reads value of GPIOx.
 * @param [in] 	-GPIOx where x can be (A...E depending on device used) to select GPIO peripheral.
 * @param [in] 	-PIN number : set PIN number according @ref GPIO_PINS_define
 * @retval	 	-input PORT value
 * Note			-none
 */

uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef * GPIOx ){
	uint16_t PortValue ;
	PortValue = (uint16_t)(GPIOx->IDR) ;
	return PortValue;

}

/**================================================================
 * @Fn			-MCAL_GPIO_WritePin
 * @brief 		-Write value on specified PIN.
 * @param [in] 	-GPIOx where x can be (A...E depending on device used) to select GPIO peripheral.
 * @param [in] 	-PIN number : set PIN number according @ref GPIO_PINS_define
 * @param [in]	-value : PIN value
 * @retval	 	-none
 * Note			-none
 */

void MCAL_GPIO_WritePin(GPIO_TypeDef * GPIOx , uint16_t PinNumber , uint8_t value){
	if(value != (uint8_t)GPIO_PIN_RESET){
//		Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
//		These bits are write-only and can be accessed in Word mode only.
//		0: No action on the corresponding ODRx bit
//		1: Set the corresponding ODRx bit

			(GPIOx->BSRR) = (uint16_t)PinNumber ;
		}
		else{
//			Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
//			These bits are write-only and can be accessed in Word mode only.
//			0: No action on the corresponding ODRx bit
//			1: Reset the corresponding ODRx bit
			(GPIOx->BRR) = (uint16_t)PinNumber ;
		}

}

/**================================================================
 * @Fn			-MCAL_GPIO_WritePort
 * @brief 		-write value to GPIOx.
 * @param [in] 	-GPIOx where x can be (A...E depending on device used) to select GPIO peripheral.
 * @param [in]	-value : PORT value
 * @retval	 	-none
 * Note			-none
 */
void MCAL_GPIO_WritePort(GPIO_TypeDef * GPIOx ,uint16_t value ){

	GPIOx->ODR = (uint32_t) value;

}

/**================================================================
 * @Fn			-MCAL_GPIO_TogglePin
 * @brief 		-toggle specific PIN.
 * @param [in] 	-GPIOx where x can be (A...E depending on device used) to select GPIO peripheral.
 * @param [in] 	-PIN number : set PIN number according @ref GPIO_PINS_define
 * @retval	 	-none
 * Note			-none
 */
void MCAL_GPIO_TogglePin(GPIO_TypeDef * GPIOx , uint16_t PinNumber){
	(GPIOx->ODR) ^= PinNumber;

}

/**================================================================
 * @Fn			-MCAL_GPIO_LockPin
 * @brief 		-toggle specific PIN.
 * @param [in] 	-GPIOx where x can be (A...E depending on device used) to select GPIO peripheral.
 * @param [in] 	-PIN number : set PIN number according @ref GPIO_PINS_define
 * @retval	 	-enabled if PIN config is locked or error if PIN not locked (enabled or error defined according @ref GPIO_RETURN_LOCK )
 * Note			-none
 */
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef * GPIOx , uint16_t PinNumber){
	//	Bit 16 LCKK[16]: Lock key
	//	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	//	0: Port configuration lock key not active
	//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	//	LOCK key writing sequence:
	//	Write 1
	//	Write 0
	//	Write 1
	//	Read 0
	//	Read 1 (this read is optional but confirms that the lock is active)
	//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	//	Any error in the lock sequence will abort the lock.
	//	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	//	These bits are read write but can only be written when the LCKK bit is 0.
	//	0: Port configuration not locked
	//	1: Port configuration locked.

	volatile uint32_t tmp;
	tmp = (1<<16);
	//set lcky
	tmp |= PinNumber;
	//write 1
	(GPIOx->LCKR) |=  tmp ;
	//write 0
	(GPIOx->LCKR) = PinNumber;
	//write 1
	(GPIOx->LCKR) |=  tmp ;
	//read 0
	tmp = (GPIOx->LCKR);
	//	Read 1 (this read is optional but confirms that the lock is active)
	if((uint32_t)(GPIOx->LCKR & 1<<16)){
		return	GPIO_RETURN_LOCK_ENABLED;
	}
	else{
		return	GPIO_RETURN_LOCK_ERROR;
	}
}
