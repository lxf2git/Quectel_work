#include"hash.h"
void create_node(pData *p)
{
		create_memory((void **)p,sizeof(sData));
		(*p)->next=*p;
		(*p)->prev=*p;
}

void create_memory(void **p,int size)
{
		*p=malloc(size);
		if(NULL==*p)
		{
				printf("create memory error!\n");
				exit(-1);
		}
}

void insert_node(pData phead,pData pnew)
{
		pnew->prev=phead->prev;
		pnew->next=phead;
		phead->prev->next=pnew;
		phead->prev=pnew;
}

void output(pData phead)
{
		pData p=phead->next;
		printf("%d ", phead->data);
		while(p!=phead)
		{
				printf("%d ", p->data);
				p=p->next;
		}
}
