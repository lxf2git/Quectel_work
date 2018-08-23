#include<stdio.h>
#include<stdlib.h>

void swap(int *parr,int x,int y)
{
	int tmp;
	tmp = parr[x];
	parr[x] = parr[y];
	parr[y] = tmp;
}

int sort(int *parr,int low,int high)
{
	int flag = parr[low];
	while(low<high)
	{
		while(flag<parr[high]&&low<high)
		{
			high--;
		}
		swap(parr,low,high);
		if(low<high)
		{
			low++;
		}
		while(flag>parr[low]&&low<high)
		{
			low++;
		}
		swap(parr,low,high);
		if(low<high)
		{
			high--;
		}
	}

	return low;
}

void quick_sort(int *parr,int low,int high)
{
	int ret;
  	ret = sort(parr,low,high);//交换 比较.....

	if(ret+1<high)
	{		
		quick_sort(parr,ret+1,high);//右侧
	}
	if(low<ret-1)
	{
		quick_sort(parr,low,ret-1);//左侧
	}
}
void in_put(int *parr,int n)
{
	int i;
	printf("input data:\n");
	for(i=0;i<n;i++)
	{	
		scanf("%d",parr+i);
	}
	
}

void out_put(int *parr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{	
		printf("%d ",parr[i]);
	}
	printf("\n");
}
int main()
{
	int num,i;
	int *p;
	printf("input the num of data:\n");
	scanf("%d",&num);	
	p = (int *)malloc(num*sizeof(int));
	if(NULL==p)
	{
		printf("malloc error");
		exit(-1);
	}

	in_put(p,num);
	quick_sort(p,0,num-1);
	out_put(p,num);	
	if(p!=NULL)
	{
		free(p);
		p = NULL;
	}
	return 0;

}
