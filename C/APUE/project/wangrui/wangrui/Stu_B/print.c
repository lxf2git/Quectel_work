#include"student.h"



void Print(pStu pHead)
{
	pStu ptmp = pHead;
	for(ptmp=pHead->next;ptmp!=NULL;ptmp=ptmp->next)
	{
		ptmp->pstu_print = stu_print;
		(*ptmp->pstu_print)(ptmp);
	}
}

void stu_print(pStu ps)
{
	printf("ID:%d Age:%d\n",ps->num,ps->age);
}
