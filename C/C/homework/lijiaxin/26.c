#include<stdio.h>
#define N 5
void input(int arr1[][N])
{
		int i,j;
		for(i=0;i<N;i++)
		{
				for(j=0;j<N;j++)
				{
						scanf("%d",*(arr1+i)+j);
				}
		}
}
int main()
{
		int i,j;
		int arr[N][N]={0};
	   	input(arr);
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
			{
					if(i<=j)
					{
							if(arr[0][0]>arr[i][j])
									arr[0][0]=arr[i][j];
					}
					else
					{
							if(arr[1][0]<arr[i][j])
									arr[1][0]=arr[i][j];
					}
			}	
		printf("右上三角最小值为:%d 左下三角最大值为:%d\n",arr[0][0],arr[1][0]);
}
