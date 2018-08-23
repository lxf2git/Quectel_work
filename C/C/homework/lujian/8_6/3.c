#include<stdio.h> 
#define  N (64)
int main() 
{
	int a[N]={}, i=0, x, flag =0;

	printf("please input x:\n"); 

	scanf("%d",&x); 

	if (0==i)
	{
		a[0] = x%2;
	}
	for ( i=1; i<N; i++)
	{
	
		x /= 2;
	
		a[i] = x%2;

	}
	
		printf("0b "); 
	for (i = N-1; i>=0; i--)
	{	
/********* 标记 第一 一 然后输出************/

		if( a[i] ==1)
			flag =1;
		if(1==flag)
		{
		printf("%d ",a[i]); 
		}
	}
	putchar('\n');
	 return 0; 
}
