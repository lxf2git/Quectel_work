#include"calculate.h"

void creat_memory(void **p,int size)
{
	*p = malloc(size);
	if(*p == NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void init_stack_int(pStack1 psd)
{
	creat_memory((void **)&psd->bottom,
					SIZE*sizeof(sStack1));
	psd->top = 0;
}
void init_stack_char(pStack2 psc)
{
	creat_memory((void **)&psc->bottom,
					SIZE*sizeof(sStack2));
	psc->top = 0;
}

int push_int(pStack1 psd,int num)
{
	if(psd->top == SIZE)
	{
		printf("full");
		return FULL;
	}
	psd->bottom[psd->top] = num;
	psd->top++;
	return SUC;
}
int push_ch(pStack2 psc,char sign)
{
	if(psc->top == SIZE)
	{
		printf("full");
		return FULL;
	}
	psc->bottom[psc->top] = sign;
	psc->top++;
	return SUC;
}

int pop_int(pStack1 psd,int *pop_num)
{
	if(psd->top == 0)
	{
		printf("empty\n");
		return EMPTY;
	}
	psd->top--;
	*pop_num = psd->bottom[psd->top];
	return SUC;
}
int pop_ch(pStack2 psc,char *pop_sign)
{
	if(psc->top == 0)
	{
		printf("empty\n");
		return EMPTY;
	}
	psc->top--;
	*pop_sign = psc->bottom[psc->top];
	return SUC;
}
