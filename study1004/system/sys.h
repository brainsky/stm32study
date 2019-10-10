#ifndef __SYS_H
#define __SYS_H

#define u8  unsigned char
#define u16 unsigned short int	
#define u32 unsigned int
static u8  fac_us=0;//us延时倍乘数
static u16 fac_ms=0;//ms延时倍乘数

void delay_ms(u32 ms);
void delay_init(void);

#endif
