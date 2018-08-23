#include"stack.h"
void get_memory(void **p,int size)
{
		*p = malloc(size);
		if(NULL==*p)
		{
				printf("malloc error!\n");
				exit(-1);
		}	
}
void init_stack(pStack *pp)
{
		get_memory((void **)pp,sizeof(sStack));
		get_memory((void **)&(*pp)->bottom,SIZE*sizeof(int));
		(*pp)->top = 0;
}

int push(pStack pp,int inter) 
{
		if(pp->top == SIZE)
		{
				printf("stack full\n");
				return FULL;
		}
		pp->bottom[pp->top++] = inter;
		printf("push: %d\n",pp->bottom[(pp->top)-1]);
}
int pop(pStack pp)
{
		if(pp->top == 0)
		{
			return EMPTY;
		}	
		return pp->bottom[--pp->top];
}


