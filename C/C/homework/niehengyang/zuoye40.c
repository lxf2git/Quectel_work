#include<stdio.h>
#include<stdlib.h>
int find(int **p,int r,int c);
int main()
{
	int i,j,r,c;
	int **p=NULL;
	int min;
	printf("please input column:");
	scanf("%d",&r);
	p=(int **)malloc(r*sizeof(int *));
	printf("please input row:");
	scanf("%d",&c);
	for(i=0;i<r;i++)
	{
	*(p+i)=(int *)malloc(c*sizeof(int));
	}
	printf("please input number:");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",*(p+i)+j);

		}

	}
	min=find(p,r,c);
	printf("the second small number of:%d \n",min);


}

int find(int **p,int r,int c)
{
	int i,j;
	int t=**p;
	int a[10];
	int min,n;
	for(n=0;n<=1;n++)
	{
	for(i=0;i<r;i++)
	{	
		for(j=0;j<c;j++)
		{
		if(i==0&&j==0&&p[0][0]==0)
		{
			t=p[0][1];
			}
			else
			if(t>p[i][j])	
			{
			t=p[i][j];
			p[i][j]=p[0][0];
			p[0][0]=t;
			min=t;
			}
			
		}
	}	
		p[0][0]=0;
	}
		return min;

}
