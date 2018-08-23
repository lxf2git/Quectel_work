#include<stdio.h>
#include<stdlib.h>

void compare(int **pp,int r,int c)
{	
	int i,j;
	int min=pp[0][0];
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			min = min<pp[i][j]?min:pp[i][j];
	printf("min=%d\n",min);
	for(i=0;i<r;i++)
		for(j=0;j<c-1;j++)
			if(pp[i][j]==min)
			{
				pp[i][j]=pp[i][j+1];
			}
	int min_two=pp[0][0];
	for(i=0;i<r;i++)
		for(j=0;j<c-1;j++)
			min_two = min_two<pp[i][j]?min_two:pp[i][j];
	printf("min_two=%d\n",min_two);		
	if(pp!=NULL)
	{
		free(pp);
		pp = NULL;
	}
}

void input(int **ptr,int r,int c)
{
	int i,j;
	printf("Please input arr：\n");
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		scanf("%d",&ptr[i][j]);
		compare(ptr,r,c);	
}

void create_memory(int r,int c)
{
	int **p;
	int i;
	p = (int  **)malloc(r*sizeof(int *));
	if(NULL==p)
	{
		printf("malloc error");
		exit(-1);
	}
	for(i=0;i<r;i++)
	{
		*(p+i) = (int *)malloc(c*sizeof(int));
		if(NULL==*(p+i))
		{
			printf("malloc error");
			exit(-1);
		}
	}
	input(p,r,c);
}

int main()
{
	int **p;
	int r,c;
	printf("Please input r,c:\n");
	scanf("%d,%d",&r,&c);
	create_memory(r,c);
	return 0;
}
