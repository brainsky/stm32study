#include "key.h"
#include "sys.h"
#include "stm32f10x.h"

void Key_GPIO_Config(void){
	
	
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	//开启PA | PC 的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC, ENABLE);
	
	//关闭jtag, 开启swd。因为pa15脚与jtag复用了
	//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	
		//设置pin15脚
	//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	
	//设置上拉输入
	//GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	
	//GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		//设置pin5脚
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	
	//设置上拉输入
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
}

u8 Scan_Key(GPIO_TypeDef * GPIOx, u16 GPIO_Pin){
	
	if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON){
		
		  delay_ms(100);
		 	if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON){
					while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON);
								return KEY_ON;
			}else{
				return KEY_OFF;
			}
	}else{
			return KEY_OFF;
	}
	
}