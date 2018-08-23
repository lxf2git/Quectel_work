#include<stdio.h>
#define N 10

int main()
{
	int i,j,a=0,b=0,min,max,flog1,flog2,shuru[N];
	printf("输入十个数：\n");
	scanf("%d",&shuru[0]);
	min=max=shuru[0];
	for(i=1;i<N;i++)
	{
		scanf("%d",&shuru[i]);
		if(max<shuru[i])
		{
			max=shuru[i];
			flog1=i;
		}
		else if(min>shuru[i])
		{
			min=shuru[i];
			flog2=i;
		}
	}
	a=shuru[N-1];
	shuru[N-1]=shuru[flog1];
	shuru[flog1]=a;
	b=shuru[0];
	shuru[0]=shuru[flog2];
	shuru[flog2]=b;
	printf("调整后输出：\n");
	for(j=0;j<N;j++)
	{
		printf("shuru[%d]=%d\n",j,shuru[j]);
	}
	return 0;
}
