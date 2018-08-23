#include<stdio.h>
int main()
{
	int a,b;
	printf("输入2位正整数:\n");
	scanf("%d %d",&a,&b);
	printf("c=%d",b%10*1000+a/10*100+b/10*10+a%10);

	return 0;




}

