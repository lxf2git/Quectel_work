#include <common.h>
void mem_init(unsigned long* ttb);
void mmu_init(void);
void mmu_enable(void);
void mmap(unsigned long* ttb, unsigned long va,unsigned long pa);
int main()
{
	   unsigned long *va=(void*)0xfff22444;
	   unsigned long *pa=(void*)0x56522444;

           *pa=1234; 
		   mmu_init();
		   mmu_enable();
		   mmap((void*)0x70000000,(unsigned long)va,(unsigned long)pa);
		   printf("%d\n",*pa);  //123 
		   printf("%d\n",*va);  //123

 }
void mmu_enable(void)
{
	    __asm__ __volatile__(
				
					   "mrc p15,0,r0,c1,c0,0\n\t"
					   "orr r0,r0,#1\n\t"
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
