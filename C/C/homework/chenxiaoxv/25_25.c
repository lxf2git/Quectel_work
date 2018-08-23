#include<stdio.h>
#define R 500
#define C 500


void ca(int arr[][C],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)	
		{
			if(i<=j)
			{
				arr[i][j]=1;
				printf("%d ",arr[i][j]);		
			}
			else
			{
				arr[i][j]=i-j+1;
	 			printf("%d ",arr[i][j]);		
			}
		}
		printf("\n");
	}

}

int main()
{
	int n;
	int a[R][C];
	scanf("%d",&n);
	ca(a,n);
	

return 0;
}




