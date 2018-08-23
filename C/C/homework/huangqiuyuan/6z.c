#include<stdio.h>
int main()
{
	float h,m,s,x;
	printf("输入一个时间：\n");
	scanf("%f %f %f",&h,&m,&s);
	if ((h>=0&h<=24)&(m>=0&m<=60)&(s>=0&s<=60))
{
	x=h*60+m+s/60;
	printf("转化为分钟为%f分\n",x);
}
	else
	printf("输入错误\n");

return 0;

}
