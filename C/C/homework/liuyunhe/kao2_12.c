#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
int put(int a,int b)
{
		return a/b;
}
int pfun(int (*fun)(int,int),int a,int b)
{
		int m;
		m=fun(a,b);
		return m;
}

int main(int argc,char *argv[])
{
		int l1,l2;
		int a=0;
		int b=0;
		int i,st;
		l1=strlen(argv[1]);
		l2=strlen(argv[3]);
		for(i=0;i<l1;i++)
		{
				a=a+argv[1][i]-48;
				printf("a:%d\n",a);
				if((i+1)<l1)
				{
						a=a*10;
				printf("a:%d\n",a);
				}
		}
		for(i=0;i<l2;i++)
		{
				b=b+argv[3][i]-48;
				printf("b:%d\n",b);
				if((i+1)<l2)
				{
						b=b*10;
				printf("b:%d\n",b);
				}
		}
		printf("%s\n",argv[2]);
		printf("%s\n",argv[3]);
		char ch=*argv[2];
		switch(ch)
		{
				case '+':
						st=pfun(add,a,b);
						break;
				case '-':
						st=pfun(sub,a,b);
						break;
				case '*':
						st=pfun(mul,a,b);
						break;
				case '/':
						st=pfun(put,a,b);
						break;
				default:
						printf("错误\n");
						break;
		}
		printf("%d\n",st);
		return 0;
}
