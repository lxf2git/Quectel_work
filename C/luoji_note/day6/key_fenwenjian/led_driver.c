
#include<stdio.h>
int led_driver(int opt, int led)
{
	if (opt==EN)
	{
      	GPM4DAT &=~(0x1<<led);
	}
	else if(opt == DEN)
	{
		GPM4DAT |=(0x1<<led);
	}
	return 0;
}
