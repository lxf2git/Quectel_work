#include"base_sort.h"

void create_memory(void **p,int size)
{
	*p = malloc(size);
	if(NULL == *p)
	{
		printf("malloc error!\n");
		exit(-1);
	}
	bzero(*p,size);
}

void create_chain(pSt phead)
{
	int i;
	pSt pnew = NULL;
	for(i=0;i<N;i++)
	{
		init_node(&pnew,sizeof(sSt));
		printf("please input data:");
		scanf("%d",&pnew->data);
		insert_back_head(phead,pnew);
	}
}

void create_chain_chain(pChain pFh)
{
	int i;
	pChain pcn;
	for(i=0;i<10;i++)
	{
		init_chain(&pcn, sizeof(sChain));
		init_node(&pcn->record,sizeof(sSt));
		pcn->prev = pFh->prev;
		pFh->prev->next = pcn;
		pFh->prev = pcn;
		pcn->next = pFh;
	}
}

void free_memory(void **p)
{
	free(*p);
	if(NULL != *p)
	{
		*p=NULL;
	}
}

void init_node(pSt *pnode,int size)
{
	create_memory((void **)pnode,size);
	(*pnode)->next = *pnode;
	(*pnode)->prev = *pnode;
}
void init_chain(pChain *pnode,int size)
{
	create_memory((void **)pnode,size);
	(*pnode)->next = *pnode;
	(*pnode)->prev = *pnode;
}

#if 1
void insert_back_head(pSt phead, pSt pnew)
{
	pnew->prev = phead->prev;
	phead->prev->next = pnew;
	phead->prev = pnew;
	pnew->next = phead;
}
#endif

void show_chain(pSt phead)
{
	pSt pnew=phead;
	for(pnew=phead->next;pnew != phead;pnew=pnew->next)
	{
		printf("%d  ",pnew->data);
	}
	printf("\n");
}
