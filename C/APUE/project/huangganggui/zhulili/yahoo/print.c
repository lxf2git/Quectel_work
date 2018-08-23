#include"print.h"

void printA(pNode pHeadA)
{
	pNode ptmp = NULL;
	for(ptmp=pHeadA->next;ptmp!=pHeadA;ptmp=ptmp->next)
	{
		printf("dataA:%d\n",ptmp->data);
	}
	printf("\n");
}

void printB(pNode pHeadB)
{
	pNode ptmp;
	for(ptmp=pHeadB->next;ptmp!=pHeadB;ptmp=ptmp->next)  
	{
		printf("dataB:%d\n",ptmp->data);
	}
	printf("\n");
}

void pPrint(pNode pHeadA,pNode pHeadB)
{
	printA(pHeadA);
	printB(pHeadB);
	
}
