#include"init.h"

void create_memory(pTree *p)
{
		*p = (pTree)malloc(sizeof(sTree));
		if(*p==NULL)
		{
				printf("malloc error!\n");
				exit(-1);
		}
}

void init_node(pTree *p)
{
	create_memory(p);
	(*p)->lc = NULL;
	(*p)->rc = NULL;
}
