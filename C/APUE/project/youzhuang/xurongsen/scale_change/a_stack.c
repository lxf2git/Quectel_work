#include"stack.h"
/*
#include<stdio.h>
#include<stdlib.h>
#define SIZE 2
*/
//十进制转换

void choose(sStack sta,sStack stb,sStack stc,int chos)
{
	switch(chos)
	{
		case TWO:
				{
					show_two(sta);
					break;
				}
		case EIGHT:
				{
					show_eig(sta);
					break;
				}
		case SIXTEEN:
				{
					show_two(stc);
					break;
				}
		default:{
					printf("no other case output!\n");
					break;
				}
	}
}

void show_two(sStack sta)
{
	int pop_data;//出栈的数字
	while((pop_stack(&sta,&pop_data))!=EMPTY)
	{
		if(pop_data > 9)
		{
			pop_data = pop_data+55;
	   	printf("%c ",pop_data);
		}
		else
		{
			printf("%d ",pop_data);
		}
	}
	printf("\n");
}
void show_eig(sStack sta)
{
	int pop_data;//出栈的数字
	int pop_eig;
	int sum=0,n=0;
	int d=4;
	sStack ste;
	init_stack(&ste);
	printf("show_eig\n");
	while((pop_stack(&sta,&pop_data))!=EMPTY)
	{
		printf("eight-->while!\n");
		printf("%d ",pop_data);
		pop_eig = pop_data;
		printf("pop_eig:%d\n",pop_eig);
		push_stack(&ste,pop_eig);
	}
	while((pop_stack(&ste,&pop_eig)) != EMPTY)
	{
		printf("%d ",pop_eig);
		sum = sum+pop_eig*recur(n);
		n++;
	printf("init_stack:pop success!\n");
		if(3 == n)
		{
			printf("%d ",sum);
			sum=0;
			n=0;
		}
	}
	printf("\n");
}

int recur(int n)
{
	if(n=0)
	{
		return 1;
	}
	else
	{
		return 2*recur(n-1);
	}
}

void show_six(sStack sta)
{
	int pop_data;//出栈的数字
	while((pop_stack(&sta,&pop_data))!=EMPTY)
	{
		printf("%d ",pop_data);
	}
	printf("\n");
}

int main()
{
	int data,mod;
	int pop_data,d;//出栈的数字
	int chos;//选择的类型
	sStack sta;
	init_stack(&sta);
	sStack stb;
	init_stack(&stb);
	sStack stc;
	init_stack(&stc);
	printf("please input data:");
	scanf("%d",&data);
	d=data;
	while(data!=0)
	{
		mod = data%2;
		push_stack(&sta,mod);
		data = data/2;
	}
	data=d;
	while(data!=0)
	{
		mod = data%8;
		push_stack(&stb,mod);
		data = data/8;
	}
	
	data=d;
	while(data!=0)
	{
		mod = data%16;
		push_stack(&stc,mod);
		data = data/16;
	}
	printf("please choose output case:(1:二进制2:八进制3:十六进制):");
	scanf("%d",&chos);

	choose(sta,stb,stc,chos);
/*
	while((pop_stack(&sta,&pop_data))!=EMPTY)
	{
		printf("%d ",pop_data);
	}
	printf("\n");
*/
	return 0;
}
