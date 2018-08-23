#include"show.h"
void show_chain(pMem pHead)
{
		pMem ptmp;
		ptmp = pHead->next;
		printf("sum:%d\n",pHead->mem_size);
		while(ptmp!=pHead)
		{
				printf("index:%d size:%d\n",ptmp->index,ptmp->mem_size);
				ptmp=ptmp->next;
		}
}
