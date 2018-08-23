#include"main.h"

int search_age(pStu phead,int num)
{
	pStu ptmp=phead->next;
	while(ptmp!=NULL)
	{
		if(ptmp->age==num)
		{
			printf("ID:---->%-3d AGE:---->%-3d\n",ptmp->num,ptmp->age);
		}
		ptmp=ptmp->next;
	}
return 0;
}

int search_id(pStu phead,int num)
{
	pStu ptmp=phead->next;
	while(ptmp!=NULL)
	{
		if(ptmp->num==num)
		{
			printf("ID:---->%-3d AGE:---->%-3d\n",ptmp->num,ptmp->age);
		}
		ptmp=ptmp->next;
	}
return 0;

}




int psearch(pStu phead,int (*pFun_Search[2])(pStu phead,int num))
{	
	int data;
	while(1)
	{
	printf("按年龄查找-------->1\n");
	printf("按学号查找-------->2\n");
	scanf("%d",&data);
	if(data==1)
	{	
		printf("输入要查找的年龄:\n");
		scanf("%d",&data);
		pFun_Search[0](phead,data);
		return 0;
	}
	else if(data==2)
	{
		printf("输入要查找的学号:\n");
		scanf("%d",&data);
		pFun_Search[1](phead,data);
		return 0;
	}
	else
	{
		printf("没有这个选项!\n");
	}
	}
}
void search_chain(pStu phead,sList pl)
{	
	int (*pFun_Search[2])(pStu pHead,int num);
	pFun_Search[0]=search_age;
	pFun_Search[1]=search_id;	
	pl.pSearch=psearch;
	pl.pSearch(phead,pFun_Search);
	
}
