#include"student.h"


void Init_Stu(pStu *p)
{
	creat_memory(p,sizeof(sStu));
	(*p)->next = NULL;
}

void creat_memory(pStu *p,int size) 
{
	*p=(pStu)malloc(size);
	if(NULL == *p)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void Exit(pStu *pHead)
{
	pStu pdel = NULL;
	while((*pHead)->next != NULL)
	{
		pdel = (*pHead)->next;
		(*pHead)->next = pdel->next;
		pdel->next = NULL;
		Destory_Stu(&pdel);
	}
	Destory_Stu(pHead);
	printf("eixt\n");
}

void Destory_Stu(pStu *p)
{
	if(*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}	
