#include<stdio.h>
void swap(int *flag,int *tmpd)
{
		int	tmp;
		tmp = *flag;
		*flag = *tmpd;
		*tmpd = tmp;
}
int sort(int *parr,int low,int high)
{
		int *p = &parr[low];
		int flag;
		int a = 0;
		flag = parr[low];
		while(low!=high)
		{
				if(a==0)
				{
						
						if(flag>parr[high])
						{
								swap(p,&parr[high]);
								p = &parr[high];
								low++;
								a = 1;
						}
						else
					//	if(flag<parr[high])
						{
								high--;
						}
				}
				else
				{
						if(flag<parr[low])
						{
								swap(p,&parr[low]);
								p = &parr[low];
								high--;
								a = 0;
						}
				//		if(flag>parr[low])
						else
						{
						low++;
						}
				}
		}
	  	return high;
}
void quick_sort(int *parr,int low,int high)
{
		int ret;
		ret = sort(parr,low,high);
		if(ret+1<high)
		{
				quick_sort(parr,ret+1,high);
		}
		if(low<ret-1)
		{
			quick_sort(parr,low,ret-1);
		}
}
int main()
{
		int i;
		int arr[] = {12,3,5,12,43,11};
		quick_sort(arr,0,5);
		for(i=0;i<6;i++)
				printf("%d ",arr[i]);
		return 0;
}
