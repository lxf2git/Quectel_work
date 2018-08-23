#include<stdio.h>
int main()
{
	float h,m,s,x;
	printf("输入 时间 分钟 秒：\n");
	scanf("%f%f%f",&h,&m,&s);
	x=h*60+m+s/60;
	printf("时间为%.2f\n",x);
	return 0;


}
