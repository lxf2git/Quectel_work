#include"quick.h"

void input(int *p)
{
	printf("please input %d data\n",SIZE);
	int i;
	for(i=0;i<SIZE;i++)
	{
		scanf("%d",&p[i]);
	}
}

void quick_sort(int *p,pSta ps)
{
	int ret=0;
	int low=0,high=SIZE-1;
	push(ps,low,high);
	while(pop(ps,&low,&high)!=EMPTY)
	{
		//printf("%d %d",ret+1,high);
		if(ret+1<high)
		{
		//	printf("%d ",ret);
			ret=sort(p,low,high);
			//printf("%d ");
			push(ps,ret+1,high);
		}
		if(low<ret-1)
		{
			ret=sort(p,low,high);
			push(ps,low,high);
		}
	}
}

void swap(int *p,int x,int y)
{
	int tmp;
	tmp=p[x];
	p[x]=p[y];
	p[y]=tmp;
}

void output(int *p)
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		printf("%d ",p[i]);
	}
	printf("\n");
}

int sort(int *p,int low,int high)
{
	int flag=p[low];
	while(low<high)
	{
		while(low<high&&flag<p[high])
		{
			high--;
		}
		swap(p,low,high);
		if(high<low)
		{
			low++;
		}
		while(low<high&&flag>p[low])
		{
			low++;
		}
		swap(p,low,high);
		if(high<low)
		{
			high--;
		}
	}
	return low;
}
