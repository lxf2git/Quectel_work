#include<stdio.h>
int main()
{
int a,b,m,n,x,y;
printf("please input:");
scanf("%d%d",&a,&b);
m=a%10;
a/=10;
n=a%10;
x=b%10;
b/=10;
y=b%10;
printf("%d\n",m+y*10+100*n+1000*x);
return 0;
}
