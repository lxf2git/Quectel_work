#include<stdio.h>
int main()
{
int a[10]={1,2,3,4,5,6,7,8,9,10};
int n,m,x,i,j,q;
printf("开始位置与个数:");
scanf("%d%d",&n,&m);
i=n-1;
j=m+n-2;
do
{
	x=a[i];
	a[i]=a[j];
	a[j]=x;
	++i;
	--j;	
						
}while(i<j);
	for(q=0;q<10;q++)
	{
		printf("%d",a[q]);
	}
	printf("\n");
return 0;
}
