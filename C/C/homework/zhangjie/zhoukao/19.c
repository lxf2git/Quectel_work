#include<stdio.h>

int main()
{
	int i,m=0,n=0,h=0,s=0;
	int a[100];
	for(i=0;;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]%2==0&&a[i]!=0)
		{
			m++;
			h=h+a[i];
		}
		if(a[i]%2==1)
		{
			n++;
			s=s+a[i];
		}
		if(a[i]==0)
		{
			break;
		}
	}
	printf("偶数个数%d,平均值%d\n",m,h/m);
	printf("奇数个数%d,平均值%d\n",n,s/n);
	return 0;
}
