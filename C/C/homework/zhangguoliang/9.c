#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d",&a);
	b=a;
	do
	{
		a=a+b/2;
		b=b/2+b%2;

	}while(b>1);

	printf("喝了%d瓶汽水\n",a);
	return 0;
}
