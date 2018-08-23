#include"print.h"

void prrint(pStu p)
{
	printf("num:%dage:%d\n",p->num,p->age);
}

void pprint(pStu pHead)
{
	pStu ptail = pHead;
	while(ptail->next!=NULL)
	{
		ptail->stu_print = prrint;
		ptail->stu_print(ptail->next);
		ptail = ptail->next;
	}
}

void Print(sList slist,pStu pHead)
{
	slist.pPrint = pprint;
	slist.pPrint(pHead);
}
