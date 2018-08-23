#include<stdio.h>
int  aa(int a)
{
	printf("请输入一个2位数：");
	scanf("%d",&a);
	return a;
}

int main()
{
	int a=0,b=0,m=1,n=1,t=1;
	a = aa(a);
	b=aa(b);
	if((a<10) || (a>99))
	{
		printf("error!\n");
		a = aa(a);
	}
	if((b<10) || (b>99))
	{
		printf("error!\n");
		b = aa(b);
	}
	m=a%10;
	n=a/10;
	t=n*100+m;
	m=b%10;
	n=b/10;
	t=t+m*10+n*1000;
	printf("t=%d\n",t);

	return 0;

}


