#include"stack.h"

void creat_memory(int **p,int size)
{
	*p=(int*)malloc(size);
	if(NULL==*p)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void init_stack(pSta ps)
{
	ps->top=0;
}

int push(pSta ps,int low,int high)
{
	if(ps->top==SIZE)
	{
		printf("stack full\n");
		return FULL;
	}
	ps->top++;
	ps->low[ps->top]=low;
	ps->high[ps->top]=high;
	return SUC;
}

int pop(pSta ps,int *low,int *high)
{
	if(ps->top==0)
	{
		return EMPTY;
	}
	*low=ps->low[ps->top];
	*high=ps->high[ps->top];
	ps->top--;
	return SUC;
}
