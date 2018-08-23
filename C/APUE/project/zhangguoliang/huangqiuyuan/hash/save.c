#include"main.h"

void save(pMode pStart)
{
	printf("please input how many number you want save:\n");
	int x,i,n;
	struct data *pnew=NULL;
	scanf("%d",&x);
	for(i=0;i<x;i++)
	{
		pnew=(pData)malloc(sizeof(sData));
		init_Node(pnew);
		scanf("%d",&n);
		pnew->data=n;
		pStart->mod[n%5]->and[n>>3&7]->next->prev=pnew;
		pnew->prev=pStart->mod[n%5]->and[n>>3&7];
		pnew->next=pStart->mod[n%5]->and[n>>3&7]->next;
		pStart->mod[n%5]->and[n>>3&7]->next=pnew;
	}
}
