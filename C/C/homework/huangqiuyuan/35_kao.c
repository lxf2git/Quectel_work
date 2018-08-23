#include<stdio.h>
int main()
{
	int a[100]={},i,x;
	printf("输入一个长整数");
	scanf("%d",&x);
		for(i=0;;i++)
		{
			a[i]=x%2;
			x=x/2;
			if(x==0)
			break;
		}
			for(;i>=0;i--)
				printf("%d",a[i]);
	//	puts(a);

	return 0;
}
