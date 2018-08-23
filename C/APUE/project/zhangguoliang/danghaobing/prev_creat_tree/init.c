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

void init_Node(pTree *p)
{
		create_memory(p);
		(*p)->tr_data = '\0';
		(*p)->tr_lc = NULL;
		(*p)->tr_rc = NULL;
}
