#include<stdio.h>
int main()
{
		int a[5];
		int i,max=0,min=0,flag=0,blag=0,j;
		for(i=0;i<5;i++)
		{
				printf("请输入第%d个数: ",i+1);
				scanf("%d",&a[i]);
				if(max<a[i])
				{
						max=a[i];
						flag=i;
				}
		}
				
		a[flag]=a[4];
		a[4]=max;
				
				min=a[0];
				for(j=0;j<5;j++)
				{
						if(min>a[j])
					{
						min=a[j];
						blag=j;
					}
				}
		a[blag]=a[0];
		a[0]=min;
		
		printf("%d %d %d %d %d\n",a[0],a[1],a[2],a[3],a[4]);
}
