#include<stdio.h>
int main()
{
	int a,b,c;
	int max,min,cha;
	scanf("%d%d%d",&a,&b,&c);
        max=(a>b?a:b)>c?(a>b?a:b):c;
	min=(a<b?a:b)<c?(a<b?a:b):c;	
	cha=max-min;
	printf("max=%d\nmin=%d\ncha=%d\n",max,min,cha);
return 0;
}