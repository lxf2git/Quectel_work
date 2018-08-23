#include"free.h"
#include"insert.h"

int free_mem(pMem phead_app,pMem phead_free,pRec phead_rec)
{
	printf("please input a number\n");
	int n,i;
	scanf("%d",&n);
	pRec p=phead_rec;
	for(i=0;i<n;i++)
	{
		p=p->next;
	}
	if(p->next == p)
	{
		printf("free error\n");
		return FULL;
	}
	if(p->p[0]==NULL)
	{
		printf("free error\n");
		return FULL;
	}
//	printf("%d ",p->p[0]->index);
	for(i=0;i<N;i++)
	{
		if(p->p[i]==NULL)
		{
			break;
		}
		else
		{
			//printf("index:%d memsize:%d",p->p[i]->index,p->p[i]->mem_size);
			delete_free(p->p[i],phead_app);
		}
	}
	free_free(p);
	destory(phead_rec);
	return SUC;
}

pMem find_index(pMem phead,int x)
{
	pMem p=NULL,p1=NULL;
	for(p=phead->next;p!=phead;p=p->next)
	{
		if(p->index==x)
		{
			p1=p;
			break;
		}
	}
	return p1;
}

void delete_free(pMem pdel_free,pMem phead_app)
{
	pdel_free->prev->next=pdel_free->next;
	pdel_free->next->prev=pdel_free->prev;
	pdel_free->prev=pdel_free;
	pdel_free->next=pdel_free;
	pMem ptmp=find_index(phead_app,pdel_free->index);
	if(ptmp==NULL)
	{
		//printf("index:%d memsize:%d",pdel_free->index,pdel_free->mem_size);
		insert_apply(phead_app,pdel_free);
	}
	else
	{
		ptmp->mem_size+=pdel_free->mem_size;
	}
	all_size(phead_app);
}

void i_free(void **p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}

int destory(pRec phead_rec)
{
	pRec p=NULL;
	if(judge(phead_rec)==YES)
	{
		while(phead_rec->next!=phead_rec)
		{
			p=phead_rec->next;
			phead_rec->next=p->next;
			p->next->prev=phead_rec;
			p->prev=p;
			p->next=p;
			i_free((void**)&p);
		}
		return SUC;
	}
	else
	{
		return SUC;
	}
}

int judge(pRec phead_rec)
{
	pRec p=NULL;
	for(p=phead_rec->next;p!=phead_rec;p=p->next)
	{
		if(p->p[0]!=NULL)
		{
			return NO;
		}
	}
	return YES;
}

void free_free(pRec p)
{
	int i;
	for(i=0;i<N;i++)
	{
		p->p[i]==NULL;
	}
}
