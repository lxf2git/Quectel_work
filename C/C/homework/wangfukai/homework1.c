#include<stdio.h>

int main()
{
int a;
printf("输入年份：\n");
scanf("%d",&a);
if
(a%4==0&&a%100!=0)
printf("是闰年");
else 
if(a%400==0)
printf("是闰年");
else
 printf("不是闰年");
return 0;
}
