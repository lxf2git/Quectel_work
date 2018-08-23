#ifndef _STDIO_H

#define  printf(...)  (((int(*)(const char* format, ...))0x43e11a2c)(__VA_ARGS__))
#define  GPX3CON  (*((volatile unsigned long*)0x11000c60))
#define  GPX3DAT  (*((volatile unsigned long*)0x11000c64))

#define GPM4CON 	(*((volatile unsigned long*)0x110002e0))
#define  GPM4DAT    ((*(volatile unsigned long*)0x110002e4))
#define  GET_BIT(x, n)   ((x&(0x1<<n))>>n)

enum
{	
		K1 =2,
		K2,	
		K3,
		K4,
};
enum
{
		LED1 =0,
		LED2,
		LED3,
		LED4,
};
enum
{
		EN=0,
		DEN,
};

#endif 
