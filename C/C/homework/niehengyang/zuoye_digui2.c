#include<stdio.h>
#include<stdlib.h>

void get_chain(int *p,int num)
{
	int i;
	printf("please input the chain:\n");
	for(i=0;i<num;i++)
	{
		scanf("%d",&p[i]);
	}
}


void swap(int *p, int l, int r)
{
	int tmp;
	tmp=p[r];
	p[r]=p[l];
	p[l]=tmp;
}

int sort(int *p,int l,int r)
{
	int flag=p[l];
	while(l<r)
	{
		while(flag<p[r]&&l<r)
		{
			r--;
		}
		swap(p,l,r);
		if(l<r)
		{
		l++;
		}
		while(flag>p[l]&&l<r)
		{
			l++;
		}
		swap(p,l,r);
		if(l<r)
		{
		r--;
		}
	}
	return l;
}

void digui_sort(int *p, int l, int r)
{
	int tmp;
	tmp=sort(p,l,r);
	if(tmp+1<r)
	{
	digui_sort(p,tmp+1,r);
	}
	if(tmp-1>l)
	{
	digui_sort(p,l,tmp-1);
	}
}

void output_chain(int *p, int num)
{
	int i;
	for(i=0;i<num;i++)
	{
		printf(" %d ",p[i]);	
	}
	printf("\n");
}

int main()
{
	int *p;
	int num;
	printf("please input chain's num:\n");
	scanf("%d",&num);
	p=(int *)malloc(sizeof(int)*num);
	if(p==NULL)
	{
		printf("create error\n");	
		exit(-1);
	}
	get_chain(p,num);
	digui_sort(p,0,num-1);
	output_chain(p,num);
}
