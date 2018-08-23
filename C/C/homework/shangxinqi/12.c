#include<stdio.h>

main ()
{
int a,b;
for(b=1;b<=9;b++)
for(a=1;a-b<=0;a++)
if(a==b)
		printf("%d*%d=%d\n",a,b,a*b);
		else
		printf("%d*%d=%d",a,b,a*b);

return 0;
}
