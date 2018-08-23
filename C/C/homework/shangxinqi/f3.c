#include<stdio.h>

int main()
{
int year;
printf("请输入年份:\n");
scanf("%d",&year);
if((year%400==0)||(year%100!=0&&year%4==0))
printf("it is\n");
else 
printf("it is not\n");
return 0;
}
