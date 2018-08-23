#include"main.h"
void init_Node(pData p)
{
	p->data=0;
	p->prev=p;
	p->next=p;
}

void init_pMode(pMode *pStart)
{
	int i,j;
	*pStart=(pMode)malloc(sizeof(sMode));
	for(i=0;i<5;i++)
	{
		(*pStart)->mod[i]=(pAnd)malloc(sizeof(sAnd));
		for(j=0;j<8;j++)
		{
			(*pStart)->mod[i]->and[j]=(pData)malloc(sizeof(sData));
			init_Node((*pStart)->mod[i]->and[j]);
		}
	}
}
