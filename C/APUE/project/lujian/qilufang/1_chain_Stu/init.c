#include"init.h"

void getmemory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("getmemory_error!\n");
		exit(-1);
	}
}
void init_Stu(pStu *p,int size)
{
	getmemory((void **)p,size);
	(*p)->next=NULL;
}
void init_Node(pList p,int size)
{
	getmemory((void **)p,size);
}
void destory(pStu del)
{
	if(del!=NULL)
	{
		del->next=NULL;
		free(del);
	}
}
void chain_del(pStu *pHead)
{
	pStu ptmp=(*pHead)->next;
	pStu del=NULL;
	while(ptmp!=NULL)
	{
		del=ptmp;
		(*pHead)->next=ptmp->next;
		ptmp=ptmp->next;
		destory(del);
	}	
}
