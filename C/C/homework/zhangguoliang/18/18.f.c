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
	cp(a);
	ava(a);
	return 0;
}
int cp(int a[10])
{	int i,m,n,x,y;	
	m=a[0];
	x=m;
	n=a[9];
	y=n;
	for(i=0;i<10;i++)
	{
		if(m<a[i])
		{
			m=a[i];
			a[0]=m;
		}
		if(n>a[i])
		{
			n=a[i];
			a[9]=n;
		}
	}
	printf("最高分：%d\n最低分:%d\n",m,n);
	for(i=1;i<9;i++)
	{
		if(a[0]==a[i])
				a[i]=x;
		if(a[9]==a[i])
				a[i]=y;
	}
}

int ava(int a[])
{	int sum=0,i;
	float z;
	for(i=1;i<9;i++)
	{
		sum+=a[i];
	}
	printf("sum=%d\n",sum);
	z=(sum)/8;
	printf("最后的平均分为:%.2f\n",z);
}
