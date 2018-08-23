#include<stdio.h>
#define N 5
#include<stdlib.h>

int main()
{
	int a[N];
	int x;
	int i,j;

	printf("input arr:\n");

	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	
	printf("input x :\n");
	scanf("%d",&x);

	for(j=0;j<N;j++)
	{
		if(x==a[j])
		{
			printf("flag :%d\n",j);
			exit(0);
		}
	}
	printf("sorry,not found!\n");


	return 0;
}
