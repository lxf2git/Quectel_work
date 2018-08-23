#include<stdio.h>
#define N 5
void input(int a[]);
void MAX_exchange(int a1[]);
void MIN_exchange(int a2[]);
void output(int a3[]);
int main()
{
		int arr[N];
		input(arr);
		MAX_exchange(arr);
		MIN_exchange(arr);
		output(arr);
		return 0;
}
void input(int a[])
{
	//	int a[N];
		int i;
		printf("请输入5位数:\n");
		for(i=0;i<N;i++)
		{
				scanf("%d",a+i);
		}

}
void MAX_exchange(int a1[])
{
		int j=0,i,exchange;
	    exchange=a1[0];
		for(i=0;i<N;i++)
		{
				if(exchange<a1[i])
				{
						exchange=a1[i];
						j=i;
				}
		}
		a1[j]=a1[N-1];
		a1[N-1]=exchange;
}
void MIN_exchange(int a2[])
{
		int j=0,i,exchange;
	    exchange=a2[0];
		for(i=0;i<N;i++)
		{
				if(exchange>a2[i])
				{
						exchange=a2[i];
						j=i;
				}
		}
		a2[j]=a2[0];
		a2[0]=exchange;
}
void output(int a3[])
{       int i;
		for(i=0;i<N;i++)
				printf("%d\n",a3[i]);

}










