#include<stdio.h>
int main()
{
int a,data1,data2;char op;
printf("输入数字和运算符：");
scanf("%d,%c,%d,",&data1,&op,&data2);
if(op=='+'){a=data1+data2;printf("%d",a);}
else if(op=='-'){a=data1-data2;printf("%d",a);}
else  if(op=='*'){a=data1*data2;printf("%d",a);}
else  if(op=='/'){a=data1/data2;printf("%d",a);}
return 0;
}
