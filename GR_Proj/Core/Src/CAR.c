

/**
 ******************************************************************************
 * @file    CAR.c
 * @brief   Source file for L298N motor driver module
 ******************************************************************************
 *
 * Copyright (c) Eng. ALI Osama Abo-Ouf 2023
 * All rights reserved.
 *
 ******************************************************************************
 */

#include "CAR.h"
#include "L298N.h"


void Car_INIT(CAR_TYPEDEF* Car){
	L298N_Init(Car->motor);

}

void Car_Start(CAR_TYPEDEF* Car){
	L298N_SetMotorDirection(Car->motor , L298N_MOTOR_1,L298N_MOTOR_DIRECTION_FORWARD);
	L298N_SetMotorDirection(Car->motor , L298N_MOTOR_2,L298N_MOTOR_DIRECTION_FORWARD);

}
void Car_Stop(CAR_TYPEDEF* Car){
	L298N_SetMotorDirection(Car->motor , L298N_MOTOR_1,L298N_MOTOR_DIRECTION_STOP);
	L298N_SetMotorDirection(Car->motor , L298N_MOTOR_2,L298N_MOTOR_DIRECTION_STOP);

}
void Car_Forward(CAR_TYPEDEF* Car){
	L298N_SetMotorDirection(Car->motor , L298N_MOTOR_1,L298N_MOTOR_DIRECTION_FORWARD);
	L298N_SetMotorDirection(Car->motor , L298N_MOTOR_2,L298N_MOTOR_DIRECTION_FORWARD);


}
void Car_Reverse(CAR_TYPEDEF* Car){
	L298N_SetMotorDirection(Car->motor , L298N_MOTOR_1,L298N_MOTOR_DIRECTION_BACKWARD);
	L298N_SetMotorDirection(Car->motor , L298N_MOTOR_2,L298N_MOTOR_DIRECTION_BACKWARD);

}
void Car_Right(CAR_TYPEDEF* Car){
	L298N_SetMotorDirection(Car->motor , L298N_MOTOR_1,L298N_MOTOR_DIRECTION_STOP);
	L298N_SetMotorDirection(Car->motor , L298N_MOTOR_2,L298N_MOTOR_DIRECTION_FORWARD);
}

void Car_left(CAR_TYPEDEF* Car){
	L298N_SetMotorDirection(Car->motor , L298N_MOTOR_1,L298N_MOTOR_DIRECTION_FORWARD);
	L298N_SetMotorDirection(Car->motor , L298N_MOTOR_2,L298N_MOTOR_DIRECTION_STOP);
}

void Car_Set_Speed(CAR_TYPEDEF* Car , uint16_t speed){
	L298N_SetMotorSpeed(Car->motor, L298N_MOTOR_1, speed);
	L298N_SetMotorSpeed(Car->motor, L298N_MOTOR_2, speed);

}
