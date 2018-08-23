
#include<adc.h>
#include<common.h>
int adc_end()
{
	if (((ADCCON &(0x1<<15))>>15) == 1)
	{
		return  END;
	}	
	else
	{
		return PROCESS;
	}
}
