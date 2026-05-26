/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

typedef struct {
    float humidity;
    float temperature;
    uint16_t conductivity;
    float ph;
    uint16_t nitrogen;
    uint16_t phosphorus;
    uint16_t potassium;
    uint16_t salinity;
    uint16_t tds;
} SoilData;

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */


uint16_t CalculateCRC(uint8_t *buf, int len);
void Read_Soil_Sensor(void);

SoilData currentData;
extern UART_HandleTypeDef huart2;
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval in
  */
int main(void)
{

  /* USER CODE BEGIN 1 *

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_USART1_UART_Init();


  /* USER CODE BEGIN 2 */
  HAL_UART_Transmit(&huart2, (uint8_t*)"BOOT OK\r\n", 9, 500);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  Read_Soil_Sensor();
	  HAL_Delay(1000);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 4800;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

uint16_t CalculateCRC(uint8_t *buf, int len) {
    uint16_t crc = 0xFFFF;
    for (int pos = 0; pos < len; pos++) {
        crc ^= (uint16_t)buf[pos];
        for (int i = 8; i != 0; i--) {
            if ((crc & 0x0001) != 0) {
                crc >>= 1;
                crc ^= 0xA001;
            } else {
                crc >>= 1;
            }
        }
    }
    return crc;
}

void Read_Soil_Sensor(void)
{
    uint8_t msg[8] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00};
    uint16_t crc = CalculateCRC(msg, 6);
    msg[6] = crc & 0xFF;
    msg[7] = (crc >> 8) & 0xFF;

    uint8_t response[19] = {0};
    char buffer[256];

    // Flush any garbage in RX buffer first
    __HAL_UART_FLUSH_DRREGISTER(&huart1);

    if (HAL_UART_Transmit(&huart1, msg, 8, 100) == HAL_OK)
    {
        HAL_Delay(100);  // Increased from 10 to 100ms
        if (HAL_UART_Receive(&huart1, response, 19, 2000) == HAL_OK)  // Increased timeout to 2000ms
        {
            snprintf(buffer, sizeof(buffer),
                    "RAW: %02X %02X %02X %02X %02X %02X %02X %02X %02X\r\n",
                    response[0], response[1], response[2],
                    response[3], response[4], response[5],
                    response[6], response[7], response[8]);
            HAL_UART_Transmit(&huart2, (uint8_t*)buffer, strlen(buffer), 200);
        }
        else
        {
            HAL_UART_Transmit(&huart2, (uint8_t*)"Timeout\r\n", 9, 100);
        }
    }
}

//void Read_Soil_Sensor(void) {
//    uint8_t msg[8] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x07, 0x04, 0x08};
//    uint8_t response[23] = {0};
//
//    uint16_t crc = CalculateCRC(msg, 6);
//    msg[6] = crc & 0xFF;
//    msg[7] = (crc >> 8) & 0xFF;
//
//    if (HAL_UART_Transmit(&huart1, msg, 8, 100) == HAL_OK) {
//        if (HAL_UART_Receive(&huart1, response, 23, 1000) == HAL_OK) {
//            currentData.humidity     = ((response[3] << 8) | response[4]) * 0.1f; // 0.1%RH
//            currentData.temperature  = ((response[5] << 8) | response[6]) * 0.1f;
//            currentData.conductivity = (response[7] << 8) | response[8];
//            currentData.ph           = ((response[9] << 8) | response[10]) * 0.1f;
//            currentData.nitrogen     = (response[11] << 8) | response[12];
//            currentData.phosphorus   = (response[13] << 8) | response[14];
//            currentData.potassium    = (response[15] << 8) | response[16];
//            currentData.salinity     = (response[17] << 8) | response[18];
//            currentData.tds          = (response[19] << 8) | response[20];
//        }
//    }
//
//    HAL_UART_Transmit(&huart2, currentData.nitrogen, 8, 100);
//
//
//}

//void Read_Soil_Sensor(void)
//{
//    uint8_t msg[8] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x07, 0x04, 0x08};
//    uint8_t response[23] = {0};
//
//    char buffer[128];
//
//    uint16_t crc = CalculateCRC(msg, 6);
//
//    msg[6] = crc & 0xFF;
//    msg[7] = (crc >> 8) & 0xFF;
//
//    if (HAL_UART_Transmit(&huart1, msg, 8, 100) == HAL_OK)
//    {
//        if (HAL_UART_Receive(&huart1, response, 19, 1000) == HAL_OK)
//        {
//            currentData.humidity     = ((response[3] << 8) | response[4]) * 0.1f;
//            currentData.temperature  = ((response[5] << 8) | response[6]) * 0.1f;
//            currentData.conductivity = (response[7] << 8) | response[8];
//            currentData.ph           = ((response[9] << 8) | response[10]) * 0.1f;
//            currentData.nitrogen     = (response[11] << 8) | response[12];
//            currentData.phosphorus   = (response[13] << 8) | response[14];
//            currentData.potassium    = (response[15] << 8) | response[16];
//            currentData.salinity     = (response[17] << 8) | response[18];
//            currentData.tds          = (response[19] << 8) | response[20];
//
//            sprintf(buffer, // @suppress("Float formatting support")
//                    "Temp: %.1f C\r\n"
//                    "Humidity: %.1f %%\r\n"
//                    "Nitrogen: %u\r\n"
//                    "Phosphorus: %u\r\n"
//                    "Potassium: %u\r\n\r\n",
//                    currentData.temperature,
//                    currentData.humidity,
//                    currentData.nitrogen,
//                    currentData.phosphorus,
//                    currentData.potassium);
//
//            //transmit data through uart
//
//            HAL_UART_Transmit(&huart2,
//                              (uint8_t*)buffer,
//                              strlen(buffer),
//                              100);
//        } else {
//            HAL_UART_Transmit(&huart2,
//                              (uint8_t*)"RX FAIL\r\n",
//                              9, 100);
//            return;
//        }
//    }
//}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
