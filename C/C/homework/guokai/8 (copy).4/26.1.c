#include<stdio.h>
#define N 3
int main()
{
	int a[N][N];
	int i,j,min,max=0;
    	for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				scanf("%d",&a[i][j]);
				if(j>=i)
				{
					if(i==0&&j==0)	
					   min=a[0][0];	
				    if(min>a[i][j])	
			           min=a[i][j];				
				}
			    else if(a[i][j]>max)
					    max=a[i][j];
			}	
			printf("\n");
		}
		printf("max=%d min=%d\n",max,min);
return 0;
}
