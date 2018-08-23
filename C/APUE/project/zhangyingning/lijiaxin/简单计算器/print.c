#include"stack.h"
int del(pStack p_data)
{
		int i=pop(p_data);
		return (pop(p_data)/i);
}
int mul(pStack p_data)
{
		int i=pop(p_data);
		printf("i: %d ",i);
		int j=pop(p_data);
		printf("j: %d\n",j);
		return (j-i);
}

void print(pStack p_data,pStack p_oper)
{
		printf("print_p_data: %d \n",p_data->bottom[p_data->top-1]);
		printf("print_p_oper: %d \n",p_oper->bottom[p_oper->top-1]);
		int i = pop(p_oper);
		while(i!=EMPTY)
		{
				switch(i)
				{
						case 1:push(p_data,pop(p_data)+pop(p_data));break;
						case 2:push(p_data,mul(p_data));break;
						case 3:push(p_data,pop(p_data)*pop(p_data));break;
						case 4:push(p_data,del(p_data));break;
				}
				 i = pop(p_oper);
		}
		printf("%d \n",pop(p_data));
}
