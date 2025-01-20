/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    ltdc.h
  * @brief   This file contains all the function prototypes for
  *          the ltdc.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#ifndef __LTDC_H__
#define __LTDC_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "tim.h"
#include "quadspi.h"
/* USER CODE END Includes */

extern LTDC_HandleTypeDef hltdc;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_LTDC_Init(void);

/* USER CODE BEGIN Prototypes */

uint16_t *LTDC_Buffer_Init(void);
void display_Activate(void);
void display_BL_Set(bool back_Light_State);
void display_Draw_Rectangle(uint32_t x_px, uint32_t y_px, uint32_t width_px, uint32_t heigh_px, uint32_t colour);
void display_Draw_Circle(uint32_t x_px, uint32_t y_px, uint32_t radius_px, uint32_t colour);
void display_Simple_Update(uint16_t *buffer);


/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __LTDC_H__ */

