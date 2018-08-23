#include<stdio.h>
int main()
{ 
    int a[5][5];
    int i,j,min,max;
  	for(i=0;i<5;i++)
  		{	
        	for(j=0;j<5;j++)
			{
				scanf("%d",&a[i][j]);
				if(j>=i)
				{
					if(a[i][j]<=a[0][0]&&i==4&&j==4)
						min = a[i][j];	
				}
				else
				{
				   if(a[1][0]>a[i+1][j+1])
				      max=a[i][j];
				}
			}
			printf("\n");
  		}			  
	printf("min=%d max=%d cha=%d\n",min,max,max-min);
return 0; 
}
