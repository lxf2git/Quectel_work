#include"stack.h"

void init_OP(pStack_ch pf)
{
		great_memory((char **)&pf->bottom,10*sizeof(char));
		pf->top=0;
}

int push_ch(pStack_ch ps,char data)
{
		if(ps->top==50)
		{
				printf("full\n");
				return FULL;
		}
		ps->bottom[ps->top]=data;
		ps->top++;
		return SCU;
}

int pop_ch(pStack_ch ps,char *pop_data)
{
		if(ps->top==0)
		{
				return EMPTY;
		}
		ps->top--;
		*pop_data=ps->bottom[ps->top];
		return SCU;
}
