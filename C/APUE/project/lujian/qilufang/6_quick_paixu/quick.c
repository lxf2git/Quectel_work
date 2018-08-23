#include<stdio.h>
#include<stdlib.h>
int sort(int *parr,int low,int high)
{
	int flag=parr[low];
	int loca=low;
	while(low!=high)
	{
			if(flag==parr[high]&&loca!=high&&low!=high)
			{
					high--;
			}
			if(flag==parr[low]&&loca!=low&&low!=high)
			{
					low++;
			}
		if(flag<parr[high])
		{
			high--;
		}
		if(flag>parr[high])
		{
			parr[loca]=parr[high];
			parr[high]=flag;
			loca=high;
			low++;
		}
		if(flag>parr[low])
		{
			low++;
		}
		if(parr[low]>flag)
		{
			parr[loca]=parr[low];
			parr[low]=flag;
			loca=low;
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
void out_put(int *arr,int nb)
{	
	int i;
	for(i=0;i<nb;i++)
	{
		printf("arr[%d]:%d\n",i,arr[i]);
	}
}
int main()
{
		int	arr[8]={12,3,15,17,47,11,17,20};
		quick_sort(arr,0,8);
		out_put(arr,8);	
		return 0;

}

