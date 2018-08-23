#include"main.h"

void init_node(pFile *p)
{
		create_memory(p,sizeof(sFile));
		(*p)->prev=*p;
		(*p)->next=*p;
}

void add_node(pFile phead,pFile pnew)
{
		pnew->next=phead;
		pnew->prev=phead->prev;
		phead->prev->next=pnew;
		phead->prev=pnew;
}

void create_memory(pFile *p,int size)
{
		*p=malloc(size);
		if(NULL==*p)
		{
				printf("create memory error\n");
				exit(-1);
		}
}

void unload_link(pFile *phead)
{
		while((*phead)->next!=(*phead))
		{
				del_node((*phead),(*phead)->next);
		}
		free_memory(phead);
}

void del_node(pFile phead,pFile p)
{
		phead->next=p->next;
		p->next->prev=phead;
		p->prev=NULL;
		p->next=NULL;
		free_memory(&p);
}

void free_memory(pFile *p)
{
		if(*p!=NULL)
		{
				free(*p);
				*p=NULL;
		}
}
