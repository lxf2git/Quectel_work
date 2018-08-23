#include"print.h"

void input (pStu pHead)
{
	while(pHead->next!=NULL)
	{
		printf("%d %d\n",pHead->next->id,pHead->next->age);
		pHead = pHead->next;
	}
}
