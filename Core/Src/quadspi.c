/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    quadspi.c
  * @brief   This file provides code for the configuration
  *          of the QUADSPI instances.
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
/* Includes ------------------------------------------------------------------*/
#include "quadspi.h"

/* USER CODE BEGIN 0 */
QSPI_CommandTypeDef sCommand = {
	.InstructionMode   = QSPI_INSTRUCTION_1_LINE,
	.AddressSize       = QSPI_ADDRESS_24_BITS,
	.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE,
	.DdrMode           = QSPI_DDR_MODE_DISABLE,
	.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY,
	.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD
};
/* USER CODE END 0 */

QSPI_HandleTypeDef hqspi;

/* QUADSPI init function */
void MX_QUADSPI_Init(void)
{

  /* USER CODE BEGIN QUADSPI_Init 0 */

  /* USER CODE END QUADSPI_Init 0 */

  /* USER CODE BEGIN QUADSPI_Init 1 */

  /* USER CODE END QUADSPI_Init 1 */
  hqspi.Instance = QUADSPI;
  hqspi.Init.ClockPrescaler = 0;
  hqspi.Init.FifoThreshold = 4;
  hqspi.Init.SampleShifting = QSPI_SAMPLE_SHIFTING_NONE;
  hqspi.Init.FlashSize = 23;
  hqspi.Init.ChipSelectHighTime = QSPI_CS_HIGH_TIME_4_CYCLE;
  hqspi.Init.ClockMode = QSPI_CLOCK_MODE_0;
  hqspi.Init.FlashID = QSPI_FLASH_ID_1;
  hqspi.Init.DualFlash = QSPI_DUALFLASH_DISABLE;
  if (HAL_QSPI_Init(&hqspi) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN QUADSPI_Init 2 */


  // ENABLE WRITE OPERATION AND ERASE MEMORY SPACE //
    QSPI_WriteEnable(&hqspi);

    sCommand.Instruction = BULK_ERASE_CMD; // SECTOR_ERASE_CMD;
    sCommand.AddressMode = QSPI_ADDRESS_1_LINE;
  	sCommand.Address     = 0;
  	sCommand.DataMode    = QSPI_DATA_NONE;
  	sCommand.DummyCycles = 0;

  	if(HAL_QSPI_Command_IT(&hqspi, &sCommand) != HAL_OK)
 	{
  		Error_Handler();
  	}

  	// Configure automatic polling mode to wait for end of erase //
  	QSPI_AutoPollingMemReady(&hqspi);

  /* USER CODE END QUADSPI_Init 2 */

}

void HAL_QSPI_MspInit(QSPI_HandleTypeDef* qspiHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(qspiHandle->Instance==QUADSPI)
  {
  /* USER CODE BEGIN QUADSPI_MspInit 0 */

  /* USER CODE END QUADSPI_MspInit 0 */
    /* QUADSPI clock enable */
    __HAL_RCC_QSPI_CLK_ENABLE();

    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    /**QUADSPI GPIO Configuration
    PE2     ------> QUADSPI_BK1_IO2
    PB6     ------> QUADSPI_BK1_NCS
    PB2     ------> QUADSPI_CLK
    PD12     ------> QUADSPI_BK1_IO1
    PD13     ------> QUADSPI_BK1_IO3
    PD11     ------> QUADSPI_BK1_IO0
    */
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_QUADSPI;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF10_QUADSPI;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_QUADSPI;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_QUADSPI;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /* QUADSPI interrupt Init */
    HAL_NVIC_SetPriority(QUADSPI_IRQn, 3, 0);
    HAL_NVIC_EnableIRQ(QUADSPI_IRQn);
  /* USER CODE BEGIN QUADSPI_MspInit 1 */
  /* USER CODE END QUADSPI_MspInit 1 */
  }
}

void HAL_QSPI_MspDeInit(QSPI_HandleTypeDef* qspiHandle)
{

  if(qspiHandle->Instance==QUADSPI)
  {
  /* USER CODE BEGIN QUADSPI_MspDeInit 0 */

  /* USER CODE END QUADSPI_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_QSPI_CLK_DISABLE();

    /**QUADSPI GPIO Configuration
    PE2     ------> QUADSPI_BK1_IO2
    PB6     ------> QUADSPI_BK1_NCS
    PB2     ------> QUADSPI_CLK
    PD12     ------> QUADSPI_BK1_IO1
    PD13     ------> QUADSPI_BK1_IO3
    PD11     ------> QUADSPI_BK1_IO0
    */
    HAL_GPIO_DeInit(GPIOE, GPIO_PIN_2);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_6|GPIO_PIN_2);

    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_11);

    /* QUADSPI interrupt Deinit */
    HAL_NVIC_DisableIRQ(QUADSPI_IRQn);
  /* USER CODE BEGIN QUADSPI_MspDeInit 1 */

  /* USER CODE END QUADSPI_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

void QSPI_WriteEnable(QSPI_HandleTypeDef *QSPIHandle)
{
	QSPI_CommandTypeDef     	sCommand_t;
	QSPI_AutoPollingTypeDef 	sConfig_t;

	// Enable write operations //
	sCommand_t.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
	sCommand_t.Instruction       = WRITE_ENABLE_CMD;
	sCommand_t.AddressMode       = QSPI_ADDRESS_NONE;
	sCommand_t.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
	sCommand_t.DataMode          = QSPI_DATA_NONE;
	sCommand_t.DummyCycles       = 0;
	sCommand_t.DdrMode           = QSPI_DDR_MODE_DISABLE;
	sCommand_t.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
	sCommand_t.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

	if(HAL_QSPI_Command(QSPIHandle, &sCommand_t, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	{
		Error_Handler();
	}

	// Configure automatic polling mode to wait for write enabling //
	sConfig_t.Match           = 0x02;
	sConfig_t.Mask            = 0x02;
	sConfig_t.MatchMode       = QSPI_MATCH_MODE_AND;
	sConfig_t.StatusBytesSize = 1;
	sConfig_t.Interval        = 0x10;
	sConfig_t.AutomaticStop   = QSPI_AUTOMATIC_STOP_ENABLE;

	sCommand_t.Instruction    = READ_STATUS_REG_CMD;
	sCommand_t.DataMode       = QSPI_DATA_1_LINE;

	if(HAL_QSPI_AutoPolling(QSPIHandle, &sCommand_t, &sConfig_t, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	{
		Error_Handler();
	}
}

void QSPI_AutoPollingMemReady(QSPI_HandleTypeDef *QSPIHandle)
{
  QSPI_CommandTypeDef     sCommand_t;
  QSPI_AutoPollingTypeDef sConfig_t;

  // Configure automatic polling mode to wait for memory ready //
  sCommand_t.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
  sCommand_t.Instruction       = READ_STATUS_REG_CMD;
  sCommand_t.AddressMode       = QSPI_ADDRESS_NONE;
  sCommand_t.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  sCommand_t.DataMode          = QSPI_DATA_1_LINE;
  sCommand_t.DummyCycles       = 4;
  sCommand_t.DdrMode           = QSPI_DDR_MODE_DISABLE;
  sCommand_t.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  sCommand_t.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

  sConfig_t.Match           = 0x00;
  sConfig_t.Mask            = 0x01;
  sConfig_t.MatchMode       = QSPI_MATCH_MODE_AND;
  sConfig_t.StatusBytesSize = 1;
  sConfig_t.Interval        = 0x10;
  sConfig_t.AutomaticStop   = QSPI_AUTOMATIC_STOP_ENABLE;

  if (HAL_QSPI_AutoPolling_IT(QSPIHandle, &sCommand_t, &sConfig_t) != HAL_OK)
  {
    Error_Handler();
  }
}

void QSPI_DummyCyclesCfg(QSPI_HandleTypeDef *QSPIHandle)
{
  QSPI_CommandTypeDef sCommand_t;
  uint8_t reg;

  // Read Volatile Configuration register //
  sCommand_t.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
  sCommand_t.Instruction       = READ_VOL_CFG_REG_CMD;
  sCommand_t.AddressMode       = QSPI_ADDRESS_NONE;
  sCommand_t.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  sCommand_t.DataMode          = QSPI_DATA_1_LINE;
  sCommand_t.DummyCycles       = 0;
  sCommand_t.DdrMode           = QSPI_DDR_MODE_DISABLE;
  sCommand_t.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  sCommand_t.SIOOMode         = QSPI_SIOO_INST_EVERY_CMD;
  sCommand_t.NbData            = 1;

  if (HAL_QSPI_Command(QSPIHandle, &sCommand_t, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    Error_Handler();
  }

  if (HAL_QSPI_Receive(QSPIHandle, &reg, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    Error_Handler();
  }

  // Enable write operations //
  QSPI_WriteEnable(QSPIHandle);

  // Write Volatile Configuration register (with new dummy cycles) //
  sCommand_t.Instruction = WRITE_VOL_CFG_REG_CMD;
  MODIFY_REG(reg, 0xF0, (DUMMY_CLOCK_CYCLES_READ_QUAD << POSITION_VAL(0xF0)));

  if (HAL_QSPI_Command(QSPIHandle, &sCommand_t, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    Error_Handler();
  }

  if (HAL_QSPI_Transmit(QSPIHandle, &reg, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    Error_Handler();
  }
}

void QSPI_WriteData(uint8_t *data, uint32_t data_Byte_Length, uint32_t address)
{
	QSPI_WriteEnable(&hqspi);
	sCommand.Instruction = QUAD_IN_FAST_PROG_CMD;
	sCommand.AddressMode = QSPI_ADDRESS_1_LINE;
	sCommand.DataMode    = QSPI_DATA_4_LINES;
	sCommand.Address     = address;
	sCommand.NbData      = data_Byte_Length;

	if(HAL_QSPI_Command(&hqspi, &sCommand, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	{
		Error_Handler();
	}

	if(HAL_QSPI_Transmit_IT(&hqspi, data) != HAL_OK)
	{
		Error_Handler();
	}

	QSPI_AutoPollingMemReady(&hqspi);
}

void QSPI_ReadData(uint8_t  *data, uint32_t data_Byte_Length, uint32_t address)
{
	QSPI_DummyCyclesCfg(&hqspi);
	sCommand.Instruction = QUAD_OUT_FAST_READ_CMD;
	sCommand.DummyCycles = DUMMY_CLOCK_CYCLES_READ_QUAD;
	sCommand.Address     = address;
	sCommand.NbData      = data_Byte_Length;

	if(HAL_QSPI_Command(&hqspi, &sCommand, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	{
		Error_Handler();
	}

	if(HAL_QSPI_Receive_IT(&hqspi, data) != HAL_OK)
	{
		Error_Handler();
	}
}

void QSPI_WriteImage(uint8_t *data, uint8_t ImageNumber)
{
		// first erase memory
		QSPI_WriteEnable(&hqspi);
		sCommand.Instruction = BULK_ERASE_CMD; // SECTOR_ERASE_CMD;
	    sCommand.AddressMode = QSPI_ADDRESS_1_LINE;
	  	sCommand.Address     = 0;
	  	sCommand.DataMode    = QSPI_DATA_NONE;
	  	sCommand.DummyCycles = 0;

	  	if(HAL_QSPI_Command_IT(&hqspi, &sCommand) != HAL_OK)
	 	{
	  		Error_Handler();
	  	}

	  	QSPI_AutoPollingMemReady(&hqspi);

		//QSPI_WriteEnable(&hqspi);
		sCommand.Instruction = QUAD_IN_FAST_PROG_CMD;
		sCommand.AddressMode = QSPI_ADDRESS_1_LINE;
		sCommand.DataMode    = QSPI_DATA_4_LINES;
		sCommand.Address     = GET_BASE_ADDRESS(ImageNumber);
		sCommand.NbData      = 65280;

		if(HAL_QSPI_Command(&hqspi, &sCommand, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
		{
			Error_Handler();
		}

		if(HAL_QSPI_Transmit_IT(&hqspi, data) != HAL_OK)
		{
			Error_Handler();
		}

		QSPI_AutoPollingMemReady(&hqspi);
}

void QSPI_Read_Image(uint8_t *data, uint8_t ImageNumber)
{
	QSPI_DummyCyclesCfg(&hqspi);
	sCommand.Instruction = QUAD_OUT_FAST_READ_CMD;
	sCommand.DummyCycles = DUMMY_CLOCK_CYCLES_READ_QUAD;
	sCommand.Address     = GET_BASE_ADDRESS(ImageNumber);
	sCommand.NbData      = 65280;

	if(HAL_QSPI_Command(&hqspi, &sCommand, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	{
		Error_Handler();
	}

	if(HAL_QSPI_Receive_IT(&hqspi, data) != HAL_OK)
	{
		Error_Handler();
	}
}



// QUAD SPI FLASH MEMORY - EXAMPLE TEST CODE//
// uint8_t dataToWrite[] = {" ****QSPI communication based on IT****  ****QSPI communication based on IT****  ****QSPI communication based on IT****  ****QSPI communication based on IT****  ****QSPI communication based on IT****  ****QSPI communication based on IT**** "};
//  uint8_t dataRead[BUFFERSIZE] = {0};
//
//  uint32_t writeAddress = 0x00000000;
//  uint32_t readAddress  = 0x00000000;
//
//  QSPI_WriteData(dataToWrite, BUFFERSIZE, writeAddress);
//  QSPI_ReadData(dataRead, BUFFERSIZE, readAddress);
//
//  printf("Read data: %s", dataRead);

/* USER CODE END 1 */
