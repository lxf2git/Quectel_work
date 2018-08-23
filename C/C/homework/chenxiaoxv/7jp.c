#include<stdio.h>

int main()
{
char a;
int z,other,s,space;
z=0;
space=0;
s=0;
other=0;
printf("输入字符串:");
while((a=getchar())!='\n')
{
  if(a>=65&&a<=90||a>=97&&a<=122)
    z=z+1;
  else if(a>=48&&a<=57)
    s=s+1;
  else if(a==32)
    space=space+1;
  else if(a<65||a>91||a>123)
    other=other+1;
}
printf("输出字母:%d\n",z);
printf("输出数字:%d\n",s);
printf("输出空格:%d\n",space);
printf("输出其他:%d\n",other);
return 0;
}
