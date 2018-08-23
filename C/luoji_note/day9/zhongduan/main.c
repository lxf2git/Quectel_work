#include<common.h>
#include<eint.h>
#include<key.h>

extern int start;
extern int end;

void mmu_init();
void mem_init(unsigned long* ttb);
void mmu_enable();
void mmap(unsigned long* ttb, unsigned long va, unsigned long pa);
void memcpy(char* dest, const char* src, int size);
void irq_init(void);
void delay();



int main() 
{

	unsigned long* va =(void*)0xffff0018;
	unsigned long* pa =(void*)0x7fff0018;
	mmu_init();
	mmu_enable();
	mmap((unsigned long*)0x70000000, (unsigned long)va, (unsigned long)pa);
	irq_init();
	
}


void mem_init(unsigned long* ttb)
{
	unsigned long pa, va;

	for (pa=0x00000000; pa< 0x80000000; pa +=0x100000)
	{
		va = pa;
		ttb[va>>20] = pa|2;
	}

}

void mmu_init()
{
		unsigned long* ttb = (void* )0x70000000;
		mem_init(ttb);

		__asm__ __volatile__(
						"mvn r0, #0x0;"
						"mcr p15, 0, r0, c3, c0, 0;"
						"mcr p15, 0, %0, c2, c0, 0; "
						:
						:"r"(ttb)
						:"r0"
						);

}

void mmu_enable()
{
	__asm__ __volatile__(
					"mrc p15, 0, r0, c1, c0, 0;"
					"orr r0, r0, #1;"      //开启MMU
					"orr r0, r0, #(1<<13);" //开启高地址向量表
					"mcr p15, 0, r0, c1, c0, 0;"
					);

}

void mmap(unsigned long* ttb, unsigned long va, unsigned long pa)
{
	ttb[va>>20] = ttb[pa>>20];
}


void memcpy(char* dest, const char* src, int size)
{

	while(size--)
	{
		*dest++ = *src++;
	}

}

// 设置中断
void irq_init(void)
{	
	
	memcpy((void*)0xffff0018, (void*)start, end - start);
	__asm__ __volatile__(
					"cpsie i;"
					);

		/******CPU interface****/	
		ICCICR_CPU0=1;  				  //786
        ICCPMR_CPU0=255;   				//786
        /*******GIC(中断分配器) ********/
        ICDDCR=1;  						// 794

        /*******中断源***********/
        ICDISER2=1<<(64-64);            //使能(查看原理图)中断源 748   780   801
         ICDIPR16 &=~0xff;             // (值越低，优先级越大) 748  781   812  
         ICDIPTR16=1;     // 782         中断源对应的处理器0   815    

         /******按键***********/
         GPX3CON  |=0xffff<<8;    	   // 设置成中断 357  //k1, k2, k3, k4;
         EXT_INT43CON |=2<<8;   	 //k1 触发条件 366 
         EXT_INT43CON |=2<<12;   	 //k2 触发条件 366 
         EXT_INT43CON |=2<<16;   	 //k3 触发条件 366 
         EXT_INT43CON |=2<<20;   	 //k4 触发条件 366 

         EXT_INT43_MASK &=~(0xf<<2); 	//使能 379
}


//中断处理函数

void deal_irq()
{	

		if ((EXT_INT43_PEND &(1<<2)) >>2)
		{
				delay();
				if ((EXT_INT43_PEND &(1<<2)) >>2)
				{
						printf("key 1 down\n");
						EXT_INT43_PEND |=(1<<2); 
				}
		}

		if ((EXT_INT43_PEND &(1<<3))>>3)
		{
				delay();
				if ((EXT_INT43_PEND &(1<<3))>>3)
				{
						printf("key2 down\n");
						EXT_INT43_PEND |=(1<<3); 
				}
		}

		if ((EXT_INT43_PEND &(1<<4))>>4)
		{

				delay();
				if ((EXT_INT43_PEND &(1<<4))>>4)
				{
						printf("key3 down\n");
						EXT_INT43_PEND |=(1<<4); 
				}
		}
		if ((EXT_INT43_PEND &(1<<5))>>5)
		{
				delay();
				if ((EXT_INT43_PEND &(1<<5))>>5)
				{
						printf("key 4 down\n");
						EXT_INT43_PEND |=(1<<5); 
				}
		}

}

void delay()
{
	int i, j;
	for (i=0; i<100; i++)
	{
		for (j=0; j<1000; j++)
		{
			;
		}
	}
}
