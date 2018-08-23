#include<stdio.h>
int comp1(int a,int b,int c);
int comp2(int a,int b,int c);
int sum(int n,int m);
int main()
{
		int a,b,c;
		printf("请输入3个整数，用空格隔开，以回车结束!\n");
		scanf("%d%d%d",&a,&b,&c);
		int n=comp1(a,b,c);
		int m=comp2(a,b,c);
		int h=sum(n,m);
		printf("最大的数是：%d\n",n);
		printf("最小的数是：%d\n",m);
		printf("做差后的数：%d\n",h);
}
int comp1(int a,int b,int c)
{
		if(a>=b&&a>=c)
				return a;
		else if(b>=a&b>=c)
				return b;
		else return c;
}
int comp2(int a,int b,int c)
{
		if(a<=b&&a<=c)
				return a;
		else if(b<=a&&b<=c)
				return b;
		else return c;
}
int sum(int n,int m)
{
		return n-m;
}
