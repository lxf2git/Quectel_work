#include<stdio.h>
#include<stdlib.h>

void creat_memory(void **p,int size);
void input(int **p,int x, int y);
int min(int **p, int x, int y, int m ,int n);
void i_free(void **p);
void judge(int **p, int x, int y);

int main()
{
	int **p=NULL;
	int r, c, i;
	int Min;
	printf("please input row col\n");
	scanf("%d%d",&r, &c);
	creat_memory((void **)&p,r*sizeof(int *));
	for(i=0;i<r;i++)
	{
		creat_memory((void **)p+i,c*sizeof(int));
	}
	input(p,r,c);
	min(p,r,c,0,0);
	judge(p,r,c);
	//printf("%d",p[0][0]);
	Min=min(p,r,c,0,0);
	printf("第二小：%d\n",Min);
	for(i=0;i<r;i++)
	{
		i_free((void **)p+i);
	}
	i_free((void **)&p);
	return 0;
}

void creat_memory(void **p,int size)
{
	*p=malloc(size);
	if(*p==NULL)
	{
		printf("malloc error");
		exit(-1);
	}
}

void input(int **p,int x, int y)
{
	printf("请输入一个%d行%d列的数组\n", x, y);
	int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			scanf("%d",&p[i][j]);
		}
	}
}

int min(int **p, int x, int y, int m ,int n)
{
	int i,j,t;
	for(i=m;i<x;i++)
	{
		for(j=n;j<y;j++)
		{
			if((p[m][n])>p[i][j])
			{
				t=p[m][n];
				p[m][n]=p[i][j];
				p[i][j]=t;
			}
		}
	}
	return p[m][n];
}

void i_free(void **p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}

void judge(int **p, int x, int y)
{
	if(y>1)
	{
		p[0][0]=p[0][1];
	}
	else
	{
		if(x==1)
		{
			;
		}
		else
		{
			p[0][0]=p[1][0];
		}
	}
	//printf("%d",p[0][0]);
}
