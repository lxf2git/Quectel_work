#include"init.h"

void create_memory(pNode *p,int size)
{
	*p = (pNode)malloc(size);
	if(*p == NULL)
	{
		printf("malloc error");
		exit(-1);
	}
}

void init_node(pNode *p,int size)
{
	create_memory(p,size);
	(*p)->next = *p;
	(*p)->prev = *p;
}


