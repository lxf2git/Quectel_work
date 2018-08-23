#include"main.h"

void pprint(pStu ptmp)
{
	printf("id:---->%-3d age:---->%-3d\n",ptmp->num,ptmp->age);
}



void print(pStu phead)
{
	pStu ptmp=phead->next;
	while(ptmp!=NULL)
	{
		(ptmp->stu_print)=pprint;
		ptmp->stu_print(ptmp);
		ptmp=ptmp->next;
	}
}
void print_chain(pStu phead,pList pl)
{
	pl->pPrint=print;
	(pl->pPrint)(phead);
}
