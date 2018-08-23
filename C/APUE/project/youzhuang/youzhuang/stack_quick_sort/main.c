#include"main.h"
int main()
{
		int arr[N]={12,3,5,9,11,27,23,45,7,10};
		quick_sort(arr,0,N-1);
		output(arr);
		return 0;
}

void output(int arr[N])
{
		int i;
		for(i=0;i<N;i++)
		{
				printf("%d ",arr[i]);
		}
		printf("\n");
}
void quick_sort(int arr[N],int low,int high)
{
		pSta stack=NULL;
		init_stack(&stack);
		int ret;
		push(stack,arr,low,high);
		while(stack_empty(stack)!=EMPTY)
		{
				pop(stack,arr,&low,&high);

				int i;
				for(i=0;i<N;i++)
				{
						printf("%d ",arr[i]);
				}
				printf("\n");

				ret=sort(arr,low,high);
				if(ret+1<high)
				{
						push(stack,arr,ret+1,high);
				}
				if(low<ret-1)
				{
						push(stack,arr,low,ret-1);
				}
		}
}

int sort(int arr[N],int low,int high)
{
		int flag=arr[low];
		while(low<high)
		{
				while(flag<arr[high]&&low<high)
				{
						high--;
				}
				swap(arr,low,high);
				if(low<high)
				{
						low++;
				}
				while(flag>arr[low]&&low<high)
				{
						low++;
				}
				swap(arr,low,high);
				if(low<high)
				{
						high--;
				}
		}
		return low;
}

void swap(int arr[],int low,int high)
{
		int temp;
		temp=arr[low];
		arr[low]=arr[high];
		arr[high]=temp;
}
