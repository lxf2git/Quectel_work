#include"init.h"

void creat_memory(pMem *p)
{
	*p = malloc(sizeof(sMem));
}

void init_memory(pMem *p)
{
	creat_memory(p);
	(*p)->next=(*p);
	(*p)->prev=(*p);
}


