#include"init.h"

void creat_memory(pStu *p)
{
	*p = (pStu)malloc(sizeof(sStu));
}

void init_memory(pStu *p)
{
	creat_memory(p);
	(*p)->next = NULL;
}

void init_memory_list(pList *p)
{
	*p = malloc(sizeof(sList)); 
}
