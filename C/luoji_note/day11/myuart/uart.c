

#include<uart.h>
#include<common.h>

void delay()
{
	int i, j;

	for (i=0; i<1000; i++)
	{
		for (j=0; j<1000; j++);
	}
}

void send_uart(char* arr)
{
		char *p = arr;
		printf("sdfsd");
		while(1)
		{
				UTXH0 =*p++;
				while(!(UTRSTAT0 &(0x1<<1)));
				delay();
				if (*p == '\0')
				{
						p = arr;
					//	break;
				}
		}

}



void uart_init()
{
	//引脚设置
	GPA0CON  |= 0x22;

	//设置 数据位位数 流控等
	//Indicates the number of data bits UART transmits or receives 
	//per frame. 
	ULCON0   |=0x3;
	
	UMCON0   &=~(0x1<<4);

	//URT 工作模式		
	//Determines which function is able to Write Tx data to the 
	//UART transmit buffer. 
	UCON0  |=0x1<<2|1;

	UFCON0 &=~(0x1);

	// 1 设置波特率
	UBRDIV0   = 53; 
	UFRACVAL0 = 3;

}



