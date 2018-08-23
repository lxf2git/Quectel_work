#include<stdio.h>

void input(int arr[][3],int row,int col)
{
	int i,j;
	printf("please input:\n");	
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&arr[i][j]);
		}
		printf("\n");
	}
	
}

void output(int arr[][3],int row,int col)
{
	int i,j;	
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("arr[%d][%d]:%d  ",i,j,arr[i][j]);
		}
		printf("\n");
	}
	
}

int find_max(int arr[][3],int row,int col)
{
	int i,j;	
	int max=arr[0][0];
	for(i=0;i<row;i++)
	{
		for(j=1;j<col;j++)
		{
			if(arr[i][j]>max)
			{
				max = arr[i][j];
			}
		}
	}

	return max;
}

int main()
{
	int i,j;
	int a1[2][3];
	int a2[3][3];
	input(a1,2,3);
	input(a2,3,3);
	output(a1,2,3);
	output(a2,3,3);
	printf("div:%d\n",(find_max(a2,3,3)-find_max(a1,2,3)));

	
	return 0;


}

