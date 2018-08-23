#include<stdio.h>

int main()
{
		int a[5][5];
		int i,j;
		for(i=0;i<5;i++)
		{
				for(j=0;j<5;j++)
				{
						scanf("%d",&a[i][j]);
				}
				printf("\n");
		}
		int min=a[0][0],max=a[0][0];
		for(i=0;i<5;i++)
		{
				for(j=0;j<5;j++)
				{
						if(j>=i)
						{
								if(min>a[i][j])
								{
										min=a[i][j];
								}
						}
						else
						{
								if(max<a[i][j])
								{
										max=a[i][j];
								}
						}
						printf("%4d",a[i][j]);
				}
				printf("\n");
		}
		printf("min=%d,max=%d\n",min,max);
}
