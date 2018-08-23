#include<stdio.h>
#include<led.h>
#include<pwm_isr.h>

extern int start;
extern int end;

void delay(int ms);
void irq_processor();
void memcpy(char *dest, const char *src, int n);
void mmu_enable(void);
void mmap(unsigned long* ttb, unsigned long va,unsigned long pa);
void mem_init(unsigned long* ttb);
void mmu_init();
void mmu_map();
void irq_pwm(int tcnt, int tcmp);

int main() 
{
		mmu_map();
		memcpy((void*)0xffff0018,(void*)start, end -start); //中断函数存放在向量表
		irq_processor();    
		irq_pwm(250000, 100000);
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


void do_pwm()
{	
	printf("[%s = %d line] \n", __FUNCTION__, __LINE__ ); 
	GPM4CON |=0x1111;
	GPM4DAT &=~0xf;
	delay(1);
	GPM4DAT |=0xf;
	TINT_CSTAT |=0x1<<5;
}

void do_irq(void)
{
		unsigned int icciar_cpu0 = ICCIAR_CPU0;
		switch((icciar_cpu0 & 0x3ff))
		{   
				case 76: 
					//	do_alarm();
						break;
				case 69:
						do_pwm();
						break;
				default:
						break;
		}   
		ICCEOIR_CPU0 = icciar_cpu0;
}


