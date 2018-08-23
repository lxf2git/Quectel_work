#include"init.h"
void init_Node(struct data * pHead)
{
		pHead->data = 0;
		pHead->prev = pHead;
		pHead->next = pHead;
}

void init_pMode(pMode *pStart)
{
		int i,j;
		*pStart = (pMode)malloc(sizeof(sMode));
		for(i=0;i<5;i++)
		{
				(*pStart)->mod[i] = (struct and *)malloc(sizeof(struct and));
				for(j=0;j<8;j++)
				{
						(*pStart)->mod[i]->and[j] = (struct data *)malloc(sizeof(struct data));
						init_Node((*pStart)->mod[i]->and[j]);
				}
		}
}
