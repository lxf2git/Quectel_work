#include"main.h"


void cut_free(pMem p5,pRec p4)
{
	p5->next->prev=p5->prev;
	p5->prev->next=p5->next;
	p5->next=p5;
	p5->prev=p5;
}

void link_free(pMem p5,pMem ptmp)
{
	ptmp->prev->next=p5;
	p5->prev=ptmp->prev;
	p5->next=ptmp;
	ptmp->prev=p5;
}

void find_free(pMem pHead,pRec p4)
{
	pMem p5=(p4->pdata)->next;
	pMem ptmp=pHead->next;
	while(p5!=p4->pdata)
	{
		ptmp=pHead->next;
		while(ptmp!=pHead)
		{
			if(ptmp->index==p5->index)
			{
				cut_free(p5,p4);
				(ptmp->mem_size)+=p5->mem_size;
				ptmp=pHead->prev;
			}
			else
			{
				if(ptmp->index>p5->index)
				{
					cut_free(p5,p4);
					link_free(p5,ptmp);
					ptmp=pHead->prev;
				}
			}
			ptmp=ptmp->next;
		}
	p5=p4->pdata->next;
	}
}

void free_memory(pMem pHead,pRec phead)
{
	int count,i;
	pRec p4=phead->next;
	printf("please input the count you want to free:\n");
	scanf("%d",&count);
	for(i=1;i<count;i++)
	{
		p4=p4->next;
	}
		find_free(pHead,p4);
}
