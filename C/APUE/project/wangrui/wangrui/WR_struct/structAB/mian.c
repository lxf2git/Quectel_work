#include"main.h"

int main()
{
	pNode pHeadA = NULL;
	pNode pHeadB = NULL;
	init_node(&pHeadA);
	init_node(&pHeadB);
	creat_chain(pHeadA);
	creat_chain(pHeadB);
	deal_chain(pHeadA,pHeadB);
	show_chain(pHeadA);
	show_chain(pHeadB);
	return 0;
}

void show_chain(pNode pHead)
{
	pNode ptmp = pHead;
	for(ptmp=pHead->next;
			ptmp != pHead;
				ptmp = ptmp->next)
	{
		printf("%d ",ptmp->data);
	}
	printf("\n");
}
