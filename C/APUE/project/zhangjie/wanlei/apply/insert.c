#include"insert.h"
#include"free.h"

void creat_memory(void **p,int size)
{
	*p=malloc(size);
	if(*p==NULL)
	{
		printf("mallco error\n");
		exit(-1);
	}
}

void init_memory(pMem *p,int size)
{
	creat_memory((void **)p,size);
	(*p)->mem_size=0;
	(*p)->prev=*p;
	(*p)->next=*p;
}

void init_rec(pRec *p,int size)
{
	creat_memory((void **)p,size);
	(*p)->prev=*p;
	(*p)->next=*p;
}

void creat_chain(pMem phead,int x)
{
	pMem pnew=NULL;
	int i;
	for(i=0;i<x;i++)
	{
		init_memory(&pnew,sizeof(sMem));
		pnew->index=i+1;
		pnew->mem_size=N;
		insert_(phead,pnew);
	}
	phead->mem_size=all_size(phead);
}

int insert_(pMem p1,pMem p2)
{
	if(p1==NULL||p2==NULL)
	{
		printf("insert error\n");
		return FULL;
	}
	p2->next=p1;
	p2->prev=p1->prev;
	p1->prev->next=p2;
	p1->prev=p2;
	return SUC;
}

int insert_free(pMem phead,pMem pnew)
{
	if(phead==NULL||pnew==NULL)
	{
	//	printf("%p",pnew);
		printf("free insert error\n");
		return FULL;
	}
	pMem ptmp=find_max(phead,pnew);
	insert_cent(ptmp,pnew);
}

int insert_apply(pMem phead,pMem pnew)
{
	if(phead==NULL||pnew==NULL)
	{
		printf("free insert error\n");
		return FULL;
	}
	pMem ptmp=find_index_max(phead,pnew);
	printf("index:%d mem_size%d\n",ptmp->index, ptmp->mem_size);
	insert_cent(ptmp,pnew);
}

pMem find_index_max(pMem phead,pMem pnew)
{
	pMem p=NULL;
	for(p=phead->next;p!=phead;p=p->next)
	{
		if(pnew->index < p->index)
		{
			break;
		}
	}
	return p->prev;
}

int insert_cent(pMem p1,pMem p2)
{
	if(p1==NULL||p2==NULL)
	{
		printf("insert cent error\n");
		return FULL;
	}
	p2->next=p1->next;
	p2->prev=p1;
	p1->next=p2;
	p2->next->prev=p2;
	return SUC;
}

int insert_rec(pRec p1,pRec p2)
{
	if(p1==NULL||p2==NULL)
	{
		printf("insert record error\n");
		return FULL;
	}
	p2->next=p1;
	p2->prev=p1->prev;
	p1->prev->next=p2;
	p1->prev=p2;
	return SUC;
}

pMem find_max(pMem phead,pMem pnew)
{
	pMem p=NULL;
	for(p=phead->next;p!=phead;p=p->next)
	{
		if(pnew->mem_size < p->mem_size)
		{
			break;
		}
	}
	return p->prev;
}

void show(pMem phead)
{
	pMem p=phead->next;
	while(p!=phead)
	{
		printf("index:%d mem_size:%d\n",p->index,p->mem_size);
		p=p->next;
	}
}

int all_size(pMem phead)
{
	pMem p=NULL;
	phead->mem_size=0;
	for(p=phead->next;p!=phead;p=p->next)
	{
		phead->mem_size+=p->mem_size;
	}
	return phead->mem_size;
}
