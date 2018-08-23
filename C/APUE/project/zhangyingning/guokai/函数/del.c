#include"del.h"
int (*pDel)(pStu pHead, pStu (*pDelPosition)(pStu pNode, int age));

pStu del_age1(pStu pHead,int age)
{
	pStu ptrav=pHead;	
	while(ptrav->next!=NULL)
	{
		if(ptrav->next->age==age)
			return ptrav;
		pHead=pHead->next;
		continue;
	}
	printf("no find\n");
}

int del_age(pStu pHead, pStu (*pDelPosition)(pStu pHead,int age))
{
	pStu pnode=NULL;
	int age;
	scanf("%d",&age);	
	pDelPosition = del_age1;	
	pnode = pDelPosition(pHead,age);
	pStu p = pnode->next->next;
	pnode->next=pnode->next->next;
	p = NULL;
	if(p!=NULL)
	{
		free(p);
		p=NULL;
	}
}
