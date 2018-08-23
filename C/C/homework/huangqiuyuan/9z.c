#include<stdio.h>
int main()
{
	int m,p,x=0;
	printf("你有多少钱：");
 	scanf("%d",&m);
	p=m;
	while(p>1)
{
	p=p/2;
	x=x+p;
}
	x=x+m+1;
	printf("可以喝%d\n瓶",x);
return 0 ;
}
