#include "main.h"
#include "init.h"
#include "insert.h"


int searage(pStu p,int n)
{
	pStu ptemp=NULL;
	p->stu_print=stu_pri;
	for(ptemp=p->next;ptemp!=NULL;ptemp=ptemp->next)
	{
		if(ptemp->age==n)
		{
			//printf("%d %d\n",ptemp->num,ptemp->age);
			p->stu_print(ptemp);
		}
	}
	return 0;	
}

int searid(pStu p,int n)
{
	pStu ptemp=NULL;
	p->stu_print=stu_pri;
	for(ptemp=p->next;ptemp!=NULL;ptemp=ptemp->next)
	{
		if(ptemp->num==n)
		{
			//printf("%d %d\n",ptemp->num,ptemp->age);
			p->stu_print(ptemp);
			return 0;
		}
	}
	printf("::::::have nonu this id!::::::\n");
	printf("\n");
	return -1;
}

int search1(pStu p,int (*pFun_Search[2])(pStu pHead,int num))
{
	pFun_Search[0]=searage;
	pFun_Search[1]=searid;
	int i,s;
	printf("=================\n");
	printf("1:search with age\n");
	printf("2:search with id \n");
	printf("=================\n");
	scanf("%d",&i);
	if(i!=1&&i!=2)
	{
		printf("::::::::input error::::::\n");
		return -1;
	}
	printf("input the inter\n");
	scanf("%d",&s);
	switch(i)
	{
		case 1:
			pFun_Search[0](p,s);
			break;
		case 2:
			pFun_Search[1](p,s);
			break;
	}
	return 0;
}


void search(pStu p)
{
	int (*pFun_Search[2])(pStu pHead,int num);
	int (*pSearch)(pStu pHead,int (*pFun_Search[2])(pStu pHead, int num));
	pSearch=search1;
	pSearch(p,pFun_Search);
}
