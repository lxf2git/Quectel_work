#include<stdio.h>
int main()
{
	 int a[10]={1,2,3,4,5,6,7,8,9,10};
     int i,j,m,n;
     scanf("%d%d",&m,&n);
     i=m+n-2;
	 for(j=0;j<m-1;j++)
     printf("%d",a[j]);
     for(j=i;j>=m-1;j--)
	 printf("%d",a[j]);
     for(j=i+1;j<10;j++)
	 printf("%d\n",a[j]);	   
return 0;
}
