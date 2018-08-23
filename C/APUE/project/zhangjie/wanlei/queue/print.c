#include"print.h"

void print(pQue pq, pTree root)
{
	pTree p=root;
	push(pq,p);
	while(pop(pq,&p)!=EMPTY)
	{
		printf("%c ",p->data);
	//	printf("%c %c ",p->lc->data,p->rc->data);
		if(p->lc!=NULL)
		{
			push(pq,p->lc);
		}
		if(p->rc!=NULL)
		{
			push(pq,p->rc);
		}
	}
	printf("\n");
}
