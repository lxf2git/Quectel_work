#include<stdio.h>
int main()
{
int a,b,c;
float d;
for(;;)
{
scanf("%d%d%d",&a,&b,&c);
if(a>24||b>60||c>60)
{printf("输入错误");
		break;
}
else
d=60*a+b+c/60.0;
printf("%g",d);
}
}
