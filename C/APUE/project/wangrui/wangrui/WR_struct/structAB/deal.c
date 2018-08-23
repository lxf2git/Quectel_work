#include"main.h"

void deal_chain(pNode pHeadA,pNode pHeadB)
{
	pNode pA=NULL;	
	pNode pB=NULL;
	pNode ptmp=NULL;
	pNode pdel=NULL;
	int same;
	int jud = 0;	
	for(pA=pHeadA->next;
			pA!=pHeadA;)
	{
		for(pB=pHeadB;
				pB->next!=pHeadB;)
		{
			if(pB->next->data == pA->data)
			{
				pdel = pB->next;
				same = pdel->data;
				jud = Destory_node(pB,&pdel);
				continue;
			}
			pB=pB->next;
		}
		if(jud == 1)
		{
			for(ptmp=pA;
					ptmp->next!=pHeadA;)
			{
				if(ptmp->next->data == same)
				{
					pdel = ptmp->next;
					jud = Destory_node(ptmp,
									&pdel);
					continue;
				}
				ptmp = ptmp->next;
			}
			pA=pA->prev;
			pdel = pA->next;
			Destory_node(pA,&pdel);
		}
		jud = 0;
		pA=pA->next;
//		printf("==========\n");
		show_chain(pHeadA);
		show_chain(pHeadB);
//		printf("==========\n");
	}

}


int Destory_node(pNode pPos,pNode *pdel)
{
	pPos->next = (*pdel)->next;
	(*pdel)->next->prev = pPos;
	(*pdel)->next = NULL;
	(*pdel)->next = NULL;
	free_node(pdel);
	return 1;
}
