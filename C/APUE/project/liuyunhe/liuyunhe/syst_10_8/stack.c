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
		greate_memory(&pS->bottom);
		pS->top=0;
}

int push(pStack ps,int mod)
{
		if(ps->top==50)
		{
				printf("FULL\n");
				return FULL;
		}
		ps->bottom[ps->top] = mod;
		ps->top++;
		return SUC;
}

int pop(pStack ps,int *pop_data)
{
		if(ps->top==0)
		{
			return EMPTY;
		}
		ps->top--;
		*pop_data=ps->bottom[ps->top];
		return SUC;
}
