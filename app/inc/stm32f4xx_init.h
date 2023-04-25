/**
  ******************************************************************************
  * @file    stm32f4xx_clock.h  
  * @author  MCD Application Team
  * @version V1.0.1
  * @date    11-November-2013
  * @brief   Library configuration file.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4xx_INIT_H
#define __STM32F4xx_INIT_H

/* Includes ------------------------------------------------------------------*/
/* Uncomment the line below to enable peripheral header file inclusion */
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"

/* Exported types ------------------------------------------------------------*/
typedef enum 
{
  LED3 = 0,
  LED4 = 1
} Led_TypeDef;

typedef enum 
{  
  BUTTON_USER = 0,
} Button_TypeDef;

typedef enum 
{  
  BUTTON_MODE_GPIO = 0,
  BUTTON_MODE_EXTI = 1
} ButtonMode_TypeDef;

/* Exported constants --------------------------------------------------------*/


/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */
void Delay_Init(void);
void LED_Init(Led_TypeDef Led);

void LED_Toggle(Led_TypeDef Led);
void LED_On(Led_TypeDef Led);
void LED_Off(Led_TypeDef Led);

#endif /* __STM32F4xx_INIT_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
