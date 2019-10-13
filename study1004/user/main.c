#include "led.h"
#include "sys.h"
#include "stm32f10x_gpio.h"

int main()
{
	delay_init();
	
	LED_Init();
	
	while(1){
		
		GPIO_ResetBits(GPIOA, GPIO_Pin_8);
		
		GPIO_ResetBits(GPIOD, GPIO_Pin_2);
		
		delay_ms(300);
		
		GPIO_SetBits(GPIOD, GPIO_Pin_2);
		
		GPIO_SetBits(GPIOA, GPIO_Pin_8);
		
		delay_ms(300);
	}
	
}

