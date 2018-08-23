#include<stdio.h>
#include<stdlib.h>

void compare(int m,int n,int **pt);
void input(int m,int n,int **pt);
void creat_memory(int **pt,int size);
void area(int *r,int *c);
int main()
{
	int m,n,i;
	int **p;
	area(&m,&n);
	creat_memory((int **)&p,m*sizeof(int *));
	for(i=0;i<m;i++)
	{
		creat_memory((int **)&*(p+i),n*sizeof(int));
	}
	input(m,n,p);
	compare(m,n,p);
	return 0;
}

void area(int *r,int *c)
{
	printf("hang:\n");
	scanf("%d",r);
	printf("lie:\n");
	scanf("%d",c);
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
	printf("num:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%4d",*(*(pt+i)+j));
		}
		printf("\n");
	}
}
void compare(int m,int n,int **pt)
{
	int i,j,max;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(*(*(pt+i)+j)>=max)
			{
				max=*(*(pt+i)+j);
			}
		}
	}
	printf("max:%d\n",max);
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
