#include<stdio.h>

int complate(int a,int n);
void last_3_num(int sul);

int main()
{
	int a,n,sul;

	printf("input a num:");
	scanf("%d",&a);
	printf("input a power:");
	scanf("%d",&n);
	
	sul=complate(a,n);

	printf("%d^%d=%d\n",a,n,sul);

	last_3_num(sul);
	return 0;
}
int complate(int a,int n)
{
	 
	int sul;	
	if(n==0)
		return 1;
	sul=a*complate(a,n-1);

	return sul;
}
void last_3_num(int sul)
{
	int i;
	
	sul %= 1000;
	
	printf("%d ",sul/100);
	printf("%d ",sul/10-sul/100*10);
	printf("%d\n ",sul%10);
	
}
