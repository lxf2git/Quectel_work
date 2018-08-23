#include"main.h"


void cut_memory(pMem ptmp,pMem pHead)
{
	ptmp->next->prev=ptmp->prev;
	ptmp->prev->next=ptmp->next;
	ptmp->next=ptmp;
	ptmp->prev=ptmp;
}

void link_memory(pMem ptmp,pMem pHost)
{
	pHost->prev->next=ptmp;
	ptmp->prev=pHost->prev;
	ptmp->next=pHost;
	pHost->prev=ptmp;
	
	/*ptmp->next=pHost->next;
	pHost->next->prev=ptmp;
	ptmp->prev=pHost;
	pHost->next=ptmp;
	*/
}

void Link_Memory(pRec phead,pRec ptm,pRec pNew_memory)
{
	pNew_memory->next=phead;
	phead->prev=pNew_memory;
	pNew_memory->prev=ptm;
	ptm->next=pNew_memory;
}
void apply_memory(pMem pHead,pRec ptm,pRec phead)
{
	int mem_need;
	int max=0;
	pMem pnew_add;
	pRec pNew_memory;
	pMem ptmp_next;
	pMem ptmp=pHead->next;
	printf("please input how lenth memory you need\n");
	scanf("%d",&mem_need);
	//cut_memory(pHead,phead,mem_need);
	create_memory(&pNew_memory,sizeof(sRec));
	create_memory(&pNew_memory->pdata,sizeof(sMem));
	while(ptmp!=NULL)
	{
		if(mem_need>(pHead->mem_size))
		{
			ptmp_next=ptmp->next;
			if(ptmp->mem_size==pHead->mem_size)
			{
			cut_memory(ptmp,pHead);
			link_memory(ptmp,pNew_memory->pdata);
			mem_need=mem_need-(pHead->mem_size);
			//ptmp=pHead->next;
			}
			ptmp=ptmp_next;
			/*if(ptmp->mem_size==pHead->mem_size)
			{
			mem_need=mem_need-(ptmp->mem_size);
			cut_memory(ptmp,pHead);
			link_memory(ptmp,pNew_memory->pdata);
			}*/
		}
		else 
		{
			if(mem_need==ptmp->mem_size&&mem_need!=0)
			{
				cut_memory(ptmp,pHead);
				//create_memory(&pNew_memory,sizeof(sRec));
                       		//create_memory(&pNew_memory->pdata,sizeof(sMem));
                        	link_memory(ptmp,pNew_memory->pdata);
                        	mem_need=mem_need-(ptmp->mem_size);
				ptmp=ptmp->next;
			}
			else
			{
				if(ptmp->mem_size==pHead->mem_size&&mem_need!=0)
				{
					ptmp->mem_size=(ptmp->mem_size)-mem_need;
					create_memory(&pnew_add,sizeof(sMem));
					pnew_add->index=ptmp->index;
					pnew_add->mem_size=mem_need;
					link_memory(pnew_add,pNew_memory->pdata);
					mem_need=0;
				}	
				
				ptmp=ptmp->next;
			}
			
		}
		printf("==%d\n",mem_need);
		if(max<ptmp->mem_size&&ptmp!=pHead)
		{
		max=ptmp->mem_size;
		}
		//ptmp=ptmp->next;
		if(ptmp==pHead)
		{
			ptmp=pHead->next;
			pHead->mem_size=max;
			max=0;	
		}
		if(mem_need==0)
		{
		Link_Memory(phead,ptm,pNew_memory);
			break;
		}
	}
}
