
#include<common.h>
#include<irq_alarm.h>
void alarm_enable();
void alarm_set(const struct time_st* pt);
void  irq_alarm(const struct time_st* pt)
{
	//
	ICDISER2 |=0x1<<(76-64);
	ICDIPR19 &=~(0xff);
 	ICDIPTR19 |=(0x1);	


	alarm_enable();
	alarm_set(pt);

}

void alarm_enable()
{
	RTCALM  |=(0x7<<0)|(0x1<<6); //使能 hour , min , sec 
}
void alarm_set(const struct time_st* pt)
{
	//INTP  |= 1<<2;
	ALMHOUR |=((pt->hour/10)<<4)|(pt->hour%10);
	ALMMIN |=((pt->min/10)<<4)|(pt->min%10);
	ALMSEC |=((pt->sec/10)<<4)|(pt->sec%10);


}
