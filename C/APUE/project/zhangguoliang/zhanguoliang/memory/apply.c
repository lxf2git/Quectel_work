#include"main.h"
#include"apply.h"

pMem find_max(pMem pHead,pMem pnew)
{
	pMem ptmp=pHead;
	while(ptmp->next!=pHead)
	{
		if(ptmp->next->mem_size > pnew->mem_size)
		{
			return ptmp;
		}
		ptmp=ptmp->next;
	}
	return ptmp;
}

int insert_back(pMem pbef,pMem pnew)
{
	pbef->next->prev=pnew;
	pnew->prev=pbef;
	pnew->next=pbef->next;
	pbef->next=pnew;
}

void address(pMem pnew,pRec pnum,pRec p,int j)
{
//	printf("add:%p ",pnew);
//	pRec p=NULL;
//	init_rec(&p);
	
	p->pdata[j]=pnew;
//	printf("apply j :%d ",j);
//	printf("pdata[%d]:%p ",j,p->pdata[j]);
	p->next=pnum;
	p->prev=pnum->prev;
	pnum->prev->next=p;
	pnum->prev=p;
	
}
/*
void delete(pMem *pdel)
{
	if(*pdel!=NULL)
	{
		free(*pdel);
		*pdel=NULL;
	}
}
*/
void compare(pMem pHead,pMem pfree,pRec pnum,pRec p,int size,int j)
{
	int max=0,n;
	int i=0;
	if(size>0)
	{
		pMem pnew=pHead->next;
		while(pnew!=pHead)
		{
			if(size==pnew->mem_size)
			{
	//			pMem pnewf=NULL;

	//			pMem pdel=pnew;

	//			init_memory(&pnewf);
	//			pnewf->index=pnew->index;
	//			pnewf->mem_size=size;
	//			printf("pnew:%p ",pnew);
				address(pnew,pnum,p,j);

				pnew->next->prev=pnew->prev;
				pnew->prev->next=pnew->next;
					pnew->next=pnew;
					pnew->prev=pnew;
				pMem pmax= find_max(pfree,pnew);
				insert_back(pmax,pnew);
				
			//	delete(&pdel);
				i=1;
				break;
			}
			else
				pnew=pnew->next;
		}
		pnew=pHead->next;
		while(pnew!=pHead)
		{
			if(max<pnew->mem_size)
			{
				max=pnew->mem_size;
				n=pnew->index;
			}
			pnew=pnew->next;
		}
		if(size<max)
		{
			pnew=pHead->next;
			while(pnew!=pHead)
			{
				if(n==pnew->index&&i!=1)
				{
					pMem pnewf=NULL;
					init_memory(&pnewf);
					pnewf->index=pnew->index;
					pnewf->mem_size=size;
					pMem pmax= find_max(pfree,pnewf);
	//			printf("pnewf:%p ",pnewf);
					address(pnewf,pnum,p,j);
					insert_back(pmax,pnewf);
					pnew->mem_size=pnew->mem_size - size;
					pnew=pnew->next;
					
				}
				else
					pnew=pnew->next;
			}
		}
		if(size>max)
		{
			pnew=pHead->next;
			while(pnew!=pHead)
			{
				if(n==pnew->index)
				{	
					pMem pnew1=pnew;
				//	init_memory(&pnewf);
				//	pnewf->index=pnew->index;
				//	pnewf->mem_size=max;
					address(pnew,pnum,p,j);
					pnew->next->prev=pnew->prev;
					pnew->prev->next=pnew->next;
					pnew->next=pnew;
					pnew->prev=pnew;
					pMem pmax= find_max(pfree,pnew);
					insert_back(pmax,pnew);
					break;
			//		pnew=pnew1->next;
				}
				else
					pnew=pnew->next;
			}
			size=size-max;
			j++;
			compare(pHead,pfree,pnum,p,size,j);
		}
	}
	else
	{
		printf("please input again:\n");
		return ;
	}
}

void apply(pMem pHead,pMem pfree,pRec pnum)
{
	int size=0;
	printf("please input size of memory\n");
	scanf("%d",&size);
	pHead->mem_size=0;
	pMem pnew=pHead->next;
	
	while(pnew!=pHead)
	{
		pHead->mem_size += pnew->mem_size;
		pnew=pnew->next;
	}

	if(size<=pHead->mem_size)
	{
		int j=0;

	pRec p=NULL;
	init_rec(&p);
		compare(pHead,pfree,pnum,p,size,j);
	}
	if(size>pHead->mem_size)
	{
		printf("memory not full\n");
		return ;
	}
}
