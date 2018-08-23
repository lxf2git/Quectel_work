#include<stdio.h>

int main()
{
int data1,data2,a;
char op;
printf("输入两个数字和运算符\n");
scanf("%d%c%d",&data1,&op,&data2);
if(op=='*')
{
a=data1*data2;
printf("%d\n",a);
}
else if(op=='+')
{
a=data1+data2;
printf("%d\n",a);
}
else if(op=='-')
{
a=data1-data2;
printf("%d\n",a);
}
else if(op=='%')
{
a=data1%data2;
printf("%d\n",a);
}
else
printf("error\n");
return 0;
}
