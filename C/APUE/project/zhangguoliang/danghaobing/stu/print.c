#include"print.h"

void stu_out(struct student *p)
{
		printf("id:%d age:%d\n",p->num,p->age);
}

void Print(pStu pHead)
{
		pStu pTra = pHead->next;
		while(pTra!=NULL)
		{
				pTra->stu_print(pTra);
				pTra = pTra->next;
		}
}
