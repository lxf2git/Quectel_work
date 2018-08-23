#include<common.h>
#include<rtc.h>
struct time_st
{
	int year;
	int month;
	int day;
	int week;	
	int hour;
	int min;
	int sec;

};
void set_time(const struct time_st* pt);
void get_time(struct time_st* pt);
void delay(int ms);

int main() 
{
		struct time_st time = {15,11,30,1,10,23,10};
		RTCCON  |=(0x1);
		RTCCON  &=~(0x1);

		set_time(&time);
		while(1)
		{	
				get_time(&time);
				printf("20%dyear-%dmon-%dday-xingqi%d-%d:%d:%2d\r",
								time.year, time.month, time.day, time.week, time.hour, 
								time.min,time.sec);
				delay(1);
		}
	
}


void set_time(const struct time_st* pt)
{
	BCDYEAR &=~(0xff);
	BCDYEAR |=((pt->year/10)<<4)|((pt->year%10)<<0);
	
	BCDMON  &=~(0x1f);
	BCDMON  |=(pt->month/10)<<4|((pt->month%10)<<0);
	
	BCDDAY  &=~(0x1f);
	BCDDAY  |=((pt->day/10)<<4)|((pt->day%10)<<0);
	
	BCDDAYWEEK &=~(0x3);
	BCDDAYWEEK |= (pt->week%10)<<0;

	BCDHOUR   &=~(0x3f);

	BCDHOUR  |=((pt->hour/10)<<4)|((pt->hour%10)<<0);
	

	BCDMIN   &=~(0x3f);
	BCDMIN  |=(pt->min/10)<<4|((pt->min%10)<<0);

	BCDSEC   &=~(0x3f);
	BCDSEC  |=((pt->sec/10)<<4)|((pt->sec%10)<<0);

}


void get_time(struct time_st* pt)
{
	
	pt->year =((BCDYEAR &(0xf<<4))>>4)*10 + (BCDYEAR&0xf); 
	pt->month =((BCDMON &(0x1<<4))>>4)*10 + (BCDMON&0xf); 
	pt->day =((BCDDAY  &(0x3<<4))>>4)*10 + (BCDDAY&0xf); 
	pt->week = BCDDAYWEEK&(0x3);
	
	pt->hour =((BCDHOUR &(0x3<<4))>>4)*10 + (BCDHOUR&0xf); 
	pt->min =((BCDMIN &(0x3<<4))>>4)*10 + (BCDMIN&0xf); 
	pt->sec =((BCDSEC &(0x7<<4))>>4)*10 + (BCDSEC&0xf); 
	
}

void delay(int ms)
{
	int i, j;

	for (i=0; i<100*ms; i++)
	{
		for (j=0; j<1000; j++);
	}
}
