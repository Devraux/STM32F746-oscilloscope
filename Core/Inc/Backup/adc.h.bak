/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    adc.h
  * @brief   This file contains all the function prototypes for
  *          the adc.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ADC_H__
#define __ADC_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

#include "../../Data_Buffer/Data_Buffer.h"
#include "stm32f7xx_it.h"
#include "stdbool.h"

/* USER CODE END Includes */

extern ADC_HandleTypeDef hadc1;

extern ADC_HandleTypeDef hadc3;

/* USER CODE BEGIN Private defines */
#define ADC_dataBufferSize 1000
#define ADC_byteDataBufferSize ADC_dataBufferSize * sizeof(uint32_t)

/* USER CODE END Private defines */

void MX_ADC1_Init(void);
void MX_ADC3_Init(void);

/* USER CODE BEGIN Prototypes */
// Double buffering DMA & ADC
uint32_t *ADC_getDataPtrBuffer1(void);
uint32_t *ADC_getDataPtrBuffer2(void);
uint32_t *ADC_getProperBuffer(void);

typedef enum ADC_activeBuffer{
	current_activeBuffer1 = 1,
	current_activeBuffer2 = 2,
}ADC_activeBuffer;

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __ADC_H__ */

