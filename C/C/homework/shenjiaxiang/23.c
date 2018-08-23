#include<stdio.h>

int main()
{
		int a[10]={1,2,3,4,5,6,7,8,9,10};
		int x,n,i,k,m;
		do
		{
			printf("请输入指定位置i：\n");
			scanf("%d",&i);
			printf("请输入逆续排列个数n：\n");
			scanf("%d",&n);
		}while((n>10-i+1)&&printf("输入出错\n"));
		x=n/2;
		n=i+n-1;
		for(i=i-1,n=n-1,k=1;k<=x;i++,n--,k++)
		{
				m=a[i];
				a[i]=a[n];
				a[n]=m;		
		}
		for(i=0;i<10;i++)
		{
			printf("%d ",a[i]);
		}


		return 0;
}
