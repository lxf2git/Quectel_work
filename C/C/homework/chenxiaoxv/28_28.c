#include<stdio.h>
#define N 3

void fan(int arr[][N])

{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
}
int max(int arr[][N],int m[N])
{
	int i,j;
	for(i=0;i<N;i++)
	{	
		int z=arr[i][i];
		for(j=0;j<N;j++)
		{	
			if(z<arr[i][j])
			z=arr[i][j];
	
		}
		 m[i]=z;

	}

}
int main()
{
	int a[N][N],m[N],i,min;
	printf("inputNxN");
	fan(a);
	max(a,m);

for(i=0;i<N;i++)
{
	if(min>m[i])
	min=m[i];
}
printf("%d\n",min);


return 0;
}





