#include<stdio.h>
#define R 5
#define C 5
void input (int arr[][C]);
void output(int arr[][C]);
int main()
{	
	int i,j;
	int arr[R][C]={};
	int min;
	int max;
	input(arr);
	output(arr);
			min=arr[0][0];
			  max=arr[1][0];
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			if(i-j<=0)
			{
			
			 if(arr[i][j]<min)
       			  min=arr[i][j];

			}
			else 
                       {  
			 
			if(arr[i][j]>max)
			  max=arr[i][j];
			}
		}
	}
		printf("min:%d\n",min);
		printf("max:%d\n",max);

	return 0;
}
void input (int arr[][C])
{
	int i,j;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			scanf("%d",&arr[i][j]);
		}
		printf("\n");
	}
}
void output (int arr[][C])
{
	int i,j;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			printf("%3d",arr[i][j]);
		}
		printf("\n");
	}
}
