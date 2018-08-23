#include<stdio.h>
void change(int *a,int *b);
void compere(int a,int b,int c);

int main()
{
	int a,b,c;

	printf("input three number:");
	scanf("%d%d%d",&a,&b,&c);
	compere(a,b,c);
	return 0;
}

void compere(int a,int b,int c)
{	
	if(a>=b)
		change(&a,&b);
	if(a>=c)
		change(&a,&c);
	if(b>=c)
	    change(&b,&c);
	printf("MAX is %d\n",c);
	printf("MIN is %d\n",a);
	printf("MAX - MIN is %d\n",c-a);
}

void change(int *a,int *b)
{
	int temp;
	temp =*a;
	*a=*b;
	*b=temp;
}
