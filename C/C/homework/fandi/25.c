#include<stdio.h>
#define N 5
int main()
{
	int a[N][N],i,j,t,n=0;
	for(i=0;i<N;i++)
			for(j=0;j<N;j++){
					a[i][j]=i-j+1;
					if(i-j+1<=1)
							a[i][j]=1;
			}
	for(i=0;i<N;i++)
			for(j=0;j<N;j++){
					printf("%d ",a[i][j]);
					n+=1;
					if(n%N==0)
					printf("\n");
			}				
	return 0; 
}
