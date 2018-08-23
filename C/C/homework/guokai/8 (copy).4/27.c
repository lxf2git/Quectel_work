#include<stdio.h>

int main()
{
	int a,b,c;
    scanf("%d%d",&a,&b);	
	c=(a%10)+(a/10)*100+(b/10)*10+(b%10)*1000;	
	printf("%d",c);
}
