#include<stdio.h>
int friend = 0;

void out_put(int *parr);
void swap(int *a,int *b)
{
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
	friend++;
}
#if 0
int sort(int *parr,int low,int high)
{
	int flag,l,h;
	flag = low;
	while(low!=high)
	{
		while(parr[high]>parr[flag])
		{
			h--;
		}
		low++;
		swap(parr+flag,parr+high);
		flag = high;
		while(parr[low]<parr[flag])
		{
			l++;
		}
		high--;
		swap(parr+low,parr+flag);
		flag = low;
		out_put(parr);	
	}
	out_put(parr);	
	return l;		
}
#endif
#if 0
int sort(int *parr,int low,int high)
{
	int flag,i,j;
	flag = low;
	
	while(1)
	{
		while(parr[high]>parr[flag])
		{
			high--;
			if(high == low)break;
		}
		if(high == low)break;
		low++;
		if(high == low)break;
		while(parr[low]<parr[flag])
		{
			low++;
			if(high == low)break;
		}
		if(high == low)break;
	
		swap(parr+low,parr+high);
		out_put(parr);	
	}
	if(flag != low)
	{
		swap(parr+flag,parr+low);
	}
	out_put(parr);	
	return low;		
}
#endif
#if 1
int sort(int *parr,int low,int high)
{
	int flag,l,h;
	flag = low;
	l =	low;
	h = high;
	while(l!=h)
	{
		while(parr[h]>=parr[flag] && h>l)
		{
			h--;
		}
		while(parr[l]<=parr[flag] && h>l)
		{
			l++;
		}
		swap(parr+l,parr+h);
		out_put(parr);	
	}
	if(flag != l)
	{
		swap(parr+flag,parr+l);
	}
	out_put(parr);	
	return l;		
}
#endif

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
int main()
{
	int arr[]={12,3,5,9,41,11,27,23,45,7,10};
	quick_sort(arr,0,10);
	out_put(arr);
	printf("swap:%d\n",friend);
	return 0;

}
void out_put(int *parr)
{
	int i;
	for(i=0;i<11;i++)
	{
		printf("%d ",*(parr+i));
	}
	printf("\n");
}
