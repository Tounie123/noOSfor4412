/*************************************************************************
    > File Name: main.c
    > 作者:YJK 
    > Mail: 745506980@qq.com 
    > Created Time: 2020年09月04日 星期五 17时53分51秒
 ************************************************************************/

#include"uart.h"
#include"led.h"
int main(int argc,char *argv[])
{
	clock();
	uart();
	myput('h');
	myput('h');
	mystring("hello world\n");	
	led();
	return 0;
}
