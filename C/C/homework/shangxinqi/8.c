#include<stdio.h>

int main()
{
float a,b;
int i;
b=100;
a=100;
for(i=1;i<=10;i++)
{
a=a/2;
b=b+a*2;
}
printf("高度为:%f\n经过的长度为:%f\n",a,b);
return 0;
}
