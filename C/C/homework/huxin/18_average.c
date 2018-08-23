#include<stdio.h>
#define N 4
int main()
{
	int i,j,flag=0,flag1=0,sum=0,average=0;
	int max,min;
	int a[N];
	printf("please input in :\n");
	scanf("%d",&a[0]);
	max=a[0];
	min=a[0];
	for(i=1;i<N;i++)
	{
		scanf("%d",&a[i]);
		if(max<a[i])
		{
			max = a[i];
			flag=i;
		}
		if(min>a[i])
		{
			min = a[i];
			flag1 = i;
		}
	}
	a[flag]=0;
	a[flag1]=0;
	for(j=0;j<N;j++)
	{
	  	sum=sum+ a[j];	  
		average=sum/(N-2);
	}
    printf("average=%d\n",average);
}
