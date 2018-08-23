#include"main.h"

void init_node(pNode *pnode)
{
	creat_memory(pnode);
	(*pnode)->next = *pnode;
	(*pnode)->prev = *pnode;
}
void creat_memory(pNode *p)
{
	*p = (pNode)malloc(sizeof(sNode));
	if(*p == NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void creat_chain(pNode pHead)
{
	int i;
	printf("data\n");
	pNode pnew = NULL;
	for(i=0;i<N;i++)
	{
		init_node(&pnew);
		scanf("%d",&pnew->data);
		pnew->prev = pHead->prev;
		pHead->prev->next = pnew;
		pHead->prev = pnew;
		pnew->next = pHead;		
	}
}

void free_node(pNode *p)
{
	if(*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}
