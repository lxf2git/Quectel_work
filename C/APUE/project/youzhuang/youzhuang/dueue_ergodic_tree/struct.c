#include"main.h"
void create_memory(void **p,int size)
{
		*p=malloc(size);
		if(NULL==*p)
		{
				printf("create memory error!\n");
				exit(-1);
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
void init_queue(pQueue *queue)
{
		pLink link=NULL;
		init_link_node(&link);
		create_memory((void **)queue,sizeof(sQueue));
		(*queue)->pw=link;
		(*queue)->pr=link;
}
void init_link_node(pLink *link)
{
		create_memory((void **)link,sizeof(sLink));
		(*link)->next=*link;
		(*link)->prev=*link;
		(*link)->tree=NULL;
}
void init_tree_node(pTree *tree)
{
		create_memory((void **)tree,sizeof(sTree));
		(*tree)->pa=NULL;
		(*tree)->lc=NULL;
		(*tree)->rc=NULL;
}
void add_link_node(pLink p,pLink pnew)
{
		pnew->next=p->next;
		p->next->prev=pnew;
		pnew->prev=p;
		p->next=pnew;
}
void del_link_node(pLink phead,pLink pdel)
{
		phead->next=pdel->next;
		pdel->next->prev=phead;
		pdel->next=pdel;
		pdel->prev=pdel;
		free_memory((void **)&pdel);
}
