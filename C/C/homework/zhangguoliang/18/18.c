#include<stdio.h>
int main()
{
	int a[10];
	int i,m,n,sum=0;
	float y;
	printf("请十位老师打分:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	m=a[0];
	n=a[9];
	for(i=0;i<10;i++)
	{
		if(m<a[i])
		{
			m=a[i];
		}
		if(n>a[i])
		{
			n=a[i];
		}
	}
	for(i=0;i<10;i++)
	{
		sum+=a[i];
	}
	printf("最高分：%d\n最低分:%d\n",m,n);
	y=(sum-m-n)/8;
	printf("最后的平均分为:%.2f\n",y);
	return 0;
}
