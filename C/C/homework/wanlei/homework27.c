#include<stdio.h>

int mix(int x,int y);

int main()
{
	int a,b,c;
	printf("请输入两个二位整数\n");
	scanf("%d%d",&a,&b);
	c=mix(a,b);
	printf("变化后的c值为：%d\n",c);
}

int mix(int x,int y)
{
	int a,b,c,d,e;
	a=x/10;
	b=x%10;
	c=y/10;
	d=y%10;
	e=a*100+b+c*10+d*1000;
	return e;
}
