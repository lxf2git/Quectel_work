#include"print.h"

void _print(pStu pHead)
{
	pStu ptmp;
	for(ptmp=pHead->next;ptmp!=NULL;ptmp=ptmp->next)
	{
		printf("==num:%d age:%d==\n",ptmp->num,ptmp->age);
	}	
}

void s_print(pStu pHead)
{
	pList p_list;
	p_list->pPrint=_print;
	p_list->pPrint(pHead);
	
}
