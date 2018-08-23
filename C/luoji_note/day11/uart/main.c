#include <common.h> //printf
#include <uart.h>
int main()
{
	 char arr='a';
	 uart_init();
	 uart_send(arr);   // 
	return 0;
}
