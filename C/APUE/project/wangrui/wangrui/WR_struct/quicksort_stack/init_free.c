#include"main.h"

void init_node(pNode *pnode)
{
	creat_memory((void**)pnode,sizeof(sNode));
	(*pnode)->prev = *pnode;
	(*pnode)->next = *pnode;
}
void creat_memory(void **p,int size);
{
	*p = malloc(size);
	if(NULL == *p)
	{
		printf("malloc error\n");
		exit(-1);
	}
}
void free_memory(void **p)
{
	if(*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}
