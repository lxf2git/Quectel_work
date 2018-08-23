
#include<common.h>
#include<irq_tic.h>
#include<set_rtc.h>
void  irq_tic()
{
	ICDISER2 |=0x1<<(77-64);
	ICDIPR19 &=~(0xff<<8);
   	ICDIPTR19 |=0x1<<8;

	TICNT   = 2;
	RTCCON  |=(0x1<<8)|(0xc<<4);
}	



		
