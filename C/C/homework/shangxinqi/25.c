#include<stdio.h>
int main()
{
int i,j,n,a[500][500]={0};
printf("please input:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
    	if(i<=j)
		{
			a[i][j]=1;
		}else
			a[i][j]=i-j+1;		
	}
}
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		printf("%d ",a[i][j]);
	}
		printf("\n");
}
return 0;
}
