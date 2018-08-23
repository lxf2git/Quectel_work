#include<stdio.h>
int main()
{
	int a[100];
	int x,i,m,j=0;
	printf("输入数字x:\n");
	scanf("%d",&x);
	for(i=0;;i++)
	{
		a[i]=x%2;
		x=x/2;
		j++;
		if(x==0)
			break;
	}
	printf("二进制为:\n");
	for(i=j-1;i>=0;i--)
	{
		printf("%d",a[i]);
	}
	printf("\n");
	return 0;
}

