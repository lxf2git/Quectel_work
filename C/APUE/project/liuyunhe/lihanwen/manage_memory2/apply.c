#include"apply.h"

int find_max(pMem pHead)
{
	int max=0;
	pMem ptmp;
	for(ptmp=pHead->next;ptmp!=pHead;ptmp=ptmp->next)
	{
		if(max <= ptmp->mem_size)
		{
			max=ptmp->mem_size;
		}
	}
	return max;
}


int same(int size,pMem pHead)
{
	int r=0;
	pMem ptmp;
	for(ptmp=pHead->next;ptmp!=pHead;ptmp=ptmp->next)
	{
		if(size==ptmp->mem_size)
		{
			r=1;
		}
	}
	return r;
}

int same_index(pMem ptmp,pMem pFree)
{
	int r=0;
	pMem ptmpf;
	for(ptmpf=pFree->next;ptmpf!=pFree;ptmpf=ptmpf->next)
	{
		if(ptmp->index==ptmpf->index)
		{
			r=1;
		}
	}
	return r;
}

void insert(pMem ptmp,pMem pFree)
{
	ptmp->next->prev=ptmp->prev;
	ptmp->prev->next=ptmp->next;
	ptmp->prev=ptmp;
	ptmp->next=ptmp;
	
	pMem ptmpf=pFree->next;
	if(ptmpf==pFree)
	{
		ptmpf->next=ptmp;
		ptmpf->prev=ptmp;
		ptmp->next=ptmpf;
		ptmp->prev=ptmpf;
	}else 
	{
		int r;
		r=same_index(ptmp,pFree);
		if(r==0)
		{
			for(ptmpf=pFree->next;ptmpf!=pFree;ptmpf=ptmpf->next)
			{
				if(ptmpf->next->index > ptmp->index)
				{
					ptmpf->next->prev=ptmp;
					ptmp->next=ptmpf->next;
					ptmp->prev=ptmpf;
					ptmpf->next=ptmp;
				}
			}
		}
		else if(r==1)
		{
			for(ptmpf=pFree->next;ptmpf!=pFree;ptmpf=ptmpf->next)
			{
				if(ptmpf->index == ptmp->index)
				{
					ptmpf->mem_size=ptmpf->mem_size+ptmp->mem_size;

					ptmp->next->prev=ptmp->prev;
					ptmp->prev->next=ptmp->next;
					ptmp->next=ptmp;
					ptmp->prev=ptmp;

					//myfree(ptmp);
				}
			}		
		}
	}
//	m_printf(pFree);
}

void insertc(pMem ptmp,pMem pFree)
{
	pMem ptmpf;
	for(ptmpf=pFree->next;ptmpf!=pFree;ptmpf=ptmpf->next)
	{
			printf("1************\n");
		if(ptmpf->next->index > ptmp->index)
		{
			ptmpf->next->prev=ptmp;
			ptmp->next=ptmpf->next;
			ptmpf->next=ptmp;
			ptmp->prev=ptmpf;

			printf("************\n");
		}
	}
//	m_print(pFree);
}

void m_apply(pMem pApply,pMem pFree)
{
	printf("Apply before\n");
	//m_print(pApply);
	
	printf("please input size to apply\n");
	int size,max,r;
	scanf("%d",&size);

	max=find_max(pApply);
	printf("max-af:%d\n",max);

	r=same(size,pApply);

	if(size>pApply->mem_size)
	{
		printf("size shrot!\n");
		exit(-1);
	}else
	{
		pMem ptmp;
		while(size>0)
		{
			max=find_max(pApply);
			if(size>=max)
			{
				for(ptmp=pApply->next;ptmp!=pApply;ptmp=ptmp->next)
				{
					if(ptmp->mem_size==max)
					{
						insert(ptmp,pFree);

						printf("max:%d\n",max);
						printf("size-bf:%d\n",size);
						size=size-max;
						printf("size-af:%d\n",size);
						ptmp=pApply->prev;

					}
				}
			}//size>=max
			if(size<max)
			{
				max=find_max(pApply);
				for(ptmp=pApply->next;ptmp!=pApply;ptmp=ptmp->next)
				{
					if(size==ptmp->mem_size)
					{
						printf("===\n");
						ptmp->next->prev=ptmp->prev;
						ptmp->prev->next=ptmp->next;
						ptmp->next=ptmp;
						ptmp->prev=ptmp;
						
						insert(ptmp,pFree);
						size=0;
						ptmp=pApply->prev;
						
						//return ;
					}
					else if(ptmp->mem_size==max)
					{
						ptmp->mem_size=ptmp->mem_size-size;
						pMem pNew;
						init_memory(&pNew);

						pNew->mem_size=size;
						pNew->index=ptmp->index;

						insertc(pNew,pFree);
						size=0;
					}
				}

			}//size==max


		}//size=0
	}

}
