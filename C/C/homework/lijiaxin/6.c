#include<stdio.h>

int main()
{
	int hour,minute;
	float second;
	printf("enter hour minute second :\n");
	scanf("%d%d%f",&hour,&minute,&second);
	if(hour>=0 && hour<=24)
	{		
		if(second/60 >= 0.5)
			minute = hour * 60 + minute + 1;
		else
			minute = hour * 60 + minute ;
		printf("大约为:%d minute.\n",minute);
	}
	else
		{
			printf("输入时间错误。\n");
		}
}
