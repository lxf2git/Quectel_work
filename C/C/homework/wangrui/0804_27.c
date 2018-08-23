#include<stdio.h>
void calculate(int,int);
int main()
{
	int a, b;
	
	printf("a:\n");
	scanf("%d",&a);
	printf("b:\n");
	scanf("%d",&b);
	calculate(a,b);
	return 0;
}

void calculate(int a,int b)
{
	int c[4]={};
	int i;
	c[1]=a/10;
	c[3]=a-(a/10*10);
	c[2]=b/10;
	c[0]=b-(b/10*10);
	i=0;
	if(c[0]==0)i=1;
	for(;i<4;i++)
	{
		printf("%d",c[i]);
	}
	printf("\n");
}
