#include<common.h>
#include<set_rtc.h>
#include<irq_tic.h>
#include<beep.h>

extern int start;
extern int end;

void set_time(const struct time_st* pt);
void get_time(struct time_st* pt);
void delay(int ms);
void irq_processor();
void memcpy(char *dest, const char *src, int n);
void mmu_enable(void);
void mmap(unsigned long* ttb, unsigned long va,unsigned long pa);
void mem_init(unsigned long* ttb);
void mmu_init();
void mmu_map();
void irq_tic();

int main() 
{
		mmu_map();
		memcpy((void*)0xffff0018,(void*)start, end -start); //中断函数存放在向量表
		irq_processor();    
		struct time_st set_t = {15,11,30,1,10,23,10};
		set_time(&set_t);
		irq_tic();
		while(1)
		{
			get_time(&set_t);
				printf("20%dyear-%dmon-%dday-xingqi%d-%d:%d:%2d\r",
								set_t.year, set_t.month, set_t.day, set_t.week, set_t.hour, 
								set_t.min,set_t.sec);
				delay(1);
		
		}
}

void set_time(const struct time_st* pt)
{

	RTCCON  |=(0x1);
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
	RTCCON  &=~(0x1);
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



void irq_processor()
{
		__asm__ __volatile__(
						"cpsie i\n\t"                           //开中断
						);

		/******CPU INterface****/
		ICCICR_CPU0=1;    //786
		ICCPMR_CPU0=255;   //786
		/*******GIC(中断分配器) ********/
		ICDDCR=1;  // 794
}


void memcpy(char *dest, const char *src, int n)
{
		while(n--)
				*dest++=*src++;

}


/**********mmu***************/

void mmu_enable(void)
{
		__asm__ __volatile__(

						"mrc p15,0,r0,c1,c0,0\n\t"
						"orr r0,r0,#1\n\t"
						"orr r0,r0,#(1<<13)\n\t"
						"mcr p15,0,r0,c1,c0,0\n\t"
						:
						:
						:"r0"
						);
}

void mmap(unsigned long* ttb, unsigned long va,unsigned long pa)
{
		ttb[va>>20]=(pa&0xfff00000)|2;
}
void mem_init(unsigned long* ttb)
{
		unsigned  long pa,va;
		for(pa=0x00000000;pa<0x14000000;pa+=0x100000)
		{ va=pa;
				ttb[va>>20]=(pa&0xfff00000)|2;
		}

		for(pa=0x40000000;pa<0x80000000;pa+=0x100000)
		{
				va=pa;
				ttb[va>>20]=(pa&0xfff00000)|2;

		}

}

void mmu_map()
{

		unsigned long *va=(void*)0xffff0018;
		unsigned long *pa=(void*)0x7fff0018;
		mmu_init();
		mmu_enable();
		mmap((void*)0x70000000,(unsigned long)va,(unsigned long)pa);

}

void mmu_init()
{
		unsigned long* ttb=(void*)0x70000000;

		mem_init(ttb);

		__asm__ __volatile__(
						" mvn r0,#0x0\n\t"
						"mcr  p15,0,r0,c3,c0,0\n\t"
						"mcr  p15,0,%0,c2,c0,0\n\t"
						:
						:"r"(ttb)
						:"r0"

						);
}

void delay(int ms)
{
	int i, j;

	for (i=0; i<100*ms; i++)
	{
		for (j=0; j<1000; j++);
	}
}

#if 0
void do_alarm()
{
	printf("I am is alarm\n");	
	INTP |=1<<1; 
}
#endif 

void do_tic()
{
	GPD0CON  |=0x1111;
	GPD0DAT  |=0xf;
	delay(1);
	GPD0DAT  &=~(0xf);

	INTP = 1;
}

void do_irq(void)
{
		unsigned int icciar_cpu0 = ICCIAR_CPU0;
		switch((icciar_cpu0 & 0x3ff))
		{   
				case 76: 
					//	do_alarm();
						break;
				case 77:
						do_tic();
				default:
						break;
		}   
		ICCEOIR_CPU0 = icciar_cpu0;
}


