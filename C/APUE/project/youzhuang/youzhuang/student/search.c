#include"search.h"
void search(pStu pHead)
{
		int (*pfun[2])(pStu pHead,int num);
		pfun[0]=find_num;
		pfun[1]=find_age;
		if(fun.pSearch(pHead,pfun))
		{
				printf("没有符合条件的学生!\n");
		}
}

int find(pStu pHead,int (*pFun_Search[2])(pStu pHead, int num))
{
		int i,num;
		printf("学号请按1\n年龄请按2\n");
		scanf("%d",&i);
		switch(i)
		{
				case 1:
						printf("请输入学号:\n");
						break;
				case 2:
						printf("请输入年龄:\n");
						break;
				default:
						printf("输入无效！\n");
						return 0;
						break;
		}
		scanf("%d",&num);
		if(pFun_Search[i-1](pHead,num)==0)
		{
				return -1;
		}
		return 0;
}

int find_num(pStu pHead,int num)
{
		int n=0;
		pStu p;
		p=pHead->next;
		while(p!=NULL)
		{
				if(p->num==num)
				{
						p->stu_print(p);
						n++;
				}
				p=p->next;
		}
		return n;
}

int find_age(pStu pHead,int age)
{
		int n=0;
		pStu p;
		p=pHead->next;
		while(p!=NULL)
		{
				if(p->age==age)
				{
						p->stu_print(p);
						n++;
				}
				p=p->next;
		}
		return n;
}
