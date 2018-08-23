#include<stdio.h>
#define N 10
int main()
{
				int a[N]={};
				int i,m,z=0;
				int subscript;
				printf("请输入十个数\n");
		for(i=0;i<N;i++)
		{
				scanf("%d",&a[i]);
		}
		printf("在输入一个数\n");
		scanf("%d",&m);
		for(i=0;i<N;i++)
		{
				if(m==a[i])
				{
						subscript=i;
						break;
				}
				else
				{
						z++;
				}
		}
		if(z==N)
		{
				printf("sorry,not found\n");
		}
		else
		{
				printf("下标值：%d\n",subscript);
		}
}
