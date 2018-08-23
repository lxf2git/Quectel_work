#include<stdio.h>
#define N 500
int p;
int input(int a[N])
{
	int i;
	printf("please input the quantity of people\n");
	scanf("%d",&p);
	for(i=0;i<p;i++)
	{
		a[i]=1+i;
	}
	for(i=0;i<p;i++)
	{
		printf("%4d",a[i]);
	}

}
int output(int a[N])
{	
	int i,j=0;
	for(i=0;i<N;i++)
	{
		if((i+1)%3==0)
		{
			a[i]=0;
			j++;
		//	printf(" killed is%d\n",i);
		}
		else
		{
			a[p+i-j]=a[i];
			a[i]=0;
		}
		if(a[p+i-j-1]==0&&a[p+i-j+1]==0)
		{
			return a[p+i-j];
		}
	}
}






int main()
{

	int a[N]={};
	int b;
	input(a);
      b=output(a);
	printf("the person is survived is:%d\n",b);
	
	return 0;
}
