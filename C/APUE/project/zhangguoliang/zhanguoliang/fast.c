#include<stdio.h>

void swap(int *a,int b,int c)
{
	int i;
	i=a[b];
	a[b]=a[c];
	a[c]=i;
}

int sort(int *parr,int low,int high)
{
	int f=low;
	int i=0;
	while(1)
	{
		if(high==low)
		{
			return f;
		}
		if(i==0)
		{
			if(parr[f]>parr[high])
			{
				swap(parr,f,high);
				low++;
				f=high;
				i=1;
			}
			else
			{
				high--;
				i=0;
			}
		}
		else
		{
			if(parr[f]<parr[low])
			{
				swap(parr,f,low);
				f=low;
				high--;
				i=0;
			}
			else
			{
				low++;
				i=1;
			}
		}
	}
//	return low;
}


void quick_sort(int *parr,int low,int high)
{
	int ret;
	ret=sort(parr,low,high);//交换 比较.....
	printf("ret:%d / ",ret);
	if(ret+1<high)
	{
		quick_sort(parr,ret+1,high);//右侧
	}
	if(low<ret-1)
	{
		quick_sort(parr,low,ret-1);//左侧
	}
}

void out_put(int *parr)
{
	int i;
	for(i=0;i<8;i++)
	{
		printf("%d ",parr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[]={12,3,15,59,47,11,17,20};
	quick_sort(arr,0,7);
	out_put(arr);
	return 0;
}
