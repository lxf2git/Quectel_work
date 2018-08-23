
#include"stack.h"

void init_stack(pStack ps)
{
	creat_memory((void **)&ps->bottom,SIZE*sizeof(int));
	ps->top = 0;
}
		
void creat_memory(void **p,int size)
{
	*p = malloc(size);
	if(*p==NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

int push(pStack ps,int mod)
{
	if(ps->top == SIZE)
	{
		printf("full\n");
		return -1;
	}
	ps->bottom[ps->top]=mod;
//	printf("pubot%d\n",ps->bottom[ps->top]);
	ps->top++;
	return 0;
}

int pop(pStack ps,int *pop_data)
{
	if(ps->top == 0)
	{
		return -1;
	}
	ps->top--;
	*pop_data = ps->bottom[ps->top];
//	printf("popdata:%d bot%d\n",*pop_data,ps->bottom[ps->top]);
	
	return 0;
}
