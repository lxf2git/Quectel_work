
#include<adc.h>
int adc_init(void)
{
	ADCCON &=~(0xff<<6);
	ADCCON |=(0xf0<<6); // A/D converter prescaler value Data value: 0xf0
	ADCCON |=(0x1<<14); // A/D converter prescaler enable 
	ADCCON &=~(0x1<<16);//0 = 10 bt A/D conversion 
	ADCCON &=~(0x1<<2);
	ADCDLY &=~(0xffff);
	ADCDLY |=(0xff);
	ADCMUX =0x00;
}
