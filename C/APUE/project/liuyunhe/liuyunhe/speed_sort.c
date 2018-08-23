#include<stdio.h>
#define LOW 0
#define HIGH 7
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
		int arr[]={12,3,15,15,17,20,17,20};
		quick_sort(arr,LOW,HIGH);
		out_qut(arr,HIGH);
		return 0;
}
