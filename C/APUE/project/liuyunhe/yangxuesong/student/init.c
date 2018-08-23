#include"init.h"
void init_node(pStu *p,int size)
{
	*p = malloc(size);
	if(*p==NULL)
	{
		printf("malloc error");
		exit(-1);
	}
	(*p)->next = NULL; 
}

void Free(pStu pHead)
{
	pStu ptv =pHead;
	pStu pdel;
	while(ptv->next!=NULL)
	{
		pdel = ptv->next;
		ptv->next = ptv->next->next;
		free(pdel);
		pdel = NULL;
	}
	free(ptv);
	ptv=NULL;
}
