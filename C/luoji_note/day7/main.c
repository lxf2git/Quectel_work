#include<common.h> //printf
#include<delay.h>   //delay
#include <adc.h>  //adc 

int main() 
{
	adc_init();
	while(1)
	{

			adc_start();
			while((adc_end()) !=END)
			{
				;
			}
			delay(4);
	}
	return 0; 
}
