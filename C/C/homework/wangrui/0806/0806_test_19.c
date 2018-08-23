#include<stdio.h>
#define N 100
int main()
{
	int arr[N]={};
	int i;
	int m=0;
	int n=0;
	float x=0;
	float y=0;
	printf("输入数字,输入0结束\n");
	for(i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i]==0)break;
		else if(arr[i]%2==0)
		{
			m++;
			x=x+arr[i];
		}
		else
		{
			n++;
			y=y+arr[i];
		}
	}
	printf("%d\n%f\n%d\n%f\n",m,x/m,n,y/n);
}
