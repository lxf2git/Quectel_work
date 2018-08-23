#include<stdio.h>
int main()
{
		int h,m;
		float s;
		printf("请输入时间 时 分 秒\n");
		scanf("%d%d%f",&h,&m,&s);
		if(h>=0&&h<=12)
        	printf("时间为%f分钟\n",h*60+m+(s/60.0));
		else 
			if(h>12&&h<=24)
				printf("时间为%f分钟\n",(h-12)*60+m+(s/60.0));
			else
				printf("错误");
return 0;		
}										
