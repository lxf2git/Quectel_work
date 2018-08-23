#include<stdio.h>
#include<stdlib.h>
int main()
{
	int **p=NULL;
	int i,col,row;
	printf("输入行 列\n");
	scanf("%d %d",&row,&col);
	p=(int **)malloc(row*sizeof(int *));
	for(i=0;i<col;i++)
	{
		*(p+i)=(int *)malloc(col*sizeof(int));
	}
	comp((int **)&p,row,col);
	return 0;
}

int comp(int **q,int r,int c)
{
	q=(int **)*q;
	int i,j,max,min;
	if(q==NULL)
	{
		printf("q:error\n");
	}
	printf("输入数字:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",*(q+i)+j);
			if(*(*(q+0)+0)>*(*(q+i)+j))
			{	*(*(q+0)+0)=*(*(q+i)+j);
			}
			max=max<*(*(q+i)+j)?*(*(q+i)+j):max;
		}
	}
	*(*(q+0)+0)=max;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(*(*(q+0)+1)>*(*(q+i)+j))
					*(*(q+0)+1)=*(*(q+i)+j);
			min=*(*(q+0)+1);
		}
	}
	printf("%d\n",min);
}
