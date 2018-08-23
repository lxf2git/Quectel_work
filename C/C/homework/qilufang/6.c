#include<stdio.h>

int main()
{
	int hou,min,sec,a;
	float b,min_all;
	printf("输入时 分 秒\n");
	scanf("%d%d%d",&hou,&min,&sec);
	if((hou<25&&hou>0)&&(min>=0&&min<61)&&(sec>=0&&sec<61))
	{
		a=hou*60;
		b=sec/60.0;
		min_all=min+a+b;
		printf("合计%f分钟\n",min_all);
	}
	else
	{
		printf("输入错误！");
	}
	return 0;
}
