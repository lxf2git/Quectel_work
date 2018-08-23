#include<stdio.h>
int main()
{
	int a[5][5]={},i,j,min=9999999999,max=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf("%d",&a[i][j]);
	//	printf("%5d",a[i][j]);
			

				if(i<=j)
				if(min>=a[i][j])
						min=a[i][j];
				if(i>=j)
				if(max<a[i][j])
						max=a[i][j];
	}
		printf("\n");
		}

	printf("%d %d",max,min);
}
