#include"print.h"

void m_print(pMem pHead)
{
	pMem ptmp;
	for(ptmp=pHead->next;ptmp!=pHead;ptmp=ptmp->next)
	{
		printf("==index:%d  mem-size:%d==\n",ptmp->index,ptmp->mem_size);
	}
}
