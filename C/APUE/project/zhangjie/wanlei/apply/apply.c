#include"apply.h"
#include"insert.h"

int apply_mem(pMem phead_app,pMem phead_free,pRec phead_rec)
{
	int size;
	printf("please input a size of apply_memory\n");
	printf("all_size:%d ",phead_app->mem_size);
	scanf("%d",&size);
	if(size>phead_app->mem_size)
	{
		printf("空间不够\n");
		return FULL;
	}
	else
	{
		creat_apply_mem(phead_app,phead_free,phead_rec,size);
		return SUC;
	}
}

int creat_apply_mem(pMem phead_app,pMem phead_free,pRec phead_rec,int size)
{
	pMem max=find_max_app(phead_app);
	pRec new_rec=NULL;
	init_rec(&new_rec,sizeof(sRec));
	creat_memory((void **)&new_rec->p,N*sizeof(pMem));
	pMem pequ=NULL;
	int i=0;
	while(size>0)
	{
		pequ=find_same(phead_app,size);
		if(pequ!=NULL)
		{
			delete_(pequ,phead_free);
			new_rec->p[i]=pequ;
			size=0;
		}
		else if(size<max->mem_size)
		{
			pMem pnew=NULL;
			init_memory(&pnew,sizeof(sMem));
			pnew->mem_size=size;
			pnew->index=max->index;
			max->mem_size-=size;
			insert_free(phead_free,pnew);
			new_rec->p[i]=pnew;
			max=find_max_app(phead_app);
			size=0;
		}
		else
		{
			size=size-max->mem_size;
			delete_(max,phead_free);
			new_rec->p[i]=max;
			max=find_max_app(phead_app);
		}
		i++;
	}
	for(;i<N;i++)
	{
		new_rec->p[i]=NULL;
	}
	insert_rec(phead_rec,new_rec);
	all_size(phead_app);
	return SUC;
}

void delete_(pMem p,pMem phead_free)
{
	p->prev->next=p->next;
	p->next->prev=p->prev;
	p->prev=p;
	p->next=p;
	insert_free(phead_free,p);
}

pMem find_max_app(pMem phead)
{
	pMem p=NULL,p1=phead->next;
	int max=phead->next->mem_size;
	for(p=phead->next;p!=phead;p=p->next)
	{
		if(max<p->mem_size)
		{
			max=p->mem_size;
			p1=p;
		}
	}
	return p1;
}

pMem find_same(pMem phead ,int size)
{
	pMem p=NULL,p1=NULL;
	for(p=phead->next;p!=phead;p=p->next)
	{
		if(size==p->mem_size)
		{
			p1=p;
			break;
		}
	}
	return p1;
}
