#include"search.h"
#include"print.h"

int pSearch(pStu pHead,int (*pFun[2])(pStu ,int))
{
	printf("请选择查找的方式：\n");
	printf("*****1:id********\n");
	printf("*****2:age*******\n");
	int n,id,age;
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			printf("请输入查找的id号\n");
			scanf("%d",&id);
			pFun[0](pHead,id);
			break;
		case 2:
			printf("请输入查找的age\n");
			scanf("%d",&age);
			pFun[1](pHead,age);
			break;
		default:
			break;
	}
}

int find_id(pStu pHead,int id)
{
	pStu p=pHead;
	while(p->next!=NULL)
	{
		if(p->next->num==id)
		{
			p->next->stu_print=print_;
			print_(p->next);
		}
		p=p->next;
	}
	return 0;
}

int find_age(pStu pHead,int age)
{
	pStu p=pHead;
	while(p->next!=NULL)
	{
		if(p->next->age==age)
		{
			p->next->stu_print=print_;
			print_(p->next);
		}
		p=p->next;
	}
	return 0;
}
