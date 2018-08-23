#include"search.h"
void pFun_Search(pStu pHead,sList slist)
{
	int (*p[2])(pStu,int)={search_age,search_id};
	slist.pSearch=search;
	slist.pSearch(pHead,p);
}
int search_age(pStu pHead,int num)
{
	int in,i=0;
	printf("请输入你查询的学生的Age\n");
	scanf("%d",&in);
	pStu stmp;
	stmp=pHead;
	while(stmp->next != NULL)
	{
		if(stmp->next->age==in)
		{
			printf("Name:%s Age:%d Id:%d\n",stmp->next->name,
						stmp->next->age,stmp->next->id);
			i++;
		}
		stmp=stmp->next;
	}
	if(i==0)
	{
		printf("不存在满足条件的学生!\n");
	}
	return 0;
}
int search_id(pStu pHead,int num)
{
	int in,i=0;
	printf("请输入你查询的学生的Id\n");
	scanf("%d",&in);
	pStu stmp;
	stmp=pHead;
	while(stmp->next != NULL)
	{
		if(stmp->next->id==in)
		{
			printf("Name:%s Age:%d Id:%d\n",stmp->next->name,
						stmp->next->age,stmp->next->id);
			i++;
		}
		stmp=stmp->next;
	}
	if(i==0)
	{
		printf("不存在满足条件的学生!\n");
	}	
	return 0;
}
int search(pStu pHead, int (*pFun_Search[2])(pStu pHead, int num))
{
	int flag;
	int num=0;
	printf("|输入1*******按年龄查询|**|输入2********按Id查询|\n");
	scanf("%d",&flag);	
	if(flag==1)
	{
		pFun_Search[0](pHead,num);
	}
	else if(flag==2)
	{
		pFun_Search[1](pHead,num);
	}
	else
	{
		printf("你输入错误!\n");
		return;			
	}
	return 0;
}


