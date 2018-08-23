#include<stdio.h>
#define N 100
int *count(int *a,int x);

int squr(int x,int y)
{
	int i,z;
	z=x;
	for(i=0;i<y-1;i++)
	{
		z=z*x;
	}
//	printf("%d",z);
	return z;
}
int *count(int *a,int x)
{
	int i,j;
	for(i=0;i<3;i++)
	{
		j=x%10;
		//printf("%d ",j);
		*(a+i)=j;
		x=x/10;
		//printf("%d ",x);
	}
	return a;
}

int main()
{
	int x,y,i;
	int a[N]={0};
	int *p=a;
	printf("输入一个正数和次方数\n");
	scanf("%d%d",&x,&y);
	int z=squr(x,y);
	//printf("%d",z);
	*p=*count(p,z);
	for(i=2;i>=0;i--)
		printf("%d",*(p+i));
}
