#include<stdio.h>

int sort(int *parr, int low, int high);
void  swp(int *a,int *b);
void quick_sort(int *parr, int low, int high);
void output(int *p);
int friend =0;

#if 0
int sort(int *parr, int low, int high)
{
	int flag;
	int i=0;
	flag=low;
	int a=0;
	while(low != high)
	{
		if(a == 0)
		{
			if(parr[flag] > parr[high])
			{
				swp(parr+flag, parr+high);
				flag = high;
				low++;
			a=1;
			}
			else
			{
				high--;
			}
		}
		else
		{
			if(parr[flag] < parr[low])
			{
				swp(parr+flag,parr+low);
				flag = low;
				high--;
			a=0;
			}
			else
			{
				low++;
			}
		}	
		i++;
		printf("i:%d\n",i);
	}
	return flag;
}
#endif
#if 1
int sort(int *parr,int low,int high)
{
	int flag;
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

		swp(parr+low,parr+high);
	}
	if(flag != low)
	{
		swp(parr+flag,parr+low);
	}
	return low;
}
#endif
void  swp(int *a,int *b)
{
	friend++;
	*a = *a+*b;
	*b = *a-*b;
	*a = *a-*b;
}

void quick_sort(int *parr, int low, int high)
{
	int ret;
	ret = sort(parr,low, high);
	if(ret+1 < high)
	{
		quick_sort(parr, ret+1, high);//右侧递归

	}
	if(low < ret-1)
	{
		quick_sort(parr, low, ret-1);//左侧递归
	}
}

void output(int *p)
{
	int len;
	len = sizeof(p);
	printf("p:%d\n",len);
	int i;
	for(i=0;i<11;i++)
	{
		printf("%d  ",p[i]);
	}
}

int main()
{
	int arr[]={12,3,5,9,41,11,27,23,45,7,10};
	quick_sort(arr,0, 10);//数组名，第一个参数是该链的第一个数的下表，最后一个数的下表
	output(arr);//输出
	printf("friend:%d\n",friend);
}
