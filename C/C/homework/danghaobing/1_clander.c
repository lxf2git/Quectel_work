#include<stdio.h>
int main()
{
		int a,d;
		printf("请输入年份：\n");
		scanf("%d",&a);
		d=a%100;
		if(d!=0)
		{
				d=a%4;
				if(d==0)
				printf("这一年是润年\n");
				else
				printf("这一年不是润年\n");
		}
		else
		{
		d=a%400;
		if(d==0)
		printf("这一年是润年\n");
		else
		printf("这一年不是润年\n");
		}
}
