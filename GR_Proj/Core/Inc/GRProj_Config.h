/*
 * GRProj_Config.h
 *
 *  Created on: Jun 14, 2023
 *      Author: Dell
 */

#ifndef SRC_GRPROJ_CONFIG_H_
#define SRC_GRPROJ_CONFIG_H_

//os includes
#include "cmsis_os.h"

//component includes
#include "L298N.h"
#include "CAR.h"


/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

#define BIT_0 (1<<0)
#define BIT_1 (1<<1)
#define BIT_2 (1<<2)


/* Private variables ---------------------------------------------------------*/

ADC_HandleTypeDef hadc2;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

osThreadId Move_TaskHandle;
osThreadId Temp_TaskHandle;
osThreadId Ultra_TaskHandle;
osThreadId Confirm_TaskHandle;
osSemaphoreId myBinarySem01Handle;
EventGroupHandle_t myEventGroupHandle;

/* Private Global variables ---------------------------------------------------------*/

/*Car global variables*/
L298N_HandleTypeDef l298l = {
		GPIOA,
		GPIO_PIN_4,
		GPIO_PIN_5,
		GPIOB,
		GPIO_PIN_14,
		GPIO_PIN_15,
		TIM3,
		TIM_CHANNEL_2,
		&htim3,
		TIM3,
		TIM_CHANNEL_2,
		&htim3
};

CAR_TYPEDEF car = {
		&l298l
};

/*UART global variables*/
uint8_t conf;
uint8_t mov;
uint8_t temp;
uint8_t fore;
uint8_t rec;
uint8_t ultra;





/*Temperature sensor global variables*/
float volatile ADC_result;
int ADC_valid=0;
int Check_interrupt;
float volatile temperature;

/*ultrasonic global variables*/

#define TRIG_PIN  GPIO_PIN_12
#define TRIG_PORT GPIOA

uint32_t IC_Val1 = 0;
uint32_t IC_Val2 = 0;
uint32_t Difference = 0;
uint8_t Is_First_Captured = 0;  // is the first value captured ?
float distance  = 0;
/* Private function prototypes -----------------------------------------------*/

/*Private System init function prototypes*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM3_Init(void);
static void MX_ADC2_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART2_UART_Init(void);

/*Private components init function prototypes*/
void HCSR04_Read (void);
void Read_temp(void);
void delay(uint16_t time);
void Buzzer_ON(void);
void Buzzer_OFF(void);

/*RTOS tasks function prototypes*/
void Start_Confirm_Task(void const * argument);
void Start_Move_Task(void const * argument);
void StartTemp_Task(void const * argument);
void Start_Ultra_Task(void const * argument);


#endif /* SRC_GRPROJ_CONFIG_H_ */
