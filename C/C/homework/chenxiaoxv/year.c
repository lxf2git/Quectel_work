#include<stdio.h>
 
int main()
{
 int a;
 printf("请输入一个年份:\n");
 scanf("%d",&a); 
 if((a%4==0&&a%100!=0)||a%400==0)
{ 
  printf("润年\n");
  printf("a:%d\n",a);
} 
 else if(a%4!=0)
   printf("平年\n");
 return 0;
}

