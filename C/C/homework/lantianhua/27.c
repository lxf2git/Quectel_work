#include<stdio.h>

int main()
{	int a,b,c,i,j,m,n;
	printf("please input a,b\n");
	scanf("%d",&a);
	scanf("%d",&b);
	i=a%10;
	j=a/10;
	m=b%10;
	n=b/10;
	c=1000*m+100*j+10*n+i;
	printf("%d\n",c);
	





	return 0;
}
