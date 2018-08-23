#include"print.h"
void Print(pStu phead)
{
	pStu ptmp = phead->next;
	while(ptmp != phead)
	{
		printf("id:%d age:%d\n",ptmp->num,ptmp->age);
		ptmp =  ptmp->next;
	}
}

