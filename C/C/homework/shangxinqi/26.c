#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
int i,j,max,min,a[5][5]={0};
printf("please input:");
for(i=0;i<5;i++)
{
	for(j=0;j<5;j++)
	{
		scanf("%d",&a[i][j]);
		n--;
		if(n==0)
		{
			goto quit;
		}
	}
}
quit: ;
max=a[4][0];
min=a[0][4];
for(i=0;i<5;i++)
{
	for(j=0;j<5;j++)
	{
		if(max<=a[i][j]&&i>j)
		{
			max=a[i][j];
		}else if(min>=a[i][j]&&i<=j)
			{
			min=a[i][j];
			}	
	}
}
printf("max:%d\nmin:%d\n",max,min);
return 0;
}
