#include"stack.h"

void great_memory(char **pf,int size)
{
		*pf=malloc(size);
}


void init_OD(pStack_in pf)
{
		great_memory((char **)&pf->data_head,10*sizeof(int));
		pf->top=0;
}

int push_in(pStack_in ps,int data)
{
		if(ps->top==50)
		{
				printf("full\n");
				return FULL;
		}
		ps->data_head[ps->top]=data;
		ps->top++;
		return SCU;
}

int pop_in(pStack_in ps,int *pop_data)
{
		if(ps->top==0)
		{
				return EMPTY;
		}
		ps->top--;
		*pop_data=ps->data_head[ps->top];
		return SCU;
}
