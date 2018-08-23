#include"stack.h"

void creat_memory(int **p,int size)
{
	*p=malloc(size);
	if(*p==NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void init_stack(pStack ps)
{
	creat_memory(&ps->bottom,SIZE*sizeof(int));
	ps->top=0;
}

int push(pStack ps,int mod)
{
	if(ps->top==SIZE)
	{
		printf("full\n");
		return FULL;
	}
	ps->bottom[ps->top++]=mod;
	return SUC;
}

int pop(pStack ps,int *pop_data)
{
	if(ps->top==0)
	{
		return EMPTY;
	}
	*pop_data=ps->bottom[--ps->top];
	return SUC;
}
