#include<stdio.h>
#include<stdlib.h>
void create_memory(void **q,int size)
{
	*q = malloc(size);
	if(NULL==*q)
	{
		printf("malloc err");
		exit(-1);
	}
}

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
	create_memory((void **)&p,r*sizeof(int*));	
	if(NULL==p)
	{
		printf("p:malloc error");
		exit(-1);
	}
	for(i=0;i<r;i++)
	{
		create_memory((void **)p+i,c*sizeof(int));
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

	for(i=0;i<r;i++)
	{
		free(*(p+i));
	}
	free(p);

	return 0;

}
