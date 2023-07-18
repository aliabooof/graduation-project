
/**
 ******************************************************************************
 * @file    L298N.c
 * @brief   Source file for L298N motor driver module
 ******************************************************************************
 *
 * Copyright (c) Eng. ALI Osama Abo-Ouf 2023
 * All rights reserved.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "L298N.h"
/*private macros*/
#define period 100
/* Private functions ---------------------------------------------------------*/
static void L298N_SetMotorPinState(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState);
}


/* Public functions ----------------------------------------------------------*/


/*
 * This function initiate the L298N driver
 *
 * Parameters:
 *    - hl298n: address of the L298N instance
 *
 * Returns:
 *    - None
 *
 */

/******************************************************************************************************/
void L298N_Init(L298N_HandleTypeDef *hl298n)
{
	/*	 Enable GPIO clock
		__HAL_RCC_GPIOB_CLK_ENABLE();
		__HAL_RCC_GPIOC_CLK_ENABLE();

		GPIO_InitTypeDef GPIO_InitStruct = {0};

		 Initialize GPIO pins for motor 1
		if (hl298n->motor1_pin1 != 0 && hl298n->motor1_pin2 != 0 ){

			GPIO_InitStruct.Pin = hl298n->motor1_pin1 | hl298n->motor1_pin2;
			GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
			GPIO_InitStruct.Pull = GPIO_NOPULL;
			GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
			HAL_GPIO_Init(hl298n->motor1_port, &GPIO_InitStruct);
		}

		 Initialize GPIO pins for motor 2
		if (hl298n->motor2_pin1 != 0 && hl298n->motor2_pin2 != 0 ){

			GPIO_InitStruct.Pin = hl298n->motor2_pin1 | hl298n->motor2_pin2;
			GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
			GPIO_InitStruct.Pull = GPIO_NOPULL;
			GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
			HAL_GPIO_Init(hl298n->motor2_port, &GPIO_InitStruct);
		}

		 Enable timer clock
		__HAL_RCC_TIM2_CLK_ENABLE();

		 Configure timer for PWM control
		hl298n->timer_handle->Instance = hl298n->TIM;
		hl298n->timer_handle->Init.Prescaler = (uint32_t)(SystemCoreClock / hl298n->timer_frequency) - 1;
		hl298n->timer_handle->Init.Period = 999;
		hl298n->timer_handle->Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
		hl298n->timer_handle->Init.CounterMode = TIM_COUNTERMODE_UP;
		hl298n->timer_handle->Init.RepetitionCounter = 0;
		HAL_TIM_PWM_Init(hl298n->timer_handle);

		 Configure timer PWM output channels
		TIM_OC_InitTypeDef sConfigOC = {0};
		sConfigOC.OCMode = TIM_OCMODE_PWM1;
		sConfigOC.Pulse = 0;
		sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
		sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
		if (hl298n->timer_channel == TIM_CHANNEL_1) {
			HAL_TIM_PWM_ConfigChannel(hl298n->timer_handle, &sConfigOC, TIM_CHANNEL_1);
		}
		else if (hl298n->timer_channel == TIM_CHANNEL_2) {
			HAL_TIM_PWM_ConfigChannel(hl298n->timer_handle, &sConfigOC, TIM_CHANNEL_2);
		}
		else if (hl298n->timer_channel == TIM_CHANNEL_3) {
			HAL_TIM_PWM_ConfigChannel(hl298n->timer_handle, &sConfigOC, TIM_CHANNEL_3);
		}
		else if (hl298n->timer_channel == TIM_CHANNEL_4) {
			HAL_TIM_PWM_ConfigChannel(hl298n->timer_handle, &sConfigOC, TIM_CHANNEL_4);
		}
		HAL_TIM_PWM_Start(hl298n->timer_handle, hl298n->timer_channel);*/

	/* Set motor initial state */
	HAL_TIM_Base_Start(hl298n->timer_handle_1);
	HAL_TIM_Base_Start(hl298n->timer_handle_2);//Initialize stm32 timer 3

	HAL_TIM_PWM_Start(hl298n->timer_handle_1, hl298n->timer_channel_1); // Replace TIM_CHANNEL_x with the appropriate channel
	HAL_TIM_PWM_Start(hl298n->timer_handle_2, hl298n->timer_channel_2); // Replace TIM_CHANNEL_x with the appropriate channel

	L298N_SetMotorDirection(hl298n, L298N_MOTOR_1, L298N_MOTOR_DIRECTION_STOP);
	L298N_SetMotorDirection(hl298n, L298N_MOTOR_2, L298N_MOTOR_DIRECTION_STOP);
}

/******************************************************************************************************/


/*
 * This function set speed of motors connected the L298N driver
 *
 * Parameters:
 *    - hl298n: address of the L298N instance
 *	  - motorNumber: number of the motor this parameter can be set according to @ref motor_number
 *	  - speed: speed of the motor this parameter can be set from 0 t0 100
 *
 * Returns:
 *    - None
 *
 */

void L298N_SetMotorSpeed(L298N_HandleTypeDef* hl298n, L298N_MotorNumberTypeDef motorNumber, uint16_t speed)
{
	/* Calculate PWM duty cycle based on input speed */
	uint32_t pulse = (speed * period) / 100;
	/* Set PWM duty cycle for selected motor */
	if (motorNumber == L298N_MOTOR_1) {
		__HAL_TIM_SET_COMPARE(hl298n->timer_handle_1, hl298n->timer_channel_1, pulse);
	}
	else if (motorNumber == L298N_MOTOR_2) {
		__HAL_TIM_SET_COMPARE(hl298n->timer_handle_2, hl298n->timer_channel_2, pulse);
	}
}


/******************************************************************************************************/

/*
 * This function set speed of motors connected the L298N driver
 *
 * Parameters:
 *    - hl298n: address of the L298N instance
 *	  - motorNumber: number of the motor this parameter can be set according to @ref motor_number
 *	  - direction: direction of the motor this parameter can be set according to @ref motor_direction
 *
 * Returns:
 *    - None
 *
 */

void L298N_SetMotorDirection(L298N_HandleTypeDef* hl298n, L298N_MotorNumberTypeDef motorNumber, L298N_MotorDirectionTypeDef direction)
{
	/* Set motor direction based on input direction */
	if (motorNumber == L298N_MOTOR_1) {
		if (direction == L298N_MOTOR_DIRECTION_FORWARD) {
			L298N_SetMotorPinState(hl298n->motor1_port, hl298n->motor1_pin1, GPIO_PIN_SET);
			L298N_SetMotorPinState(hl298n->motor1_port, hl298n->motor1_pin2, GPIO_PIN_RESET);
		}
		else if (direction == L298N_MOTOR_DIRECTION_BACKWARD) {
			L298N_SetMotorPinState(hl298n->motor1_port, hl298n->motor1_pin1, GPIO_PIN_RESET);
			L298N_SetMotorPinState(hl298n->motor1_port, hl298n->motor1_pin2, GPIO_PIN_SET);

		}else if (direction == L298N_MOTOR_DIRECTION_STOP) {
			L298N_SetMotorPinState(hl298n->motor1_port, hl298n->motor1_pin1, GPIO_PIN_RESET);
			L298N_SetMotorPinState(hl298n->motor1_port, hl298n->motor1_pin2, GPIO_PIN_RESET);
		}
	}
	else if (motorNumber == L298N_MOTOR_2) {
		if (direction == L298N_MOTOR_DIRECTION_FORWARD) {
			L298N_SetMotorPinState(hl298n->motor2_port, hl298n->motor2_pin1, GPIO_PIN_SET);
			L298N_SetMotorPinState(hl298n->motor2_port, hl298n->motor2_pin2, GPIO_PIN_RESET);
		}
		else if (direction == L298N_MOTOR_DIRECTION_BACKWARD) {
			L298N_SetMotorPinState(hl298n->motor2_port, hl298n->motor2_pin1, GPIO_PIN_RESET);
			L298N_SetMotorPinState(hl298n->motor2_port, hl298n->motor2_pin2, GPIO_PIN_SET);
		}
		else if (direction == L298N_MOTOR_DIRECTION_STOP) {
			L298N_SetMotorPinState(hl298n->motor2_port, hl298n->motor2_pin1, GPIO_PIN_RESET);
			L298N_SetMotorPinState(hl298n->motor2_port, hl298n->motor2_pin2, GPIO_PIN_RESET);
		}
	}
}

