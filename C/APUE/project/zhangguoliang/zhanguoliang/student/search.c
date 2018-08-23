#include"search.h"

void SEARCH(pStu pHead,pList plist)
{
	int (*pFun_Search[2])(pStu,int);
	pFun_Search[0]=Fun_Search1;
	pFun_Search[1]=Fun_Search2;
	
	plist->pSearch(pHead,&(*pFun_Search));

}

int Fun_Search2(pStu pHead,int num)
{
	pStu pnew=pHead->next;
	while(pnew!=NULL)
	{
		if(pnew->age==num)
		{
			pnew->stu_print(pnew);
			return 1;
		}
		pnew=pnew->next;
	}
	return 0;
}

int Fun_Search1(pStu pHead,int num)
{
	printf("*\n");
	pStu pnew=pHead->next;
	while(pnew!=NULL)
	{
		if(pnew->num==num)
		{
			pnew->stu_print(pnew);
			return 1;
		}
		pnew=pnew->next;
	}
	return 0;
}

int Search(pStu pHead,int (**pFun_Search)(pStu pHead, int num))
{
	printf("=======Search:\n");
	printf("1   id\n2   age\n");
	printf("please input you choose:\n");
	int choose,num;
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
			printf("please input id\n");
			scanf("%d",&num);
			int a=(*pFun_Search+0)(pHead,num);
			if(a==1)
			{
				printf("search successful\n");
			}
			else
			{
				printf("No student\n");
			}
			break;
		case 2:
			printf("please input age\n");
			scanf("%d",&num);
			int b=(*pFun_Search+1)(pHead,num);
			if(b==1)
			{
				printf("search successful\n");
			}
			else
			{
				printf("No student\n");
			}
			break;
	}
}
