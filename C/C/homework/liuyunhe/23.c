#include<stdio.h>

int main()
{
		int i,j,n,m;
		int series[10]={1,2,3,4,5,6,7,8,9,10};
		printf("重第几个数开始\n");
		scanf("%d",&n);
		printf("逆转几个数\n");
		scanf("%d",&m);
		i=n-1;
		j=m-1;
		int a[j];
		for(i;i<(n+m-1);i++)
		{
				a[j]=series[i];
				j--;
				
		}
		j=0;
		for(i=n-1;i<(n+m-1);i++)
		{
			
				if(j<m)
				{
						series[i]=a[j];
						j++;
				}
		}
		for(i=0;i<10;i++)
		printf("%d",series[i]);
		return 0;
}
