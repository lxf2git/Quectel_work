#include"total.h"
void getmemory(void **p,int size)
{
	*p=malloc(size);
	if(*p==NULL)
	{
		printf("getmemory_error!\n");
		exit(-1);
	}
}
void init_data(pData *p,int size)
{
	getmemory((void **)p,size);
	(*p)->nb=0;
}
