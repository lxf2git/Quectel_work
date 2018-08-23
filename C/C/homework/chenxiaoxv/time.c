#include<stdio.h>

int main()
{
	int a,b,c,d;
	d=0;
	printf("输入时分秒:");
	scanf("%d%d%d",&a,&b,&c);
	d=a*60+b+c/60;
	printf("d=%d\n",d);

return 0;
}

