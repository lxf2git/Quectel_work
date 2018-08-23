#include<stdio.h>
#include<stdlib.h>

int main()
{
	/*	
	int *p;
	p = (int *)malloc(sizeof(int));
	*/
	int **p=NULL;
	int r,c,i,j;
	printf("please input row col:\n");
	scanf("%d%d",&r,&c);
	p = (int **)malloc(r*sizeof(int*));	
	if(NULL==p)
	{
		printf("p:malloc error");
		exit(-1);
	}
	for(i=0;i<r;i++)
	{
		*(p+i) = (int *)malloc(c*sizeof(int));
		if(NULL==*(p+i))
		{
			printf("p+i:malloc error");
			exit(-1);
		}
	}	

	puts("please input data:");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",*(p+i)+j);//&p[i][j]
		}
	}

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d",*(*(p+i)+j));//p[i][j]
		}
		printf("\n");
	}
	return 0;
	return 0;

}
