
typedef unsigned long unlong;
void mem_init(unlong* ttb );
void mmap(unlong* ttb, unlong va, unlong pa);
void mmu_enable(void);

int main() 
{
	unlong* va = (void*)0xfff22444;
	unlong* pa = (void*)0x56422444;


	*pa  = 124;
	mmu_init();
	mmu_enable();
	mmap((unlong*)0x70000000, (unlong)va, (unlong)pa);
	printf("%d\n", *va);

	return 0;

}


void mem_init(unlong* ttb )
{
	unlong pa, va;
	for (pa=0x00000000; pa<0x80000000; pa +=0x100000)
	{
		va = pa;
		ttb[va>>20] =(pa&0xfff00000)|2;
	}

}
void mmu_init(void)
{
	unlong* ttb= (void*)0x70000000;
	__asm__ __volatile__(
					
					"mvn r0, #0x0;"
					"mcr p15, 0, r0, c3, c0, 0;"
					"mcr p15, 0, %0, c2, c0, 0;"
					:
					:"r"(ttb)
					:"r0"
					); 
}

void mmu_enable(void)
{
	__asm__ __volatile__(
					"mrc p15, 0, r0, c1, c0, 0;"
					"orr r0, r0, #1;"
					"mcr p15, 0, r0, c1, c0,0;"
					:
					:
					:"r0"
					);
}

void mmap(unlong* ttb, unlong va, unlong pa)
{

	ttb[va>>20] = ttb[pa>>20]=(pa&0xfff0000)|2;
}
