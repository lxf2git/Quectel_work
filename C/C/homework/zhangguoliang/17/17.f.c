#include<stdio.h>
int main()
{
	int a[5];
	int i,x,y;
	printf("输入一组数字:\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	x=a[0];
	y=a[4];
	cp(a);
	for(i=1;i<4;i++)
	{	if(a[4]==a[i])
				a[i]=y;
		if(a[0]==a[i])
				a[i]=x;
	}
	for(i=0;i<5;i++)
	{
		printf("%d ",a[i]);
		if(i==4)
			printf("\n");
	}
	return 0;
}

int cp(int a[])
{
	int m,n,i,x,y;
	m=a[0];
	
	n=a[4];
	
	for(i=0;i<5;i++)
	{
		if(m<a[i])
			m=a[i];
		if(n>a[i])
			n=a[i];
	}
			a[4]=m;
			a[0]=n;
}

