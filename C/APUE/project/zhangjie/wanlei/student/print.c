#include"print.h"

void pPrint(pStu pHead)
{
	pStu p=pHead;
	while(p->next!=NULL)
	{
		p->next->stu_print=print_;
		p=p->next;
		print_(p);
	}
}

void print_(pStu p)
{
	printf("id:%d age:%d\n",p->num,p->age);
}
