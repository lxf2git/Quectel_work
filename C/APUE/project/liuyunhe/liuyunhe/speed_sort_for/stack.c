#include"stack.h"

void greate_memory(int **p)
{
		*p= malloc(SIZE*sizeof(int));
		if(NULL==*p)
		{
				printf("sorry malloc fail\n");
				exit -1;
		}
}

void init_stack(pStack pS)
{
		greate_memory(&pS->ret);
		greate_memory(&pS->low);
		greate_memory(&pS->high);
		pS->top=0;
}

int push(pStack ps,int ret,int low,int high)
{
		if(ps->top==50)
		{
				printf("FULL\n");
				return FULL;
		}
		ps->ret[ps->top] = ret;
		ps->low[ps->top] = low;
		ps->high[ps->top] = high;
		ps->top++;
		return SUC;
}

int pop(pStack ps,int *ret,int *low,int *high)
{
		if(ps->top==0)
		{
			return EMPTY;
		}
		ps->top--;
		*ret=ps->ret[ps->top];
		*low=ps->low[ps->top];
		*high=ps->high[ps->top];
		return SUC;
}
