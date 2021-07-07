#include"uart.h"
#include"led.h"

void clock(void)
{
	
	// 设置MPLL 
	CLK_SRC_DMC = 0x01000; //配置MUXMPLL 使用FOUT
	MPLL_CON0 =	0x80640300; // M 100 P 3 S 0;
	CLK_SRC_TOP1 = 0x01000; 
	CLK_SRC_PERIL0 = 0x66666;
	CLK_DIV_PERIL0 = 0x77777;
}
void uart(void)
{
	GPA1CON = 0x00000022; //设置GPIO 
	/*	串口初始化 */
	UART1_ULCON = 0x00000003;
	UART1_UCON = 0x00000005;// 设置接收和发送模式为中断或轮询 
	UART1_DIV = 53;
	UART1_UFRACVAL = 4;

}
/*设置receive transmits buff*/

void myput(char c)
{
	/*
		等待当前发送完成
		然后再发送下次的数据
	*/
	while (!((UTRSTAT) & (0x1<<2))); //第二位为1的时候表示为空  为0 表示非空 
	UTXH = c;
}
void mystring(char *str)
{
	while(*str)
	{
		myput(*str);
		str++;
	}
}

