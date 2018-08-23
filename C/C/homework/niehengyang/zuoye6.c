#include<stdio.h>
int main()
{
	float hour,minute,second;
	int m;
	float n;
	float t;
	 printf("请输入一个时间：");
         scanf("%f:%f:%f",&hour,&minute,&second);
	if((hour<=24&&hour>=0)||(minute<=60&&minute>=0)||(second<=60&&second>=0))
	{
	m=hour*60;
	n=second/60;
	t=m+n+minute;
	printf("一共%f（分钟）\n",t);
	}
	else
	{
	printf("输入错误！");
	}
}
