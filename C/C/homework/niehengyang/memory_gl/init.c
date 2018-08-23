#include"main.h"



void create_memory(pMem *p,int size)
{
	*p=(pMem)malloc(size);
	if(*p==NULL)
	{
		printf("create error!");
		exit(-1);
	}
	(*p)->next=*p;
	(*p)->prev=*p;
}
//void init_memory(pMem *p,int size)
//{
//	create_memory(*p,size);
//}
