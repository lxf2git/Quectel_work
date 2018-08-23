#include <uart.h>

void wait_send(void)
{
	  while( !(UTRSTAT0 &2)) ;

}
void uart_send(char arr)
{
		UTXH0=arr;
		 wait_send();


}
void uart_init(void)
{
	/*******设置引脚**************/
	  GPA0CON |=0x22;   // 116
	 /******数据位宽度  8位**********/
	  ULCON0=3;   // 1385 
	  
      UCON0=(1<<2)|1;  // 设置工作模式为中断或polling 

	  UFCON0=0;    // 关闭FIFO

	  UMCON0=0;   // 关闭 流控

	  UBRDIV0=53;    // 442   1399   设置波特率 115200   
      UFRACVAL0=4;
}
