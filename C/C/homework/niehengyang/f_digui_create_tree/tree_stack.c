#include"main.h"

void push(pStack sta,pTree ptmp)
{
	if(sta->top==20)
	{
		printf("full Stack\n");
		exit(-1);
	}
	(sta->top)++;
	*(sta->bottom+(sta->top))=ptmp;
}

void pop(pStack sta,pTree *data)
{
	if(sta->top==0)
	{
		printf("stack empty\n");
		exit(-1);
	}
	(*data)=*(sta->bottom+(sta->top));
	(sta->top)--;
}

void init_stack(pStack sta)
{
	sta->bottom=malloc(sizeof(pTree)*20);
	sta->top=0;
}
