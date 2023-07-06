
/**
 ******************************************************************************
 * @file    L298N.h
 * @brief   Header file for L298N motor driver module
 ******************************************************************************
 *
 * Copyright (c) Eng. ALI Osama Abo-Ouf 2023
 * All rights reserved.
 *
 ******************************************************************************
 */

#ifndef INC_L298N_H_
#define INC_L298N_H_


/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Exported types ------------------------------------------------------------*/
/*  @ref motor_number  */
typedef enum {
	L298N_MOTOR_1 = 0,
	L298N_MOTOR_2
} L298N_MotorNumberTypeDef;


/*  @ref motor_direction  */
typedef enum {
	L298N_MOTOR_DIRECTION_STOP = 0,
	L298N_MOTOR_DIRECTION_FORWARD,
	L298N_MOTOR_DIRECTION_BACKWARD
} L298N_MotorDirectionTypeDef;



typedef struct {
	GPIO_TypeDef * motor1_port;
	uint16_t motor1_pin1;
	uint16_t motor1_pin2;
	GPIO_TypeDef * motor2_port;
	uint16_t motor2_pin1;
	uint16_t motor2_pin2;
	TIM_TypeDef * TIM_pwm_1;
	uint32_t timer_channel_1;
	TIM_HandleTypeDef *timer_handle_1;
	TIM_TypeDef * TIM_pwm_2;
	uint32_t timer_channel_2;
	TIM_HandleTypeDef *timer_handle_2;
//	uint32_t timer_frequency;
} L298N_HandleTypeDef;

/* Exported functions --------------------------------------------------------*/
void L298N_Init(L298N_HandleTypeDef *hl298n);
void L298N_SetMotorSpeed(L298N_HandleTypeDef *hl298n, L298N_MotorNumberTypeDef motorNumber, uint16_t speed);
void L298N_SetMotorDirection(L298N_HandleTypeDef *hl298n, L298N_MotorNumberTypeDef motorNumber, L298N_MotorDirectionTypeDef direction);




#endif /* INC_L298N_H_ */
