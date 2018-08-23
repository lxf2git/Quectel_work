#include"search.h"

int num(pStu pHead,int num)
{
	int i=0;
	pStu pfind=pHead->next;
	while(pfind!=NULL)
	{
		if(pfind->num==num)
		{
			printf("num:%dage:%d\n",pfind->num,pfind->age);
			i=1;
		}
		pfind = pfind->next;
	}
	if(i==0)
	{
		printf("无此id\n");
	}
}

int age(pStu pHead,int num)
{
	int i=0;
	pStu pfind=pHead->next;
	while(pfind!=NULL)
	{
		if(pfind->age==num)
		{
			printf("num:%dage:%d\n",pfind->num,pfind->age);
			i=1;
		}
		pfind = pfind->next;
	}
	if(i==0)
	{
		printf("无此年龄\n");
	}
}

int psearch(pStu pHead,int(*pFun_Search[2])(pStu pHead,int num))
{
	int i,j;
	printf("1.num\n");
	printf("2.age\n");
	scanf("%d",&i);
	printf("输入数据\n");
	scanf("%d",&j);
	pFun_Search[i-1](pHead,j);
}

void Search(sList slist,pStu pHead)
{
	printf("*\n");
	int (*pf[2])(pStu,int)={num,age};
	slist.pSearch = psearch;
	slist.pSearch(pHead,pf);
}
