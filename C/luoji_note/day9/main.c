#include <common.h>
#include<eint.h>
#include<key.h>

void mem_init(unsigned long* ttb);
void mmu_init(void);
void mmu_enable(void);
void mmap(unsigned long* ttb, unsigned long va,unsigned long pa);
void memcpy(char *dest, const char *src, int n);

extern int start;
extern int end;

int main()
{
	   unsigned long *va=(void*)0xffff0018;
	   unsigned long *pa=(void*)0x7fff0018;

		  mmu_init();
		  mmu_enable();
		  mmap((void*)0x70000000,(unsigned long)va,(unsigned long)pa);
		  memcpy((void*)0xffff0018,(void*)start, end -start); //中断函数地址存放在向量表

	    __asm__ __volatile__(
					"cpsie i\n\t"                           //开中断
				);	   

		/******CPU INterface****/
	     ICCICR_CPU0=1;    //786
		 ICCPMR_CPU0=255;   //786
		/*******GIC(中断分配器) ********/
  		ICDDCR=1;  // 794

		/*******中断源***********/
		ICDISER2=1<<(64-64);  	        //使能中断源 748   780   801
		 ICDIPR18 &=~0xff;             // (值越低，优先级越大) 748  781   812  
		 ICDIPTR18=1;     // 782     中断源对应的处理器0   815    

		 /******按键***********/
         GPX3CON  |=0xf<<8;       // 设置成中断 357 
		 EXT_INT43CON |=2<<8;    // 触发条件 366 
         EXT_INT43_MASK &=~(1<<2); //使能 379
 }

void do_irq(void)
{
		if(EXT_INT43_PEND &(1<<2) )  // 383 
			  printf("key down\n");
		    EXT_INT43_PEND=EXT_INT43_PEND|(1<<2); // 清中断 1362 

}


  void memcpy(char *dest, const char *src, int n)
{
			while(n--)
				*dest++=*src++;

}
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
