#include<stdio.h>
int main()
{
int i,j,m,n,k=0,max,a[4][4];
 printf("输入几阶方阵:");
 scanf("%d",&n);
 printf("输入阶矩阵的元素:");
 for(i=0;i<n;i++)
 {
 	for(j=0;j<n;j++)
	{
		scanf("%d",&a[i][j]);
	}
 }
 for(i=0;i<n;i++)
 {
	max=a[i][0];
 	for(j=0;j<n;j++)
	{
		if(a[i][0]<a[i][j])
		{
			max=a[i][j];
		}
	}	        
			if(k<1)
			{
				m=max;
				++k;
			}
			printf("各行最大值:%d\n",max);
			if(m>max)
			{
				m=max;
			}
 }
 printf("最小值:%d\n",m);
return 0;
}
