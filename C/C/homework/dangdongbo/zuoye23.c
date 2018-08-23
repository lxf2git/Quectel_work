#include<stdio.h>
int main()
{
		
		int n,i,a[10],m;
		for(i=0;i<10;i++)
		{
		scanf("%d",&a[i]);
		}
		scanf("%d%d",&m,&n);
		for(i=0;i<m-1;i++)
				printf("%d ",a[i]);
		for(i=m+n-2;i>m-2;i--)
				printf("%d ",a[i]);
		for(i=m+n-1;i<10;i++)
				printf("%d ",a[i]);
}
