#include<stdio.h>
int main()
{
	int a[100];
	int i,j=0,m=0,n=0,sum=0;
	printf("输入整数:\n");
	for(i=0;;i++)
	{
		scanf("%d",&a[i]);
		j++;
		if(a[i]==0)
				break;
	}
	for(i=0;i<j;i++)
	{
		if(a[i]%2==0&&a[i]!=0)
		{
			m++;
			sum+=a[i];
		}
	}
	printf("偶数个数为%d个,平均值为%d\n",m,sum/m);
	sum=0;
	for(i=0;i<j;i++)
	{
		if(a[i]%2==1)
		{
			n++;
			sum+=a[i];
		}
	}
	printf("奇数个数为%d个,平均值为%d\n",n,sum/n);
	return 0;
}
