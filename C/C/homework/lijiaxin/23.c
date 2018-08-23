#include<stdio.h>

int main()
{
		int a[10]={0},exchange;
		int i,j,n,begin;
		printf("请输入十个整数:\n");
		for(i=0;i<10;i++)
		{
				scanf("%d",a+i);
		}
		for(i=0;i<10;i++)
				for(j=i;j<10;j++)
				{
						if(a[i]>a[j])
						{
								exchange = a[i];
								a[i] = a[j];
								a[j] = exchange;
						}
				}
		for(i=0;i<10;i++)
		{
				printf("%d ",a[i]);
		}
		
		printf("\n指定位置开始的n个数逆序输出:\n");
		scanf("%d%d",&begin,&n);
		for(i=begin-1;i<begin+n-1;i++)
				for(j=i;j<begin+n-1;j++)
				{
						if(a[i]<a[j])
						{
								exchange = a[i];
								a[i] = a[j];
								a[j] = exchange;

						}
				}
		for(i=0;i<10;i++)
		{
				printf("%d ",a[i]);

		}
		printf("\n");
		return 0;

}


