#include<stdio.h>
#define n 5
int main()
{	
	int i,j,a[n][n];
			printf("输入几阶方阵:\n");
		//	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i<=j)
			{
				printf("1 ");
				if(j==n-1)
				{
					printf("\n");

				}


			}
			else
			{
				printf("%d ",i-j+1);

			}

		}


	}




	return 0;


}

