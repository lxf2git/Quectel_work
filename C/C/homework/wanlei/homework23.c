#include<stdio.h>

int main()
{
	int i,j,b,t,c,m;
	int a[10];
	printf("please input ten number\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	for(j=10;j>1;j--)
	{
		for(i=1;i<j;i++)
		{
			if(a[i-1]>a[i])
			{
				t=a[i-1];
				a[i-1]=a[i];
				a[i]=t;
			}
		}
	}
	//for(i=0;i<10;i++)
		//printf("%d ",a[i]);
#if 1
	printf("please input two number\n");
	scanf("%d%d",&b,&c);
	m=c;
	for(i=b-1;i<b-1+c/2;i++)
	{
		t=a[i];
		a[i]=a[i+m-1];
		a[i+m-1]=t;
		m-=2;
	}
#endif
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
