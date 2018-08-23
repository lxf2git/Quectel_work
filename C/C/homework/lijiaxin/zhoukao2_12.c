#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int add(int a,int b)
{
		return a+b;
}
int sub(int a,int b)
{
		return a-b;
}
int mul(int a,int b)
{
		return a*b;
}
int div_(int a,int b)
{
		return a/b;
}
void func(int (*fun)(int,int),int a,int b)
{
		int ret = fun(a,b);
		printf("%d\n",ret);
}
int main(int argc,char *argv[])
{
		int x=0,y=0,flag=0;
		int i,count;
		char ch;
		if(argc<2)
		{
				printf("no argument\n");
				exit(-1);
		}
		count = strlen(argv[1]);
		for(i=0;i<count;i++)
		{
			if(argv[1][i]<=57&&argv[1][i]>=48)
			{
					if(flag == 0)
					{
							x = 10*x + (argv[1][i]-48);
					}
					if(flag == 1)
					{
							y = 10*y + (argv[1][i]-48);
					}
			}
			else
			{
					ch = argv[1][i];
					flag = 1;
			}
		}
		switch(ch)
		{
		case '+':func(add,x,y);break;
		case '-':func(sub,x,y);break;
		case '*':func(mul,x,y);break;
		case '/':func(div_,x,y);break;
		default:printf("no ture!");break;
		}
		return 0;
}

