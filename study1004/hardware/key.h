#ifndef __KEY_H
#define __KEY_H
#include "stm32f10x.h"

#define KEY_ON unit8 1; //按下的值

#define KEY_OFF unit8 0; //松开的值

//按键配置
void Key_GPIO_Config(void);
	
//扫描按键
u8 Scan_Key(GPIO_TypeDef * GPIOx, u16 GPIO_Pin);

#endif

	