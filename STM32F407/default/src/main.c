#include "common.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

#define LED1 PFout(10)
#define LED0 PFout(9)

void Init_Clock()
{
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
}

void Init_IO()
{
  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOF, &GPIO_InitStructure);
}

int main() {
  Init_Clock();
  Init_IO();
  while (1)
  {
    LED0 = 0;
    Delay_ms(300);
    LED1 = 0;
    Delay_ms(100);
    LED1 = 1;
    Delay_ms(100);
    LED0 = 1;
    Delay_ms(300);
    LED1 = 0;
    Delay_ms(100);
    LED1 = 1;
    Delay_ms(100);
  }
}
