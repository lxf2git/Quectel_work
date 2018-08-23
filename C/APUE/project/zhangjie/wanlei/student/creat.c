#include"creat.h"

void creat_memory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void i_free(void **p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}

void destory(pStu *p)
{
	pStu pdel=(*p);
	while((*p)->next!=NULL)
	{
		pdel=(*p)->next;
		(*p)->next=pdel->next;
		pdel->next=NULL;
		i_free((void **)&pdel);
	}
	i_free((void **)p);
}
