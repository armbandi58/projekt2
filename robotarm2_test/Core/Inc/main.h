/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <math.h>
#include <inttypes.h>
#include <stdbool.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef unsigned char uch;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef volatile uint8_t v8;
typedef volatile bool vb;

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define btn_Pin GPIO_PIN_13
#define btn_GPIO_Port GPIOC
#define LCD_Rs_Pin GPIO_PIN_7
#define LCD_Rs_GPIO_Port GPIOE
#define LCD_E_Pin GPIO_PIN_10
#define LCD_E_GPIO_Port GPIOE
#define LCD_DATA_4_Pin GPIO_PIN_12
#define LCD_DATA_4_GPIO_Port GPIOE
#define LCD_DATA_5_Pin GPIO_PIN_14
#define LCD_DATA_5_GPIO_Port GPIOE
#define LCD_DATA_6_Pin GPIO_PIN_15
#define LCD_DATA_6_GPIO_Port GPIOE
#define LCD_DATA_7_Pin GPIO_PIN_10
#define LCD_DATA_7_GPIO_Port GPIOB
#define led_red_Pin GPIO_PIN_14
#define led_red_GPIO_Port GPIOB
#define led_blue_Pin GPIO_PIN_7
#define led_blue_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
