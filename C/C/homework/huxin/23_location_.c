#include<stdio.h>
int main()
{
    int  m,n,x,d,i,t;
	int  a[10]={1,2,3,4,5,6,7,8,9,10};
	for(x=0;x<10;x++)
	{
		printf("%d",a[x]);
	}
	printf("\n");
	printf("please input you require :\n");
    printf("first   figure :\n");
	scanf("%d",&m);
	printf("last figure : \n");
	scanf("%d",&n);
	d=n/2;
	m=m-1;
	n=n+m-1;
	for(i=m;i<=m+d;i++,n--)
	{

	  	t=a[i];
		a[i]=a[n];
		a[n]=t;
    }
    for(x=0;x<10;x++)
	{
		printf("%d",a[x]);
	}
	printf("\n");

	return 0;
}
