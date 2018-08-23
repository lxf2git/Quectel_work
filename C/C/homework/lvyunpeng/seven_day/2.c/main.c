#include<stdio.h>
int main()
{
	int i,j,a[5][5]={0},n,m;
	printf("请输入:\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5j++)
		{
			scanf("%d",&a[i][j]);
			printf("a[%d][%d]:%d\n",i,j,a[i][j]);
			if(i<=j)
			{
				if(a[0][0]>a[i][j])
				{
					a[0][0]=a[i][j];
					n=a[0][0];
				}
			}
			if(i>j)
			{
				if(a[0][0]<a[i][j])
				{
					a[0][0]=a[i][j];
					m=a[0][0];
				}
			}
			if(j==4)
			{
				printf("\n");
			}
		}


	}
			printf("min:%d,max:%d\n",n,m);

		return 0;
}

