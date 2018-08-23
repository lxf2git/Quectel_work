#include<stdio.h>
int main()
{
	int a,b,c,x,y,m,n;
	scanf("%d,%d",&a,&b);
	x=a%10;
	y=a/10;
	m=b%10;
	n=b/10;
	c=m*1000+y*100+n*10+x;
	printf("c:%d\n",c);
	return 0;
}
