#include"fun.h"

int func(char ch,int x,int y)
{
	switch(ch)
	{
		case '+':
				return fun(add,x,y);
				break;
		case '-':
				return fun(dec,x,y);
				break;
		case '*':
				return fun(mul,x,y);
				break;
		case '/':
				return fun(div_,x,y);
				break;
		default:
				printf("传参错误\n");
				return -1;
				break;
	}
}

int fun(int(*pf)(int,int),int x,int y)
{
	return pf(x,y);
}

int add(int x,int y)
{
	return x+y;
}

int dec(int x,int y)
{
	return x-y;
}

int mul(int x,int y)
{
	return x*y;
}

int div_(int x,int y)
{
	if(y==0)
	{
		printf("operation error\n");
		exit(-1);
	}
	else
	{
		return x/y;
	}
}

int judge(char ch1,char ch2)
{
	if(ch1==ch2||(ch1=='+'&&ch2=='-')||(ch1=='-'&&ch2=='+')||(ch1=='*'&&ch2=='/')||(ch1=='/'&&ch2=='*'))
	{
		return EQUAL;
	}	
	if((ch1=='+'&&ch2=='*')||(ch1=='+'&&ch2=='/')||(ch1=='-'&&ch2=='*')||(ch1=='-'&&ch2=='/'))
	{
		return LESS;
	}
	if((ch1=='*'&&ch2=='+')||(ch1=='*'&&ch2=='-')||(ch1=='/'&&ch2=='+')||(ch1=='/'&&ch2=='-'))
	{
		return MORE;
	}
	if(ch1=='(')
	{
		return LIFT;
	}
	if(ch2==')')
	{
		return RIGHT;
	}
}
