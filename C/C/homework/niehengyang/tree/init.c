#include"main.h"


void create_memory(pTr *p,int size)
{
	*p=(pTr)malloc(sizeof(size));
	if(*p==NULL)
	{
		printf("create error!");
		exit(-1);
	}
	(*p)->parent=NULL;
	(*p)->lc=NULL;
	(*p)->rc=NULL;
}
