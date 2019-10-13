#ifndef __SYS_H
#define __SYS_H

#define unit8  unsigned char
#define unit16 unsigned short int	
#define unit32 unsigned int
static unit8  fac_us=0;//us延时倍乘数
static unit16 fac_ms=0;//ms延时倍乘数

void delay_ms(unit32 ms);
void delay_init(void);

#endif
