

#include<adc.h>
int adc_start()
{
	
	ADCCON |=(0x1<<0); //1 = A/D conversion starts and this bit is automatically cleared 
//	after the start-up. 
			
	return 0;
}
