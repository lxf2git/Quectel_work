#define  GPX3CON  (*((volatile unsigned long*)0x11000c60))
#define  GPX3DAT  (*((volatile unsigned long*)0x11000c64))

#define GPM4CON 	(*((volatile unsigned long*)0x110002e0))
#define  GPM4DAT    ((*(volatile unsigned long*)0x110002e4))

#define  SET_BIT(x, n) 	 x |= (0x1<<n)
#define  CLEAR_BIT(x, n) x &=~(0x1<<n)
#define  GET_BIT(x, n)   ((x &(0x1<<n))>>n)

int (* printf)(const char *, ...) = (void* )0x43e11a2c;
int delay(unsigned int ms);


int _start()
{
	//按键引脚输出
	GPX3CON &=~(0xffff<<8);
	//小灯引脚输出
	GPM4CON =0x1111;
	
	while(1)
	{
		if (GET_BIT(GPX3DAT, 2) == 1)
		{
		//	printf("key1 is up\n");
			GPM4DAT |=(0x1<<0);
		}
		else
		{	
			delay(2);
			printf("key1 is down\n");
			GPM4DAT &=~(0x1<<0);
		}	
		if (GET_BIT(GPX3DAT, 3) == 1)
		{
			//printf("key2 is up\n");
			//
			GPM4DAT |=(0x1<<1);
		}
		else
		{
			delay(2);
			printf("key2 is down\n");
			GPM4DAT &=~(0x1<<1);
		}
		
		if (GET_BIT(GPX3DAT, 4) == 1)
		{
			//printf("key4 is up\n");
			GPM4DAT |=(0x1<<2);
		}
		else
		{
			delay(2);
			printf("key3 is down\n");
			GPM4DAT &=~(0x1<<2);
		}
		
		if (GET_BIT(GPX3DAT, 5) == 1)
		{
			//printf("key5 is up\n");
			GPM4DAT |=(0x1<<3);
		}
		else
		{
			delay(2);
			printf("key4 is down\n");
			GPM4DAT &=~(0x1<<3);
		}
		
	}	

}

int delay(unsigned int ms)
{
	int i=0;
	int j=0;
	for (i=0; i<ms*100; i++)
	{
		for(j=0; j<1000; j++)
		{
			;
		}
	}
}




