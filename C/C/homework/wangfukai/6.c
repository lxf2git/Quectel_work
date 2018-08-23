#include<stdio.h>
int main()
{
	int a,b,c,d;
	printf("输入时间:\n");
	scanf("%d%d%d",&a,&b,&c);
	d=a*60+b+c/60;
	printf("%d",d);
	return 0;
}
