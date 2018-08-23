#include<stdio.h>
int main()
{
	int h,m;
	float s,y;
	printf("输入 小时 分钟 秒\n");
	scanf("%d%d%f",&h,&m,&s);
	if((m>=0&&m<60)&&(s>0&&s<60))
	{	y=h*60+m+s/60;
		printf("是%2f分钟\n",y);
	}
	else
	      	printf("时间错误\n");
	return 0;
}
