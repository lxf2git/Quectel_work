#include<stdio.h>

int max_arr(int *p,int len);
int main()
{
	int i;
	int arr[10]={};
	int *p=NULL;
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	p=arr;
	printf("%d\n",max_arr(p,10));
	return 0;
}
int max_arr(int *p,int len)
{
	int max;
	max=*p;
	while(len>0)
	{	
		if(*p>=max)
		{
			max=*p;
		}
		p++;
		len--;
	}
	return max ;
}
