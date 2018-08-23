#include<stdio.h>
int main()
{	int a,b,u;
	scanf("%d%d",&a,&b);
	int i[4];
	i[3]=a%10;
	i[1]=a/10;
	i[2]=b%10;
	i[0]=b/10;
	for(u=0;u<4;u++)
	printf("%d",i[u]);
}
