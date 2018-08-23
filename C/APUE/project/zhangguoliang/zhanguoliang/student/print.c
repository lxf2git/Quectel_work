#include"print.h"

void sprint(pStu p)
{
	printf("id:%d age:%d\n",p->num,p->age);
}

void PRINT(pStu pHead)
{
	pStu pnew=pHead->next;
	while(pnew!=NULL)
	{
		pnew->stu_print(pnew);
		pnew=pnew->next;
	}
}

void Print(pStu pHead)
{
	;
}
