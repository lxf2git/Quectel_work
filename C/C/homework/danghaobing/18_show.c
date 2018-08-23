#include<stdio.h>
int main()
{
		int a[10];
		int i,max=0,min=0,flag,blag,j;
		for(i=0;i<10;i++)
		{
				printf("请输入第%d个数: ",i+1);
				scanf("%d",&a[i]);
				if(max<a[i])
				{
						max=a[i];
						flag=i;
				}
		}
		a[flag]=a[9];
		a[9]=max;		
		min=a[0];
		for(j=0;j<10;j++)
		{
			if(min>a[j])
			{
				min=a[j];
				blag=j;
			}
				}
		a[blag]=a[0];
		a[0]=min;
		printf("去掉一个最大值：%d\n",a[9]);
		printf("去掉一个最小值：%d\n",a[0]);
		printf("平均值是：%d\n",(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8])/8);
}
