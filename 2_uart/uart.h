#ifndef __UART_H
#define __UART_H

union br_rest {
	unsigned short	slot;		/* udivslot */
	unsigned char	value;		/* ufracval */
};

struct s5p_uart {
	unsigned int ulcon;
	unsigned int ucon;
	unsigned int ufcon;
	unsigned int umcon;
	unsigned int utrstat;
	unsigned int uerstat;
	unsigned int ufstat;
	unsigned int umstat;
	unsigned char utxh;
	unsigned char res1[3];
	unsigned char urxh;
	unsigned char res2[3];
	unsigned int ubrdiv;
	union br_rest rest; 
	unsigned char res3[0xffd0];
};
/*GPIO*/
#define GPA1CON					(*(volatile int *) 0x11400020)
#define GPADAT					(*(volatile int *) 0x11400024)
/*uart*/
#define UART1_BASE				(*(volatile int *) 0x13820000)
#define UART1_ULCON				(*(volatile int *) 0x13820000)
#define UART1_UCON				(*(volatile int *) 0x13820004)
#define UART1_DIV				(*(volatile int *) 0x13820028)
#define UART1_UFRACVAL			(*(volatile int *) 0x1382002C)
#define UTXH					(*(volatile int *) 0x13820020)
#define URXH					(*(volatile int *) 0x13820024)
#define UTRSTAT					(*(volatile int *) 0x13820010)
/*MPLL*/
#define CLK_SRC_DMC				(*(volatile int *) 0x10040200)
#define MPLL_CON0				(*(volatile int *) 0x10040108)
#define CLK_SRC_TOP1			(*(volatile int *) 0x1003C214)
//uart clock 
#define CLK_DIV_PERIL0			(*(volatile int *) 0x1003C550)
#define CLK_SRC_PERIL0			(*(volatile int *) 0x1003C250)

void clock(void);
void uart(void);
void myput(char c);
void mystring(char *str);
#endif
