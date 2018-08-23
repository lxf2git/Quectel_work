#include"stack.h"
//-------------------分文件-------------
//初始化
void init_stack(pStack ps)
{
	create_memory((void**)(&ps->bottom));
	ps->top = 0;
}

void create_memory(void **p)
{
	*p = malloc(SIZE*sizeof(int));
	if(NULL == *p)
	{
		printf("malloc error!\n");
		exit(-1);
	}
}
//入栈
int push_stack(pStack ps, int mod)
{
	//是否为满
	if(ps->top == SIZE)
	{
		printf("stack full!\n");
		return FULL;
	}
	//入栈：top++
	ps->bottom[ps->top] = mod;
//	printf(" %d ",ps->bottom[ps->top]);
	ps->top++;
	return SUC;
}

int pop_stack(pStack ps,int * pop_data)
{
	//是否为空
	if(ps->top == 0)
	{
		return EMPTY;
	}
	//出栈，top-- 数据出栈
	ps->top--;
//	printf(" %d ",ps->bottom[ps->top]);
	*pop_data = ps->bottom[ps->top];
	return SUC;
}
