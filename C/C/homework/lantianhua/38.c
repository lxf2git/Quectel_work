#include<stdio.h>
#define N 50
int input()
{
	int a,b;int i,c=1;
	printf("please input a number\n");
	scanf("%d",&a);
	printf("please input times\n");
	scanf("%d",&b);
	for(i=0;i<b;i++)
	{ c=c*a;

	}
	printf("%d\n",c);
	return c;

}
 void output(int m)
{

	int b;
	b=m%1000;
	printf("%d\n",b);
}
		
int main()
{
	int m;

	m=input();	
	output(m);
	return 0;
}

