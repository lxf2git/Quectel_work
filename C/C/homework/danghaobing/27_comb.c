#include<stdio.h>

int main()
{
		int a,b;
		printf("请输入两位数a和b用空格隔开\n");
		scanf("%d%d",&a,&b);
		printf("%d",a/10*100+a%10+b/10*10+b%10*1000);
}
