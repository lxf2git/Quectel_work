#include<stdio.h>
#include<stdlib.h>

void find(int a[10],int n);

int main()
{
		int i,n;
		int a[10];
		printf("请输入10个数:\n");
		for(i=0;i<10;i++)
		{
				scanf("%d",&a[i]);
		}
		printf("请输入要查询的数字:\n");
		scanf("%d",&n);
		find(a,n);
		return 0;
}

void find(int a[10],int n)
{
		int i;
		for(i=0;i<10;i++)
		{
				if(a[i]==n)
				{
						printf("a[%d]=%d\n",i,a[i]);
						exit(0);
				}
		}
		printf("sorry,not found!\n");
}
