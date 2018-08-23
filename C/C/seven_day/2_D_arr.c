#include<stdio.h>
	void print(int arr[],int n)
	{
	    int i;
	    for(i=0;i<n;i++)
	    {   
		printf("%d ",arr[i]);
	    }   
	    printf("\n");

	}

int main()
{
	int i,j;	
	int a[3][5]={
		{1,2,3},
		{4,5},
		{6,7,8,9,10}
	};	

	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d  ",a[i][j]);
		}
		printf("\n");
	}
	
	puts("===================================");
	
	print(a[0],5);
	print(a[1],5);
	print(a[2],5);


	return 0;

}
