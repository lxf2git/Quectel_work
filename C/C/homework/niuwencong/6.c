#include<stdio.h>
int main()
{
	float hour,minute,second;
	float t;
	printf("请输入要转换的时间:\n");
	scanf("%f%f%f",&hour,&minute,&second);
	printf("转换结果为：%f分钟\n",60*hour+minute+second/60);

return 0;



}
