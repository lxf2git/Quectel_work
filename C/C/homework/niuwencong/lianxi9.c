#include<stdio.h>
#define N 5
int max_arr(int *p,int len)
{
	int max;
	max=*p;
	printf("***%d\n",max);
	while(len>0)
	{
		if(max<*p)
		{
		max=*p;
		p++;
		len--;
		}
	}
	return max;
}
int main()
{
	int *p;
	int a[N];
	int max,l=N;
	p=a;
	while(l>0)
	{
	scanf("%d",p);
		p++;
		l--;
	}
	max=max_arr(p,N);
	printf("%d",max);
return 0;
}
