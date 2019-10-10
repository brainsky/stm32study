#include "led.h"
#include <stm32f10x.h>

//初始化LED0和LED1

void LED_Init(void){
	
	GPIO_InitTypeDef  GPIO_InitStructure;
	//使能PA、PD时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOD, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	
	
}