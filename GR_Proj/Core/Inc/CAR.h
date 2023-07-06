

/**
 ******************************************************************************
 * @file    CAR.h
 * @brief   Header file for 4-wheels car module
 ******************************************************************************
 *
 * Copyright (c) Eng. ALI Osama Abo-Ouf 2023
 * All rights reserved.
 *
 ******************************************************************************
 */

#ifndef CAR_H_
#define CAR_H_

#include "L298N.h"
typedef struct {

	L298N_HandleTypeDef*  motor;

}CAR_TYPEDEF;




void Car_INIT(CAR_TYPEDEF* Car);
void Car_Start(CAR_TYPEDEF* Car);
void Car_Stop(CAR_TYPEDEF* Car);
void Car_Forward(CAR_TYPEDEF* Car);
void Car_Reverse(CAR_TYPEDEF* Car);
void Car_Right(CAR_TYPEDEF* Car);
void Car_left(CAR_TYPEDEF* Car);
void Car_Set_Speed(CAR_TYPEDEF* Car , uint16_t speed);

#endif /* CAR_H_ */
