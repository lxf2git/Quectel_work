#include <common.h>
#include<eint.h>
#include<wdt.h>
void mem_init(unsigned long* ttb);
void mmu_init(void);
void mmu_enable(void);
void mmap(unsigned long* ttb, unsigned long va,unsigned long pa);
void memcpy(char *dest, const char *src, int n);
void wdt_init(int ms);
void wdt_eint_enable();
void wdt_enable();
void do_wdt();
void irq_wdt();
void mmu_map();
void irq_processor();

extern int start;
extern int end;

int main()
{
			mmu_map();
		  memcpy((void*)0xffff0018,(void*)start, end -start); //中断函数存放在向量表
			irq_processor();	
			irq_wdt();
			irq_key();

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

/*******wdt*************/

void wdt_init(int ms) //100M/(99+1) = 1M;    1024*1024/128 = 1024*8 HZ;  
{
	WTCON &=~(0xff<<8);
	WTCON |=99<<8;
	WTCON |=(0x11<<3);
   	WTCON &=~(0x1<<0);	
	WTCNT = ms*8;
	WTDAT = ms*8;
}
void wdt_eint_enable()
{
	WTCON |=(0x1<<2);
	
}
void wdt_enable()
{
	WTCON |=(0x1<<5);
}

void do_wdt()
{
	printf(" wdt \n");
	
	WTCLRINT = 1;

}
void do_irq(void)
{
	unsigned int icciar_cpu0 = ICCIAR_CPU0;
	switch((icciar_cpu0 & 0x3ff))
	{
		case 75:
				do_wdt();
				break;
		default:
				break;
	}

	ICCEOIR_CPU0 = icciar_cpu0;

}

void irq_wdt()
{

		  /*******中断源***********/
		  ICDISER2=1<<(75-64);  	        	//使能中断源 748   780   801
		  ICDIPR18 &=~(0xff<<24);            // (值越低，优先级越大) 748  781   812  
		  ICDIPTR18=1<<24; 				  // 782     中断源对应的处理器0   815   
		 wdt_init(5000);
		 wdt_eint_enable();
		 wdt_enable();
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

void mmu_init(void)
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

