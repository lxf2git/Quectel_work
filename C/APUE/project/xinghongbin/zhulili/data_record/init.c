#include"init.h"

void create_memory(pDis *p,int size)
{
	*p = (pDis)malloc(size);
	if(*p == NULL)
	{
		printf("malloc error");
		exit(-1);
	}
}

void init_node(pDis *p,int size)
{
	create_memory(p,size);
	(*p)->next = *p;
}

void create_memory_node(pNode *p,int size)
{
	*p = (pNode)malloc(size);
	if(*p == NULL)
	{
		printf("malloc error");
		exit(-1);
	}
}

void init_node_node(pNode *p,int size)
{
	create_memory_node(p,size);
	(*p)->next = *p;
	(*p)->prev = *p;	
}
