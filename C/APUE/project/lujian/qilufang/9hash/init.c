#include"main.h"
void getmemory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("getmemory_error!\n_");
		exit(-1);
	}
}
void init_data(pData *p,int size)
{
	getmemory((void **)p,size);
	(*p)->prev=(*p);
	(*p)->next=(*p);
}
