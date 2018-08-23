#include"total.h"
void init_chain(pMem *p,int size)
{
	getmemory((void **)p,size);
	(*p)->index=0;
	(*p)->mem_size=0;
	(*p)->prev=(*p);
	(*p)->next=(*p);
}
void getmemory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("getmemory_error!\n");
		exit(-1);
	}
}
void init_chain_rec(pRec *p,int size)
{
	getmemory((void **)p,size);
	(*p)->prev=(*p);
	(*p)->next=(*p);
}
void chain_back(pMem pHead,pMem pnew)
{
	pHead->next->prev=pnew;
	pnew->prev=pHead;
	pnew->next=pHead->next;
	pHead->next=pnew;
}
void output(pMem pHead)
{
	pMem ptmp=pHead->next;
	while(ptmp!=pHead)
	{
		if(ptmp->mem_size!=10)
		printf("Index:%d mem_size:%d\n",ptmp->index,ptmp->mem_size);
		else
		printf("mem_size:%d\n",ptmp->mem_size);
		ptmp=ptmp->next;
	}
	//printf("Index:%d mem_size:%d\n",pHead->index,pHead->mem_size);
}
void output_rec(pRec pHead)
{
	pRec ptmp=pHead->next;
	while(ptmp!=pHead)
	{
		if(ptmp->pdata->mem_size!=10)
		printf("Index:%d mem_size:%d\n",ptmp->pdata->index,ptmp->pdata->mem_size);
		else
		printf("mem_size:%d\n",ptmp->pdata->index);
		ptmp=ptmp->next;
	}
}
void all_mem(pMem *pHead)
{
	pMem ptmp=(*pHead)->next;
	(*pHead)->mem_size=0;
	while(ptmp != (*pHead))
	{
		(*pHead)->mem_size+=ptmp->mem_size;
		ptmp=ptmp->next;
	}
}
void destory(pMem *p)
{
	if((*p)!=NULL)
	{
		(*p)->prev=(*p);
		(*p)->next=(*p);
		free(*p);
		*p=NULL;
	}
}
void destory_rec(pRec *p)
{
	if((*p)!=NULL)
	{
		(*p)->prev=(*p);
		(*p)->next=(*p);
		free(*p);
		*p=NULL;
	}
}
void chain_back_rec(pRec pnew,pRec pHead_rec)
{
	pHead_rec->next->prev=pnew;
	pnew->prev=pHead_rec;
	pnew->next=pHead_rec->next;
	pHead_rec->next=pnew;
}
void change(pMem del,pMem pnew)
{
	del->prev->next=del->next;
	del->next->prev=del->prev;
	chain_back(pnew,del);
}
