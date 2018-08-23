#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,max;
	int m,n;
	int **p=NULL;
	printf("hang\n");
	scanf("%d",&m);
	printf("lie\n");
	scanf("%d",&n);
	p=(int **)malloc(m*sizeof(int *));
	for(i=0;i<m;i++)
	{
		*(p+i)=(int *)malloc(n*sizeof(int));
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",*(p+i)+j);
		}
	}
	max=**p;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(*(*(p+i)+j)>=max)
			{
				max=*(*(p+i)+j);
			}
		}
	}
	printf("max:%d",max);
	return 0;
}


