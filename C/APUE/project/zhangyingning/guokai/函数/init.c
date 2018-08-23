#include"init.h"

void creat_memory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==(*p))
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void init_node(pStu *p,int size)		
{
	creat_memory((void**)p,size);
	(*p)->next = NULL;
}

