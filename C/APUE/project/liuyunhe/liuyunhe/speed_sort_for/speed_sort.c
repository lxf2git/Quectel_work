#include<stdio.h>
#include"stack.h"
#define LOW 0
#define HIGH 7
void out_qut(int *parr,int high);
int sort(int *parr,int low,int high)
{
		int flag=parr[low];
		int loca=low;
		while(low!=high)
		{
#if 1
				if(flag==parr[high]&&loca!=high&&low!=high)
				{
						high--;
				}
				if(flag==parr[low]&&loca!=low&&low!=high)
				{
						low++;
				}

#endif
				if(flag<parr[high])
				{
						high--;
				}
				if(flag>parr[high])
				{
						parr[loca] = parr[high];
						parr[high]=flag;
						loca=high;
						low++;
				}

				if(parr[low]<flag)
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
		int ret=0;
		sStack sSch;
		init_stack(&sSch);
		ret = sort(parr,low,high);
		push(&sSch,ret,low,high);
		while(sSch.top!=0)
		{
				for(;ret+1<high;)
				{
						
						low=ret+1;
						ret = sort(parr,low,high);
						push(&sSch,ret,low,high);
				}
				pop(&sSch,&ret,&low,&high);
				if(low<ret-1)
				{
						high=(ret-1);
						ret=sort(parr,low,high);
						push(&sSch,ret,low,high);
				}
		}
		
		
}
void out_qut(int *parr,int high)
{
		int i=0;
		for(i;i<=high;i++)
		{
				printf("%4d",parr[i]);
		}
		printf("\n");
}
int main()
{
		int arr[]={12,3,15,59,47,11,17,20};
		quick_sort(arr,LOW,HIGH);
		out_qut(arr,HIGH);
		return 0;
}
