#include"main.h"


int stu_in(pStu p)
{
	printf("请输入学生的ID和年龄:\n");
	scanf("%d%d",&p->num,&p->age);
	return 0;
}

/*void create_memory1(pStu *p)
{
	*p=(pStu)malloc(sizeof(sStu));
	if((*p)->next!=NULL)
	{
		(*p)->next=NULL;
	}
}*/

pStu f_max(pStu pHead,pStu pnew)
{
	pStu ptmp=pHead;
	while(ptmp->next!=NULL)
	{
		if(ptmp->next->num>=pnew->num)
		{
			return ptmp;
		}
		ptmp=ptmp->next;
	}
	return ptmp;
}

int f_find(pStu pHead,pStu pnew)
{
	pStu ptmp=pHead;
	while(ptmp->next!=NULL)
	{
		if(ptmp->next->num==pnew->num)
		{
			return 1;
		}
		ptmp=ptmp->next;
	}
	return 0;
}

int pinsert(pStu pHead,pStu pnew,int (*pIDFind)(pStu pHead, pStu pnew), pStu (*pInsertPosition)(pStu pHead, pStu pnew))
{
	pStu p_max;
	pStu ptmp=pHead;
	if((pIDFind(pHead,pnew))==1)
	{
		printf("您输入的ID已经存在!\n");
		return 0;
	}
	else
	{
		p_max=pInsertPosition(pHead,pnew);
		pnew->next=p_max->next;
		p_max->next=pnew;
	}
	return 0;
}

void insert_chain(pStu phead,sList pl)
{
	pStu pnew=NULL;
	init_memory(&pnew);
	pnew->stu_input=stu_in;
	pnew->stu_input(pnew);
	pl.pInsert=pinsert;
	pl.pInsert(phead,pnew,f_find,f_max);
}
