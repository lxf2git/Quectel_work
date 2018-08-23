#include"stack.h"

void create_memoryx(pStackx p)
{
	p->bottom = (char *)malloc(sizeof(char)*SIZE); 
}

void init_stackx(pStackx p)
{
		create_memoryx(p);
		p->top=0;
}

void create_memoryn(pStackn p)
{
	p->bottom = (int *)malloc(sizeof(int)*SIZE); 
}

void init_stackn(pStackn p)
{
		create_memoryn(p);
		p->top=0;
}

int pushx(pStackx ps,char mod)
{
	if(ps->top==SIZE)
	{
			printf("full!\n");
			return FULL;
	}
	ps->bottom[ps->top++] = mod;
	return SUC;
}

int popx(pStackx ps,char *pop_char)
{
	if(ps->top<=0)
	{
			return EMPTY;
	}	
	ps->top--;
	*pop_char = ps->bottom[ps->top];
	return SUC;
}
int pushn(pStackn ps,int mod)
{
	if(ps->top==SIZE)
	{
			printf("full!\n");
			return FULL;
	}
	ps->bottom[ps->top++] = mod;
	return SUC;
}

int popn(pStackn ps,int *pop_char)
{
	if(ps->top<=0)
	{
			return EMPTY;
	}	
	ps->top--;
	*pop_char = ps->bottom[ps->top];
	return SUC;
}
