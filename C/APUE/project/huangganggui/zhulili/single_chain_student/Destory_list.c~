#include"Destory_list.h"

void Destory_Node(pNode *p)
{
	if(*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}

void Destory_list(pNode *pHead)
{
	pNode pdel = NULL;
	while((*pHead)->next != NULL)
	{
		pdel = (*pHead)->next;
		(*pHead)->next = pdel->next;
		pdel->next = NULL;
		Destory_Node(&pdel);
	}
	Destory_Node(pHead);
}

