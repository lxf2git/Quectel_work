#include<stdio.h>
#include<stdlib.h>

void creat_memory(int **pt,int size);
void area(int *m,int *n);
int compare(int m,int n,int **pt);
void input(int m,int n,int **pt);
int main()
{
	int m,n,i;
	int **p=NULL;
	area(&m,&n);
	creat_memory((int **)&p,m*sizeof(int *));
	for(i=0;i<m;i++)
	{
		creat_memory((int **)p+i,n*sizeof(int));
	}
	input(m,n,p);
	compare(m,n,p);

	return 0;
}
int compare(int m,int n,int **pt)
{
	int i,j;
	int min,smin;
	min=**pt;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(*(*(pt+i)+j)<=min)
			{
				min=*(*(pt+i)+j);
			}
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(*(*(pt+i)+j)>min)
			{
				smin=*(*(pt+i)+j);
				for(;i<m;i++)
				{
					for(;j<n;j++)
					{
						if(*(*(pt+i)+j)<=smin&&*(*(pt+i)+j)!=min)
						{
							smin=*(*(pt+i)+j);
						}
					}
				}
				printf("second min:%d\n",smin);
				return 0;
			}
		}
	}
	printf("have no second min\n");
	return 0;
}
void input(int m,int n,int **pt)
{
	int i,j;
	printf("input num:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",*(pt+i)+j);
		}
	}
	printf("num\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d",*(*(pt+i)+j));
		}
		printf("\n");
	}	
}

void area(int *m,int *n)
{
	printf("R:\n");
	scanf("%d",m);
	printf("C:\n");
	scanf("%d",n);
}

void creat_memory(int **pt,int size)
{
	*pt=(int *)malloc(size);
	if(pt==NULL)
	{
		printf("malloc error!\n");
		exit(-1);
	}
}
