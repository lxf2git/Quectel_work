#include"builtmemory.h"

void builtmemory(pMem pApply)
{
	pMem pNew;
  pMem ptmp=pApply;
	int i;
	for(i=0;i<N;i++)
	{
		init_memory(&pNew);
		pNew->index=i+1;
		pNew->mem_size=10;

		ptmp->next->prev=pNew;
		pNew->next=ptmp->next;
		ptmp->next=pNew;
		pNew->prev=ptmp;

		ptmp=pNew;
		printf("ptmp:%d ptmp-size:%d\n",ptmp->index,ptmp->mem_size);
	}
	pApply->mem_size=10*N;
}
