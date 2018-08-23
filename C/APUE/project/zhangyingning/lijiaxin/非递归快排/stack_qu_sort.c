#include"stack.h"

void get_memory(void **p,int size)
{
		*p = malloc(size);
		if(*p==NULL)
		{
				printf("malloc error!\n");
				exit(-1);
		}
}
int push(pStack skt,int data)
{
		printf("data:%d\n",data);
		if(skt->top == SIZE)
		{
				printf("full\n");
				return FULL;
		}
		skt->bottom[skt->top++] = data;
		return SUC;
}
int pop(pStack skt,int *data)
{
		if(skt->top == 0)
		{
				printf("FULL\n");
				exit(-1);
		}
		*data = skt->bottom[--skt->top];
		printf("*data:%d \n",*data);
}


