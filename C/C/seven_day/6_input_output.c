#include<stdio.h>
#define R 2
#define C 3

void input(char arr[][C])
{
	printf("size:%d\n",sizeof(arr));	//4 
	int i,j;
	printf("please input:\n");	
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			scanf("%d",&arr[i][j]);
		}
		printf("\n");
	}
	
}

void output(int arr[][C])
{
	int i,j;	
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			printf("arr[%d][%d]:%d  ",i,j,arr[i][j]);
		}
		printf("\n");
	}
	
}

int main()
{
	int i,j;
	int a[R][C];	
	char string[2][3];
	//input(a);
	input(string);
	output(a);
	
	return 0;


}

