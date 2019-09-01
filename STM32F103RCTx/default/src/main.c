#include "common.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

#define LED PAout(8)

int main (void) {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	while(1)
	{
		LED ^= 1;
		Delay_ms(200);
	}
}
