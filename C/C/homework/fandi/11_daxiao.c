#include<stdio.h>


int main()
{
	int max(int x,int y);
	int min(int x,int y);
	int a,b,c,d,e,cha;
	scanf("%d,%d,%d",&a,&b,&c);
	d=max(a,b);
	e=max(d,c);
	printf("最大值为:%d\n",e);
	a=min(a,b);
	d=min(a,c);
	printf("最小值为:%d\n",d);
	cha=e-d;
	printf("最大值与最小值的差为:%d\n",cha);
	return 0;
}

int max(int x,int y)
{
	int z;
	z=x>y?x:y;
	return z;
}

int min(int x,int y)
{
	int z;
	z=x<y?x:y;
	return z;
}
