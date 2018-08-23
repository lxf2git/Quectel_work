#include<stdio.h>
int main()
{
	int a,b,c;
	printf("输入两个两位数 a  b\n");
	scanf("%d%d",&a,&b);
	printf("c=%d\n",b%10*1000+a/10*100+b/10*10+a%10);
	return 0;
}
