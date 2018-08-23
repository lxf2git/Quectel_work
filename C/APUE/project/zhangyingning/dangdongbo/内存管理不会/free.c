#include"free.h"
void fre(pMem pHead,pMem pHead1,pr pHead2,int a)
{
		pr ptmp=NULL;
				ptmp=pHead2;
		pMem pt;
		pMem pl;
		int i,m=0;
		for(i=0;i<a;i++)
		{
				ptmp=ptmp->next;
		}
		for(i=0;ptmp->pdata[i]!=NULL;i++)
		{
				pt=ptmp->pdata[i];
				pt->prev->next=pt->next;
				pt->next->prev=pt->prev;
		        pt->prev=pt;
		        pt->next=pt;
				for(pl=pHead->next;pl!=pHead;pl=pl->next)
				{
				if(pt->index==pl->index)
				{
						pl->mem_size=pt->mem_size+pl->mem_size;
						m=-1;
				}
				}
				if(m==0)
				{
				for(pl=pHead->next;pl!=pHead;pl=pl->next)
				{
					if(pt->index<pl->index)
					{
					pt->prev=pl->prev;
					pl->prev->next=pt;
					pl->prev=pt;
					pt->next=pl;
					break;
					}
				}
						
				}

		}
}
