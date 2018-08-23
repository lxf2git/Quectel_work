#include<stdio.h>
int main()
{
	int n;
	int i,j;
	printf("请输入需要的矩阵大小：");
	scanf("%d",&n);
	int a[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j>=i)
			{
				a[i][j]=1;
			}
			else
			{
		//	scanf("%d",&a[i][j]);
			a[i][j]=i-j+1;	
			}
		}
	}
	
		
		for(i=0;i<n;i++)
		{	
			
			for(j=0;j<n;j++)
			{
				printf("%3d",a[i][j]);
			
			}
			printf("\n");
		}
}
