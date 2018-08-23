#include<stdio.h>
int main()
{
	int a[5];
	
	int i,m,n,x,y;
	printf("输入一组数字:\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
		
	}
	m=a[0];
	x=m;
	n=a[4];
	y=n;
	for(i=0;i<5;i++)
	{
		if(m<a[i])
			m=a[i];
		if(n>a[i])
			n=a[i];
	}
	a[4]=m;
	a[0]=n;
	for(i=1;i<4;i++)
	{
		if(a[0]==a[i])
				a[i]=x;
		if(a[4]==a[i])
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
