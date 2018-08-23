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
			if(a[i][j]>max)
			   max=a[i][j];		
		}
		printf("每行最大:%d",max);
		printf("\n");
	   if(i==0)
		   min=max;	   
		if(max<min)	
		   min=max;
		   max=0;	
	}	
	printf("最小的为:%d\n",min);
return 0; 
}
