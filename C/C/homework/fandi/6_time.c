#include<stdio.h>
int main()
{
	int h,z1;
	float m,s,z2;
	scanf("%d%f",&h,&m);
	scanf("%f",&s);
	if(h>=0&&h<=24&&m<=60&&m>=0&&s<=60&&s>=0)
	{		
		z1=60*h;
		z2=s/60;
		m=z1+z2+m;
	printf("转换为:%f分钟\n",m);
	}
	else
	{
		printf("输入有误\n");
	}
	return 0;
}
