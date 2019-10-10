#include "sys.h"
#include "stm32f10x.h"

void delay_ms(u32 ms){
	u32 temp;
	SysTick->LOAD=9000*ms;      //设置重装数值, 72MHZ时
  SysTick->CTRL=0X01;        //使能，减到零是无动作，采用外部时钟源
  SysTick->VAL=0;            //清零计数器
  do
  {
		temp=SysTick->CTRL;       //读取当前倒计数值
	}
  while((temp&0x01)&&(!(temp&(1<<16))));    //等待时间到达
  SysTick->CTRL=0;    //关闭计数器
  SysTick->VAL=0;
	
}

void delay_init() { 
	#if SYSTEM_SUPPORT_OS      //如果需要支持 OS.  
		u32 reload; 
	#endif  
	  SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8); //选择外部时钟  HCLK/8  
	  fac_us=SystemCoreClock/8000000;  //为系统时钟的 1/8   
	#if SYSTEM_SUPPORT_OS      //如果需要支持 OS.  
	  reload=SystemCoreClock/8000000;       //每秒钟的计数次数 单位为 K      
	  reload*=1000000/delay_ostickspersec;  //根据 delay_ostickspersec 设定溢出时间     
	  //reload 为 24 位寄存器,最大值:16777216,在 72M 下,约合 1.86s 左右   
	  fac_ms=1000/delay_ostickspersec;  //代表 OS 可以延时的最少单位      
	  SysTick->CTRL|=SysTick_CTRL_TICKINT_Msk;    //开启 SYSTICK 中断  
	  SysTick->LOAD=reload;   //每 1/delay_ostickspersec 秒中断一次   
	  SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk;    //开启 SYSTICK     
	#else  
	  fac_ms=(u16)fac_us*1000;  //非 OS 下,代表每个 ms 需要的 systick 时钟数    
	#endif 
}
