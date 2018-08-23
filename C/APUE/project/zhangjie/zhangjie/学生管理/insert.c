#include "main.h"
#include "init.h"

int find(pStu p,pStu pn)
{
	pStu ptemp=NULL;
	for(ptemp=p->next;ptemp!=NULL;ptemp=ptemp->next)
	{
		if((ptemp->num)==(pn->num))
		{
			printf("input the same num\n");
			return -1;
		}
	}
	return 0;
}

pStu  max(pStu p,pStu pn)
{
	pStu ptemp=p;
	while(ptemp->next!=NULL)
	{
		if(ptemp->next->num > pn->num)
		{
			return ptemp;
		}
		ptemp=ptemp->next;
	}
	return ptemp;
}

int insert(pStu p,pStu pn,int (*pIDFind)(pStu pHead,pStu pInsert),pStu (*pInsertPosition)(pStu pHead,pStu pInsert))
{
	int i;
	pStu ptemp=NULL;
	pIDFind=find;
	i=pIDFind(p,pn);
	if(i==-1)
	{
		return -1;
	}
	pInsertPosition=max;
	ptemp=pInsertPosition(p,pn);
	change(ptemp,pn);
}

int  stu_inp(pStu p)
{
	scanf("%d%d",&p->num,&p->age);
}

void stu_pri(pStu p)
{
	printf("======================\n");
	printf("---------%d %d-------\n",p->num,p->age);
	printf("======================\n");
	printf("\n");
}
