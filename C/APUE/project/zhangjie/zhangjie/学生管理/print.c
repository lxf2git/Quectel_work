#include "main.h"
#include "init.h"
#include "insert.h"


void print2(pStu p)
{
	pStu ptemp=NULL;
	p->stu_print=stu_pri;
	for(ptemp=p->next;ptemp!=NULL;ptemp=ptemp->next)
	{
		//if(ptemp->age==0)
		//{
		//	continue;
		//}
		//printf("%d %d\n",ptemp->num,ptemp->age);
		p->stu_print(ptemp);
	}	
}

void print(pStu p)
{
	void (*pPrint)(pStu pHead);
	pPrint=print2;
	pPrint(p);
}
