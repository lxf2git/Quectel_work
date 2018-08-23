#include"del.h"


void DEL(pStu pHead,pList plist)
{
	int a=plist->pDel(pHead,DelPosition);
	if(a==0)
	{
		printf("no student\n");
	}
	else
	{
		printf("clear over\n");
	}
}

pStu DelPosition(pStu pNode,int age)
{
	pStu pnew=pNode;
	while(pnew->next!=NULL)
	{
		if(pnew->next->age==age)
		{
			return pnew;
		}
		pnew=pnew->next;
	}
	return NULL;
}

int Del(pStu pHead,pStu(*pDelPosition)(pStu pNode,int age))
{
	printf("please input age:\n");
	int age,a=0;
	scanf("%d",&age);
	pStu ptmp=pDelPosition(pHead,age);
	while(ptmp!=NULL)
	{
		pStu pdel=ptmp->next;
		ptmp->next=ptmp->next->next;
		free(pdel);
		ptmp=pDelPosition(pHead,age);
		a++;
	}
	return a;
}

void dele(pStu pHead)
{
	pStu pnew=pHead;
	pStu pdel;
	while(pnew!=NULL)
	{
		pdel=pnew->next;
		pnew->next=pdel->next;
		pnew=pnew->next;
		free(pdel);
	}
	free(pHead);
}

