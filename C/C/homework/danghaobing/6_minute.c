#include<stdio.h>
int main()
{		
		int h,m;
		float w,s;
		printf("请输入一个时间：\n");
		scanf("%d%d%f",&h,&m,&s);
		w=60*h+m+s/60;
		printf("一共有%f分钟\n",w);
}
