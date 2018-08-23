#include<stdio.h>

int main()
{
		int count=0,i;
		float sum;
		printf("请输入一行整数用空格隔开，用0结束:\n");
		scanf("%d",&i);
		while( i!=0 )
		{
				sum += i;
				count++;
				scanf("%d",&i);
		}
		printf("%d",count);
		if(count%2==0)
				printf("偶数的平均数:");
		else
				printf("奇数的平均数:");
		printf("%f",sum=sum/count);
}
