#include<stdio.h>

int main()
{
int max,min,a,b,c;
printf("请输入三个数:\n");
scanf("%d%d%d",&a,&b,&c);
if(a-b>=0)
	max=a;
else
	max=b;
if(c-max>=0)
    max=c;
if(a-b>=0)
	min=b;
else
	min=a;
if(c-min<=0)
	min=c;
printf("最大与最小的差值为:%d\n",max-min);
return 0;
}


