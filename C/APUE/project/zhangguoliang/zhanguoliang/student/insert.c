#include"insert.h"

void INSERT(pStu pHead,pList plist)
{
	pStu pInser=NULL;
	init_stu(&pInser);
	pInser->stu_input(pInser);
	int a=plist->pInsert(pHead,pInser,IDFind,InsertPosition);
	if(a==1)
	{
		printf("not input\n");
	}
}

void sinput(pStu pnew)
{
	printf("please input num age\n");
	scanf("%d%d",&pnew->num,&pnew->age);
}

int IDFind(pStu pHead,pStu pnew)
{
	pStu ptmp=pHead->next;
	while(ptmp!=NULL)
	{
		if(ptmp->num==pnew->num)
		{
			return 1;
		}
		ptmp=ptmp->next;
	}
	return 0;
}

pStu InsertPosition(pStu pHead,pStu pInsert)
{
	pStu ptmp=pHead;
	while(ptmp->next!=NULL)
	{
		if(ptmp->next->num > pInsert->num)
		{
			return ptmp;
		}
		ptmp=ptmp->next;
	}
	return ptmp;
}

int Insert(pStu pHead,pStu Inser,int (*pIDFind)(pStu pHead, pStu pInsert),pStu(*pInsertPosition)(pStu pHead,pStu pInsert))
{
	int ret=pIDFind(pHead,Inser);
	if(ret==1)
	{
		printf("haved id\n");
		return 1;
	}
	pStu ptmp=pInsertPosition(pHead,Inser);
	Inser->next=ptmp->next;
	ptmp->next=Inser;
	return 0;
}
