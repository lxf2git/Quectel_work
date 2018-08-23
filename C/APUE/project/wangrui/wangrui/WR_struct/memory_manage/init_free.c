#include"memory.h"
extern sRec *pHrec[N];
extern int rec;
void creat_memory(void **p,int size)
{
	*p = malloc(size);
	if(*p == NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}
void insert_mem_back(pMem pHead,pMem pnew)
{
	pHead->prev->next = pnew;
	pnew->prev = pHead->prev;
	pnew->next = pHead;
	pHead->prev = pnew;
}
void insert_rec_back(pRec pHead,pRec pnew)
{
	pHead->prev->next = pnew;
	pnew->prev = pHead->prev;
	pnew->next = pHead;
	pHead->prev = pnew;
}
void init_mem_node(pMem *pnode)
{
	creat_memory((void **)pnode,sizeof(sMem));
	(*pnode)->prev = *pnode;
	(*pnode)->next = *pnode;
}

void init_rec_node(pRec *pnode)
{
	creat_memory((void **)pnode,sizeof(sRec));
//	init_mem_node(&(*pnode)->pdata);
	(*pnode)->prev = *pnode;
	(*pnode)->next = *pnode;
}

void creat_mem_chain(pMem pHapp)
{
	pMem pmem_new = NULL;
	int i;
	pHapp->size = 0;
	for(i=0;i<N;i++)
	{
		init_mem_node(&pmem_new);
		pmem_new->index = i+1;
		pmem_new->size = N;
		insert_mem_back(pHapp,pmem_new);
		pHapp->size=pHapp->size+pmem_new->size;
	}
}
void delete_mem_node(pMem *pnode)
{
	(*pnode)->prev->next = (*pnode)->next;
	(*pnode)->next->prev = (*pnode)->prev;
	(*pnode)->next = NULL;
	(*pnode)->prev = NULL;
	free_memory((void **)pnode);
}
void delete_rec_node(pRec *pnode)
{
	(*pnode)->prev->next = (*pnode)->next;
	(*pnode)->next->prev = (*pnode)->prev;
	(*pnode)->next = NULL;
	(*pnode)->prev = NULL;
	free_memory((void **)pnode);
}
void free_memory(void **p)
{
	if(*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}
int exit_free(pMem pHapp,pMem pHfre)
{
	return SUC;	
}
