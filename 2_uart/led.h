/*************************************************************************
    > File Name: led.h
    > 作者:YJK 
    > Mail: 745506980@qq.com 
    > Created Time: 2020年09月19日 星期六 18时22分50秒
 ************************************************************************/
#ifndef __LED_H
#define __LED_H 
#define GPL2CON		(*(volatile unsigned int *) 0x11000100)
#define GPL2DAT		(*(volatile unsigned int *) 0x11000104)
#define GPK1CON		(*(volatile unsigned int *) 0x11000060)
#define GPK1DAT		(*(volatile unsigned int *) 0x11000064)
void led(void);
#endif
