#include<stdio.h>
#include<stdlib.h>

void creat_memory(void **p,int size);
void input(int *p,int x);
void output(int *p,int x);
void quick_sort(int *p,int low,int high);
int sort(int *p,int low,int high);

int main()
{
	int *p=NULL;
	int n;
	printf("please input a lenge of the arr\n");
	scanf("%d",&n);
	creat_memory((void **)&p,n*sizeof(int));
	input(p,n);
	quick_sort(p,0,n-1);
	//sort(p,0,n-1);
	output(p,n);
}

void creat_memory(void **p,int size)
{
	*p=malloc(size);
	if(*p==NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void input(int *p,int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		printf("please input a data:\n");
		scanf("%d",&p[i]);
	}
}

void output(int *p,int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		printf("%d ",p[i]);
	}
	printf("\n");
}

void quick_sort(int *p,int low,int high)
{
	int ret=sort(p,low,high);
	if(ret+1<high)
	{
		quick_sort(p,ret+1,high);
	}
	if(ret-1>low)
	{
		quick_sort(p,low,ret-1);
	}
}

int sort(int *p,int low,int high)
{
	int flag=p[low];
	int t;
	while(low!=high)
	{
		while(high!=low)
		{	
			if(flag>p[high])
			{
				//printf("%d ",p[high]);
				//printf(" %d<-->%d ",p[low],p[high]);
				t=p[low];
				p[low]=p[high];
				p[high]=t;
				low++;
				break;
			}
			high--;
		}
		if(low==high)
		{
			break;
		}
		while(low!=high)
		{
			if(flag<p[low])
			{
				//printf("%d<-->%d",p[low],p[high]);
				//printf("%d ",p[low]);
				t=p[high];
				p[high]=p[low];
				p[low]=t;
				high--;
				break;
			}
			low++;
		}
	}
	//printf("%d",low);
	return low;
}
