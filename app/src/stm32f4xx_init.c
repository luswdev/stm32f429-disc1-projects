/**
  ******************************************************************************
  * @file    stm32f4xx_init.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    20-September-2013
  * @brief   Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_init.h"

/** @addtogroup Template
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define LEDn                             2
  
#define LED3_PIN                         GPIO_Pin_13
#define LED3_GPIO_PORT                   GPIOG
#define LED3_GPIO_CLK                    RCC_AHB1Periph_GPIOG  

#define LED4_PIN                         GPIO_Pin_14
#define LED4_GPIO_PORT                   GPIOG
#define LED4_GPIO_CLK                    RCC_AHB1Periph_GPIOG  

#define BUTTONn                          1

/**
 * @brief Wakeup push-button
 */
#define USER_BUTTON_PIN                GPIO_Pin_0
#define USER_BUTTON_GPIO_PORT          GPIOA
#define USER_BUTTON_GPIO_CLK           RCC_AHB1Periph_GPIOA
#define USER_BUTTON_EXTI_LINE          EXTI_Line0
#define USER_BUTTON_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOA
#define USER_BUTTON_EXTI_PIN_SOURCE    EXTI_PinSource0
#define USER_BUTTON_EXTI_IRQn          EXTI0_IRQn 

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
GPIO_TypeDef* GPIO_PORT[LEDn] = {LED3_GPIO_PORT, LED4_GPIO_PORT};
const uint16_t GPIO_PIN[LEDn] = {LED3_PIN, LED4_PIN};
const uint32_t GPIO_CLK[LEDn] = {LED3_GPIO_CLK, LED4_GPIO_CLK};

GPIO_TypeDef* BUTTON_PORT[BUTTONn] = {USER_BUTTON_GPIO_PORT}; 

const uint16_t BUTTON_PIN[BUTTONn] = {USER_BUTTON_PIN}; 

const uint32_t BUTTON_CLK[BUTTONn] = {USER_BUTTON_GPIO_CLK};

const uint16_t BUTTON_EXTI_LINE[BUTTONn] = {USER_BUTTON_EXTI_LINE};

const uint8_t BUTTON_PORT_SOURCE[BUTTONn] = {USER_BUTTON_EXTI_PORT_SOURCE};
								 
const uint8_t BUTTON_PIN_SOURCE[BUTTONn] = {USER_BUTTON_EXTI_PIN_SOURCE}; 
const uint8_t BUTTON_IRQn[BUTTONn] = {USER_BUTTON_EXTI_IRQn};
/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/**
  * @brief   Main program
  * @param  None
  * @retval None
  */
void Delay_Init(void)
{
    RCC_ClocksTypeDef RCC_Clocks;
    RCC_GetClocksFreq(&RCC_Clocks);    /* get system clock */
    /* while loop takes 4 cycles */
    /* Enable SysTick for Delay function */
    if (SysTick_Config(SystemCoreClock / 1000)) //1ms
    { 
        /* Capture error */ 
        while (1);
    }
}

void LED_Init(Led_TypeDef Led)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  
  /* Enable the GPIO_LED Clock */
  RCC_AHB1PeriphClockCmd(GPIO_CLK[Led], ENABLE);

  /* Configure the GPIO_LED pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_PIN[Led];
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIO_PORT[Led], &GPIO_InitStructure);
}

void LED_Toggle(Led_TypeDef Led)
{
  GPIO_PORT[Led]->ODR ^= GPIO_PIN[Led];
}

void LED_On(Led_TypeDef Led)
{
  GPIO_PORT[Led]->BSRRL = GPIO_PIN[Led];
}

void LED_Off(Led_TypeDef Led)
{
  GPIO_PORT[Led]->BSRRH = GPIO_PIN[Led];  
}

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
