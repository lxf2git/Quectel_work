#include<stdio.h>

int main()
{
		int a[10]={1,2,3,4,5,6,7,8,9,10};
		int x,n,i,k,m;
		printf("请输入指定位置x：\n");
		scanf("%d",&x);
		printf("请输入n个换位置的数：\n");
		scanf("%d",&n);
		k=x+n-2;
		for(i=x-1;i<x-1+n/2;i++)
		{
				m=a[x-1];
				a[x-1]=a[k];
				a[k]=m;
				k--;		
		}
		for(i=0;i<10;i++)
		{
			printf("%d",a[i]);
		}


		return 0;
}
