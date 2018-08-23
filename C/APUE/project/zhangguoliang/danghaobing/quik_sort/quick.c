#include"quick.h"

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
					return high;
				if(flag>parr[high])
				{
						swap(parr,blag,high);
						blag=high;
						low++;
						break;
				}
				else
				{
						high--;
				}
				
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
				{
						low++;
				}
		}
					
	}
}

void quick_sort(int *parr,int low,int high)
{
		int ret = sort(parr,low,high);//交换 比较。。。
	//	printf("ret:%d \n",ret);
		if(ret+1<high)
		{
			quick_sort(parr,ret+1,high);//右侧

		}

		if(low<ret-1)
		{
			quick_sort(parr,low,ret-1);//左侧
		}
		
}

void out_put(int *arr,int x)
{
		int i;
		for(i=0;i<=x;i++)
		{
			printf("%d ",arr[i]);
		}
		printf("\n");
}

int main()
{
		int arr[]={12,3,15,59,47,11,17,20};
		quick_sort(arr,0,7);
		out_put(arr,7);
		return 0;
}
