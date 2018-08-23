#include<stdio.h>

long cifang(long a,long b)
{
	long b1, a1;
	a1 = a;
	for(b1 = 0;b1 < b - 1;b1++)
	{
		a *= a1;
	}
	return a;

}
int main()
{
	long a, b, c;
	printf("请输入一个数\n");
	scanf("%d",&a);
	printf("请输入它的多少次方\n");
	scanf("%d",&b);
	c = cifang(a,b);
	c = c % 1000;
	printf("%d\n",c);


}
