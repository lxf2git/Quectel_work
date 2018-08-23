#include"stack.h"
void create_memory(int**q)
{
	*q = (int *)malloc(SIZE*sizeof(int));
	if(NULL==*q)
	{
		printf("malloc fail");
		exit(-1);
	}
}
void init_stack(pStack ps)
{
  //空间
  create_memory(&ps->bottom);
  //下标初始化
  ps->top = 0;
}

int push(pStack ps,int mod)
{
	//1 判断栈是否为满
	if(ps->top==SIZE)
	{
		printf("full");
		return FULL;
	}
	//2 入栈  入 top++
	 ps->bottom[ps->top] = mod;
	 ps->top++;
	 //ps->bottom[ps->top++] = mod;
	 return SUC;
}

int pop(pStack ps,int *pop_data)
{
	//1 判断栈是否为空
	if(ps->top==0)
	{
		return EMPTY;
	}

	//2 出栈 top-- 数据出栈
	ps->top--;
	*pop_data =ps->bottom[ps->top];
   return SUC;	
}

