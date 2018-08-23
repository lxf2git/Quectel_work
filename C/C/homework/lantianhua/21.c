#include<stdio.h>

int main()
{	
	int a;
	int b,m=0;
	int i,j,k;
	int d=1;
	char str[50]={};
	printf("please input a number\n");
	scanf("%d",&a);
	if(a<0)
	{
		printf("-");
		a=a*(-1);
	}
	while(a%d != a)
	{
		d=d*10;
	}
	for(j=d/10;j!=0;j=j/10)
	{

		str[m]=(a/j)+48;
		a=a-((a/j)*j);
		m++;
	}
	str[m]='\0';
         printf("%s\n",str);
	return 0;
}
