#include"apply.h"
void memory_chain(pMem pHead)
{
	int i;
	pMem pnew;
	for(i=0;i<N;i++)
	{
		init_chain(&pnew,sizeof(sMem));
		pnew->index=i+1;
		pnew->mem_size=10;
		chain_back(pHead,pnew);	
	}
}
void apply_chain(pMem pHead_app,pMem pHead,pRec pHead_rec)
{
	static int i=0;
	pMem pnew;
	int size;
	init_chain(&pnew,sizeof(sMem));
	pnew->index=i+1;
	printf("输入要开空间大小：\n");
	scanf("%d",&size);
	pnew->mem_size=(size%10);
	find_mem(pHead,pHead_app,pHead_rec,size,pnew);
	chain_back(pHead_app,pnew);
	i++;	
}
void rec_chain(pRec pHead_rec,pMem ptmp)
{
	pRec pnew;
	init_chain_rec(&pnew,sizeof(sRec));
	pnew->pdata=ptmp;
	chain_back_rec(pnew,pHead_rec);
}	
void find_mem(pMem pHead,pMem pHead_app,pRec pHead_rec,int size,pMem pnew)
{
	pRec pnew_1;
	pMem ptmp=pHead->next;
	pMem ptmp_1;
	pMem del;	
	int i=0,s=size;
	if(s>10)
	{
		i=s/10;		
		for(;i>0&&ptmp!=pHead;i--)
		{
			
			if(ptmp->mem_size==10)
			{				
				del=ptmp;
				rec_chain(pHead_rec,del);
				ptmp=ptmp->next;
				change(del,pHead_app);	
			}
			
			else 
			{ ptmp=ptmp->next; i++;
			}
			
		}	
	}
	s=size%10;
	if(s<10)
	{	ptmp_1=pHead->next;
		while(ptmp_1!=pHead)
		{
			if(ptmp_1->mem_size==s)
			{
				(ptmp_1->mem_size)-=s;
				rec_chain(pHead_rec,ptmp_1);
				break;
			}
			else if(ptmp_1->mem_size==10)
			{
				(ptmp_1->mem_size)-=s;
				rec_chain(pHead_rec,ptmp_1);
				break;
			}
			ptmp_1=ptmp_1->next;
		}
	}
}
