#include"search.h"

int page(pStu pHead,int age)
{
		int i=0;
		pStu palit=pHead->next;
		while(palit!=NULL)
		{
				if(palit->age==age)
				{					
						printf(" id: %d age: %d \n",palit->num,palit->age);
						i++;
				}
				palit=palit->next;
		}
		if(i==0)
		{
				printf("没有要查找的年龄\n");
		}
}

int pid(pStu pHead,int id)
{
		int i=0;
		pStu palit=pHead->next;
		while(palit!=NULL)
		{
				if(palit->num==id)
				{					
						printf(" id: %d age: %d \n",palit->num,palit->age);
						i++;
				}
				palit=palit->next;
		}
		if(i==0)
		{
				printf("没有要查找的id\n");
		}
}

int pSearch_(pStu pHead, int (*pFun_Search[2])(pStu pHead, int num))
{
		int num;
		int i;
		printf("查找方式1.age 2.id\n");
		scanf("%d",&i);
		printf("输入要查找的数据\n");
		scanf("%d",&num);
		pFun_Search[i-1](pHead,num);
}

void search(pStu pHead,sList slist)
{
		int (*p_S[2])(pStu,int)={page,pid};
		slist.pSearch=pSearch_;
		slist.pSearch(pHead,p_S);
}
