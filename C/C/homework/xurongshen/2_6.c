#include<stdio.h>

int main()
{
	int a=1,h,m,s;
	printf("请输入一个时间：格式（时 分 秒）");
	scanf("%d %d %d",&h,&m,&s);

	if(h>23 || h<0)
		if(m>59 || m<0)
			if(s>60 || s<0)
			{
				a=0;
				printf("请输入一个时间：格式（时 分 秒）");
				scanf("%d %d %d",&h,&m,&s);
			}
	//m = m + h*60;
	//s = s + m*60;
	m = h + h*60+1;
	//printf("输出的时间：%d秒\n",s);
	printf("输出的时间：%d分钟\n",m);
	return 0;

}
