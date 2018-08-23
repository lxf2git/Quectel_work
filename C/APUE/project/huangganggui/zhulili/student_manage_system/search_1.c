#include"search_1.h"

int  search_age(pStu pHead,int num)
{
	pStu ptmp = pHead;
	int Age;
	int flag = 0;
	printf("请输入要查找的年龄:");
	scanf("%d",&Age);
	printf("按年龄查找的结果:\n");
	while(ptmp != NULL)
	{
		if(ptmp->age == Age)
		{	
			flag = 1;
			if(flag == 1)
			{
				printf("age:%d  num:%d\n",ptmp->age,ptmp->num);	
			}					
		}		
		ptmp = ptmp->next;		
	}
	if(flag == 0)
		printf("没有符合的age!\n");	
}
int search_num(pStu pHead,int num)
{
	pStu ptmp = pHead;
	int Num;
	int flag = 0;
	printf("请输入要查找的num:");
	scanf("%d",&Num);
	printf("按num查找的结果:\n");
	while(ptmp != NULL)
	{
		if(ptmp->num == Num)
		{	
			flag = 1;
			if(flag == 1)
			{
				printf("num:%d  age:%d\n",ptmp->num,ptmp->age);	
			}
		}		
		ptmp = ptmp->next;		
	}
	if(flag == 0)
		printf("  没有符合的num!  \n");
}

int pSearch(pStu pHead, int (*pFun_Search[2])(pStu pHead, int num))
{
	int choose;
	int num = choose-1;
	printf("请选择:\n");
	printf("1--------按age查找:\n");
	printf("2--------按num查找:\n");
	printf("3----------退出查找:\n");
	while(pHead != NULL)
	{
		
			scanf("%d",&choose);
			if(choose != 1 && choose != 2 && choose != 3)
				printf("输入有误，请重新输入！\n");
			if(choose == 1)
			{
				pFun_Search[choose-1](pHead,num);
				//pSearch();
			}
			if(choose == 2)
			{
				pFun_Search[choose-1](pHead,num);
				//pSearch();
			}
			if(choose == 3)
				break;	
	}
}

void find(pStu pHead)
{	
	int (*pFun_Search[2])(pStu pHead,int num) = {search_age,search_num};
	pSearch(pHead, pFun_Search);
}
