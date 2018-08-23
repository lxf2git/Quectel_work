#include "main.h"
#include "init.h"

void delete(pStu p)
{
	pStu ptemp=NULL;
	ptemp=p->next;
	p->next=ptemp->next;
	ptemp->next=NULL;
	free_m(&ptemp);
}

pStu del3(pStu p,int n)
{
	pStu ptemp=p;
//	for(ptemp=p->next;ptemp!=NULL;ptemp=ptemp->next)
	while(ptemp->next!=NULL)
	{
		if(ptemp->next->age==n)
		{
			delete(ptemp);
			continue;
		}
		ptemp=ptemp->next;
	}
}



int  del2(pStu p,pStu (*pDelPosition)(pStu pNode,int age))
{
	int age;
	pDelPosition=del3;
	printf("input the age you want to delete\n");
	scanf("%d",&age);
	pDelPosition(p,age);
}


void del(pStu p)
{
	pStu (*pDelPosition)(pStu pNode,int age);
	int (*pDel)(pStu pHead,pStu (*pDelPosition)(pStu pNode,int age));
	pDel=del2;
	pDel(p,pDelPosition);
		
}
