#include<stdio.h>
#define N 2
int main()
{
		int a,b,c;
		printf("请输入两个两位数:\n");
		scanf("%d%d",&a,&b);
		c = 100*(a/10)+a%10+1000*(b%10)+10*(b/10);
		printf("%d\n",c);
}
/*
{
		int a,b,c[N][N];
		printf("请输入两个两位数:\n");
		scanf("%d%d",&a,&b);
		
}*/

