#include"stack.h"
void create_memory(int**q)
{
	*q=(int *)malloc(SIZE*sizeof(int));
	if(*q==NULL)
	{
		printf("malloc fail");
		exit(-1);
	}
}
void init_stack(pStack ps)
{
	create_memory(&ps->bottom);
	ps->top=0;
}
int push(pStack ps,int mod)
{
	if(ps->top==SIZE)
	{
		printf("full");
		return FULL;
	}
	ps->bottom[ps->top]=mod;
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
