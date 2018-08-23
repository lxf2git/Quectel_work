#include<stdio.h>
int main()
{
	float h,m,s,t;

	printf("输入时分秒：\n");
	scanf("%f%f%f",&h,&m,&s);
	
	t=h*60+m+s/60;

	printf("%f分\n",t);

	return 0;

}
