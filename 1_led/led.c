/*************************************************************************
    > File Name: led.c
    > 作者:YJK 
    > Mail: 745506980@qq.com 
    > Created Time: 2020年09月19日 星期六 18时28分16秒
 ************************************************************************/

#include"led.h"

void desplay(void)
{
	volatile int x = 0xFFFF;
	while (x--);
}
void led(void)
{
		GPL2CON = 0x00000001;
		GPK1CON = 0x00000010;  /*设置为输出模式*/
		while(1)
		{
			GPL2DAT = 0x1;
			GPK1DAT = 0x2;
			desplay();	
			GPL2DAT = 0;
			GPK1DAT = 0;		
			desplay();
		}	
}
