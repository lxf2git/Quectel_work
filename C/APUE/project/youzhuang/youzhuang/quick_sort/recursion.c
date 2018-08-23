#include<stdio.h>
#define N 10
int sort(int arr[N],int low,int high);
void quick_sort(int arr[N],int low,int high);

int main()
{
		int i;
		int arr[N]={8,11,8,9,14,2,4,3,8,4};
		quick_sort(arr,0,N-1);
		printf("\n");
		for(i=0;i<N;i++)
		{
				printf("%d ",arr[i]);
		}
		printf("\n");
		return 0;
}

void quick_sort(int arr[N],int low,int high)
{
		int ret;
		ret=sort(arr,low,high);
		if(ret+1<high)
		{
				quick_sort(arr,ret+1,high);
		}
		if(ret-1>low)
		{
				quick_sort(arr,low,ret-1);
		}
}

int sort(int arr[N],int low,int high)
{
		int temp;
		int flag=low;
		while(low!=high)
		{
				if(flag==low)
				{
						if(arr[flag]>arr[high])
						{
								temp=arr[flag];
								arr[flag]=arr[high];
								arr[high]=temp;
								flag=high;
								low++;
						}
						else
						{
								high--;
						}
				}
				else
				{
						if(arr[flag]<arr[low])
						{
								temp=arr[flag];
								arr[flag]=arr[low];
								arr[low]=temp;
								flag=low;
								high--;
						}
						else
						{
								low++;
						}
				}
		}
		return low;
}
