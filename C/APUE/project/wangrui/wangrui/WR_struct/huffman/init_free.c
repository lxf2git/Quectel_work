#include"huffman.h"

void init_node(pNode *pnode)
{
	creat_memory((void **)pnode,sizeof(sNode));
	(*pnode)->weight = 0;
	(*pnode)->data = 0;
	(*pnode)->lc = NULL;
	(*pnode)->rc = NULL;
	(*pnode)->parent = NULL;
	(*pnode)->next = NULL;
}
void creat_memory(void **p,int size)
{
	*p = malloc(size);
	if(*p == NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
	bzero(*p,size);
}
void free_node(pNode *pnode)
{
	(*pnode)->lc = NULL;
	(*pnode)->rc = NULL;
	(*pnode)->parent = NULL;
	(*pnode)->next = NULL;
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
void insert_back_chain(pNode pHead,pNode pnew)
{
		pnew->parent = pHead->parent;
		pHead->parent->next = pnew;
		pHead->parent = pnew;
		pnew->next = pHead;
}
void head_del(pNode pHead,pNode ptmp)
{
	pHead->next = ptmp->next;
	pHead->next->parent = pHead;		
	ptmp->next = NULL;
	ptmp->parent = NULL;
}
