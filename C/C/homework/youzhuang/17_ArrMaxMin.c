#include<stdio.h>
int Max(int a[10]);
int Min(int a[10]);
void Exchange(int a[10],int max,int min);

int main()
{
		int a[10];
		int i,max_n,min_n;
		printf("请输入10个数字：\n");
		for(i=0;i<10;i++)
		{
				scanf("%d",&a[i]);
		}
		max_n=Max(a);
		min_n=Min(a);
		Exchange(a,max_n,min_n);
		for(i=0;i<10;i++)
		{
				printf("%d ",a[i]);
		}
		printf("\n");
		return 0;
}

int Max(int a[10])
{
		int max=a[0];
		int i,n=0;
		for(i=1;i<10;i++)
		{
				if(max<a[i])
				{
						max=a[i];
						n=i;
				}
		}
		printf("最大值a[%d]：%d \n",n,max);
		return n;
}

int Min(int a[10])
{
		int min=a[0];
		int i,n=0;
		for(i=1;i<10;i++)
		{
				if(min>a[i])
				{
						min=a[i];
						n=i;
				}
		}
		printf("最小值a[%d]：%d \n",n,min);
		return n;
}

void Exchange(int a[10],int max,int min)
{
		int t;
		t=a[9];
		a[9]=a[max];
		a[max]=t;

		t=a[0];
		a[0]=a[min];
		a[min]=t;
}
