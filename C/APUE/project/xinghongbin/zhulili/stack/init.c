#include"init.h"

void create_memory(int **p)
{
	*p = (int *)malloc(SIZE*sizeof(int));
	if(*p == NULL)
	{
		printf("malloc error");
		exit(-1);
	}
}

void init_stack(pStack stack )
{
	create_memory(&stack->bottom);
	//初始化
	stack->top = 0;
}


int push(int mod,pStack ps)  //入栈
{
	if(ps->top == SIZE)
	{
		printf("栈满");
		return FULL;
	}
	ps->bottom[ps->top] = mod;
	
	ps->top++;
	return SUC;
}

int pop(pStack ps,int *pop_data)
{
	if(ps->top == 0)
	{
		return EMPTY;
	}
	ps->top--;
	//printf("top:%d\n",ps->top);
	*pop_data = ps->bottom[ps->top];
	//printf("pop_data:%d\n",*pop_data);
	return SUC;
}
