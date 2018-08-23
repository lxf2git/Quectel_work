#include"del.h"

int pDel(pStu pHead,pStu (*pdelp)(pStu,int))
{
	printf("请输入要删除人的年龄\n");
	int age;
	scanf("%d",&age);
	pStu p1=NULL;
	pStu p2=NULL;
	while(1)
	{
		p1=pdelp(pHead,age);
		if(p1!=NULL)
		{
			p2=p1->next;
			p1->next=p2->next;
			p2->next=NULL;
			i_free((void **)&p2);
		}
		else
		{
		 	break;
		}
	}
}

pStu pdelp(pStu pHead,int age)
{
	pStu ptar=pHead;
	while(ptar->next!=NULL)
	{
		if(ptar->next->age==age)
		{
			return ptar;
		}
		ptar=ptar->next;
	}
	ptar=NULL;
	return ptar;
}
