#include<stdio.h>
int Max(int a[10]);
int Min(int a[10]);
int aver(int a[10],int max,int min);

int main()
{
		int a[10];
		int i,max,min;
		printf("请输入分数:\n");
		for(i=0;i<10;i++)
		{
				scanf("%d",&a[i]);
		}
		max=Max(a);
		min=Min(a);
		printf("平均分：%d\n",aver(a,max,min));

}

int Max(int a[10])
{
		int max,i;
		max=a[0];
		for(i=0;i<10;i++)
		{
				if(max<a[i])
				{
						max=a[i];
				}
		}
		return max;
}
int Min(int a[10])
{
		int min,i;
		min=a[0];
		for(i=0;i<10;i++)
		{
				if(min>a[i])
				{
						min=a[i];
				}
		}
		return min;
}
int aver(int a[10],int max,int min)
{
		int i,sum=0;
		for(i=0;i<10;i++)
		{
				sum=sum+a[i];
		}
		sum=sum-max-min;
		return sum/8;
}
