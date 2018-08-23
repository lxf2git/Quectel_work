#include<stdio.h>

int main()
{
	int x,i,j;
	int a[100];
	j=0;
	printf("请输入一个10进制的数\n");
	scanf("%d",&x);
	for(i=0;i<100;i++)
	{
		a[i]=x%2;
		x=x/2;
		j=i;
		if(x==0)
				break;
	}
	for(i=j;i>-1;i--)
	{
		printf("%d",a[i]);
	}
	printf("\n");

	return 0;
}
