#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void fun(char *p);
void output(char *p,int x);
void menu(char s,int x,int y);
void fun1(int (*pf)(int,int),int x,int y);
int add(int x,int y);
int dec(int x,int y);
int mul(int x,int y);
int div_(int x,int y);

int main(int argc,char *argv[])
{
	if(argc==1)
	{
		printf("file_name argument\n");
		exit(-1);
	}
	fun(argv[1]);
	return 0;
}
void fun(char *p)
{
	int i;
	int a;
	for(i=0;;i++)
	{
		if(p[i]=='+'||p[i]=='-'||p[i]=='*'||p[i]=='/')
		{
			a=i;
			break;
		}
	}
	output(p,a);
}

void output(char *p,int x)
{
	int i;
	int s=0,t=0;
	char ch;
	for(i=0;i<strlen(p);i++)
	{
		if(i<x)
		{
			s=s*10+(p[i]-48);
		}
		else if(i>x)
		{
			t=t*10+(p[i]-48);
		}
		else
		{
			ch=p[i];
		}
	}
	menu(ch,s,t);
}

void menu(char s,int x,int y)
{
	switch(s)
	{
		case '+':
			fun1(add,x,y);
			break;
		case '-':
			fun1(dec,x,y);
			break;
		case '*':
			fun1(mul,x,y);
			break;
		case '/':
			if(y==0)
			{
				printf("div error\n");
			}
			else
			{
				fun1(div_,x,y);
			}
			break;
		default:
			printf("input error\n");
			break;
	}
}

void fun1(int (*pf)(int,int),int x,int y)
{
	int ret=pf(x,y);
	printf("result:%d\n",ret);
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
	return x/y;
}
