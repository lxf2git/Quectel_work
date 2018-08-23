


#include<uart.h>

void uart_init();
void send_uart(char* arr);
int main() 
{
	char arr[] = "hello world!";
	uart_init();
	send_uart(arr);
}
