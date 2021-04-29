
#include <DHT22.h>
#include "timer.h"
#include "stm32l1xx_hal.h"

void Data_Output (GPIO_TypeDef *PORT, uint16_t PIN)
  {
  	GPIO_InitTypeDef GPIO_InitStruct = {0};

  	GPIO_InitStruct.Pin = PIN;
  	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; //pushpull
  	HAL_GPIO_Init(PORT, &GPIO_InitStruct);
  }

void Data_Input (GPIO_TypeDef *PORT, uint16_t PIN)
  {
  	GPIO_InitTypeDef GPIO_InitStruct = {0};

  	GPIO_InitStruct.Pin = PIN;
  	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  	HAL_GPIO_Init(PORT, &GPIO_InitStruct);
  }

void Read_data (uint8_t *data)
  {
  	int i, k;
  	for (i=0;i<8;i++)
  	{
  		if (HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_0) == GPIO_PIN_RESET)    // if the pin is low
  		{
  			(*data)&= ~(1<<(7-i));   // write 0
  			while(!(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)));
  			DWT_Delay_us(40);
  		}
  		else
  		{
  			(*data)|= (1<<(7-i));  // if the pin is high, write 1
  			for (k=0;k<100;k++)
  			{
  				if (HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_0) == GPIO_PIN_RESET)
  				  {
  				  	break;
  				  }
  			}
  			while(!(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)));
  			DWT_Delay_us(40);
  		}
  	 }
  }
