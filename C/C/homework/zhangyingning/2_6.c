//输入十分秒计算出有多少分钟

#include<stdio.h>

int main()
{
	float hour, minute, second;
	printf("请输入时分秒，分别以空格间隔\n");
	scanf("%f %f %f",&hour,&minute,&second);
	while(hour >= 24 || hour < 0)
		{
			printf("请重新输入小时\n");
			scanf("%f",&hour);
		}
	while(minute >= 60 || minute < 0)
		{
			printf("请重新输入分钟\n");
			scanf("%f",&minute);
		}
	while(second >= 60 || second < 0)
		{
			printf("请重新输入秒\n");
			scanf("%f",&second);
		}
	minute = hour * 60 + minute + second / 60;
	printf("一共是%.2f分钟\n",minute);
	return 0;
}
