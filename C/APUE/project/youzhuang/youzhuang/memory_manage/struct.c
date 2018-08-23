#include"main.h"
void create_memory(void **p,int size)
{
		*p=malloc(size);
		if(NULL==*p)
		{
				printf("create memory error!\n");
		}
}

void free_memory(void **p)
{
		if(*p!=NULL)
		{
				free(*p);
				*p=NULL;
		}
}

void create_mem_node(pMem *p)
{
		create_memory((void **)p,sizeof(sMem));
		(*p)->prev=*p;
		(*p)->next=*p;
}

void create_rec_node(pRec *p)
{
		create_memory((void **)p,sizeof(sRec));
		(*p)->prev=*p;
		(*p)->next=*p;
}

void unload_rec_chain(pRec *phead)
{
		pRec p=(*phead);
		while(p->next!=*phead)
		{
				delete_rec_node(p->next);
		}
		free_memory((void **)phead);
}

void unload_mem_chain(pMem *phead)
{
		pMem p=(*phead);
		while(p->next!=*phead)
		{
				delete_mem_node(p->next);
		}
		free_memory((void **)phead);
}

void delete_mem_node(pMem p)
{
		p->prev->next=p->next;
		p->next->prev=p->prev;
		p->prev=p;
		p->next=p;
		free_memory((void **)&p);
}

void delete_rec_node(pRec p)
{
		p->prev->next=p->next;
		p->next->prev=p->prev;
		p->prev=p;
		p->next=p;
		free_memory((void **)&p);
}

pMem find_index_insert(pMem phead,pMem pnew)
{
		pMem p=phead->next;
		while(p!=phead)
		{
				if(p->index>pnew->index)
				{
						return p;
				}
				p=p->next;
		}
		return p;
}

pMem find_size_insert(pMem phead,pMem pnew)
{
		pMem p=phead->next;
		while(p!=phead)
		{
				if(p->mem_size>pnew->mem_size)
				{
						return p;
				}
				p=p->next;
		}
		return p;
}

void insert_mem_chain(pMem phead,pMem (*pfun) (pMem phead,pMem pnew),pMem pnew)
{
		pMem p=pfun(phead,pnew);
		p->prev->next=pnew;
		pnew->prev=p->prev;
		p->prev=pnew;
		pnew->next=p;
}

void insert_rec_chain(pRec phead,pRec pnew)
{
		pnew->prev=phead->prev;
		phead->prev->next=pnew;
		pnew->next=phead;
		phead->prev=pnew;
}

void create_mem_chain(pMem phead)
{
		int i;
		pMem pnew=NULL;
		for(i=0;i<10;i++)
		{
				create_mem_node(&pnew);
				pnew->index=i+1;
				pnew->mem_size=10;
				phead->mem_size+=pnew->mem_size;
				insert_mem_chain(phead,find_index_insert,pnew);
		}
}

void output_mem_chain(pMem phead)
{
		pMem p=phead->next;
		while(p!=phead)
		{
				printf("index:%d  size:%d    ",p->index,p->mem_size);
				p=p->next;
		}
		printf("\n");
}
