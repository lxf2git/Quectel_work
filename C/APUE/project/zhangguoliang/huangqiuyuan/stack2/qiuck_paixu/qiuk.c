#include<stdio.h>

void swap(int *parr,int blag,int high)
{
	int s=parr[blag];
	parr[blag]=parr[high];
	parr[high]=s;
}
int sort(int *parr,int low,int high)
{
	int flag=parr[low];
	int blag=low;
	while(1)
	{
		while(1)
		{
			if(low==high)
				return low;
				if(flag>parr[high])
				{
					swap(parr,blag,high);
					blag=high;
					low++;
					break;
				}	
				else
					high--;		
		}
		while(1)
		{
			if(low==high)
				return low;
				if(flag<parr[low])
				{
					swap(parr,blag,low);
					blag=low;
					high--;
					break;
				}
				else
					low++;
		}
	}
	
	
}
void qiuck_sort(int *parr,int low, int high)
{
	int ret;
	ret=sort(parr,low,high);//交换  比较

	if(ret+1<high)
	{
		qiuck_sort(parr,ret+1,high);//右侧
	}
	if(low<ret-1)
	{
		qiuck_sort(parr,low,ret-1);//左侧
	}
}
void out_put(int *arr,int x)
{
	int i;
	for(i=0;i<x;i++)
		{
			printf("%d ",arr[i]);
		}
			printf("\n");
}
int main()
{
	int arr[]={12,3,23,2,23,4,578,8,78,4};
	qiuck_sort(arr,0,10);
	out_put(arr,10);

	return 0;
}
