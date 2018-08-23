#include<stdio.h>
int main()
{
	int a[100]={0},i,m,x,k=0;
	printf("请输入十进制数:");
	scanf("%d",&x);
	for(i=0;;i++)
	{
		if(x!=0)
		{
			a[i]=x%2;
			x=x/2;
			k++;
		//	printf("%d",k);
		}
		else
		{
			break;
		}
	}
/*	for(i=0;i<k/2;i++)
	{
		m=a[i];
		a[i]=a[k-i-1];
		a[k-i-1]=m;
	}*/
	for(i=k-1;i>=0;i--)
	{
		printf("%d",a[i]);
	}
	return 0;
}

