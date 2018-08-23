#include"main.h"


void create_memory(pStu *p)
{
	*p=(pStu)malloc(sizeof(sStu));
}





void init_memory(pStu *p)
{
	create_memory(p);
	if((*p)->next!=NULL)
	{
		(*p)->next=NULL;
	}
}
