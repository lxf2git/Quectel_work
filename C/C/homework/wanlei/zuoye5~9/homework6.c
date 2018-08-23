#include<stdio.h>

int main()
{
	int h,m,s;
	float t=0;
	do
	{
		printf("请输入一个时间\n");
		scanf("%d%d%d",&h,&m,&s);
	}while(h>23||m>59||s>59);
	t=(60*h)+m+(s*0.1/6);
	printf("%f\n",t);
	return 0;
}
