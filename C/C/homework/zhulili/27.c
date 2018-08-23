#include<stdio.h>

int main()
{
	int a,b,c,d,e,f,g;
	scanf("%d,%d",&a,&b);
	d=b%10*1000;
	e=a/10*100;
	f=b/10*10;
	g=a%10;
	c=d+e+f+g;
	printf("%d",c);

	return 0;

}
