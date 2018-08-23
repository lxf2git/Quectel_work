#include<stdio.h>

int main ()
{
	int i,max,min,b,c,m,a[10];
	m = 0;
	printf("请各位评委打分\n");
for(i=0;i<10;i++)
{
	scanf("%d",&a[i]);
}
	max = a[0];
	min = a[0];
for(i=0;i<10;i++)
{
if (max<a[i])
{
	max=a[i];//判断最大值
	b=i;
}
}
for(i=0;i<10;i++)
{
if(min>a[i])
{
	min=a[i];//判断最小值
	c=i;
}
}
for(i=0;i<10;i++)
{
if(i==b&&i==c)
{
  break;
}
else
	m=(m+a[i]);
}
	m=m/8;//求平均数
	printf("%d\n",m);

return 0;
}
