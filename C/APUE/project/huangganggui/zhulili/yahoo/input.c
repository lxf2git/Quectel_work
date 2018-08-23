#include"input.h"

void insertA(pNode pHeadA)
{
	pNode pnew;
	pNode ptmp = pHeadA;	
	init_node(&pnew,sizeof(sNode));
	scanf("%d",&pnew->data);
	pnew->prev = ptmp;
	ptmp->next->prev = pnew;
	pnew->next = ptmp->next;
	ptmp->next  = pnew;				
}

void insertB(pNode pHeadB)
{
	pNode pnew;	
	pNode ptmp = pHeadB;
	init_node(&pnew,sizeof(sNode));
	scanf("%d",&pnew->data);
	pnew->prev = ptmp;
	ptmp->next->prev = pnew;
	pnew->next = ptmp->next;
	ptmp->next  = pnew;		
}
