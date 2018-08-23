#include"stack.h"
void create_memory(int **p)
{
		*p = (int *)malloc(SIZE*sizeof(int));
		if(NULL == *p)
		{
				printf("memory error\n");
				exit(-1);
		}
}
void stack_init(pSta p)
{
		create_memory(&p->bottom);
		p->top = 0;
}
int push(pSta p,int data)
{
		if(p->top == SIZE)
		{
				printf("stack is full\n");
				return FULL;
		}
		p->bottom[p->top++] = data;

		return 0;
}
int pop(pSta p,int *result)
{
		if(p->top == 0)
		{
				printf("\nstack id empty\n");

				if(NULL != p)
				{
				free(p->bottom);
				p->bottom =NULL;
				printf("\nfree--free\n");
				}
				return EMPTY;
		}
		*result = p->bottom[--p->top];
		return 0;

}


