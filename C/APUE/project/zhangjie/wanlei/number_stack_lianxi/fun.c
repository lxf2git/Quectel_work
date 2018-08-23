#include"fun.h"

void fun(void (*pf)(pStack,int),pStack ps, int data)
{
	pf(ps,data);
}

void ten_two(pStack ps,int data)
{
	int mod;
	int pop_data;
	while(data!=0)
	{
		mod=data%2;
		push(ps,mod);
		data=data/2;
	}
	while(pop(ps,&pop_data)!=EMPTY)
	{
		printf("%d ",pop_data);
	}
	printf("\n");
}

void ten_eight(pStack ps,int data)
{
	int mod;
	int pop_data;
	while(data!=0)
	{
		mod=data%8;
		push(ps,mod);
		data=data/8;
	}
	while(pop(ps,&pop_data)!=EMPTY)
	{
		printf("%o ",pop_data);
	}
	printf("\n");
}

void ten_sixteen(pStack ps,int data)
{
	int mod;
	int pop_data;
	while(data!=0)
	{
		mod=data%16;
		push(ps,mod);
		data=data/16;
	}
	while(pop(ps,&pop_data)!=EMPTY)
	{
		printf("%x ",pop_data);
	}
	printf("\n");
}
