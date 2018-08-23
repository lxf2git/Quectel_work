#include"print.h"

void print_id(pStu pHead)
{
	pStu palit = pHead->next;
	while(palit!=NULL)
	{
		printf("id:%d age:%d\n",palit->num,palit->age);
		palit=palit->next;
	}
}

void print(pStu pHead,sList slist)
{
	slist.pPrint = print_id;
	slist.pPrint(pHead);
}
