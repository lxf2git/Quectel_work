#include<stdio.h>
int main()
{
	int a,b;
	float c,i;
	printf("请输入时间");
	scanf("%d%d%f",&a,&b,&c);
	i=a*60+b+c/60;
	printf("%f",i);
	return 0;	

}
