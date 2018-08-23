#include<stdio.h>
int main()
{
	int i,j,k;
	int arr[4][4]={0};
	
	for(i=0;i<4;i++){

		for(j=0;j<i+1;j++){
			arr[i][j]=i-j+1;
		}		
	
		for(k=i;k<4;k++){
			arr[i][k]=1;		
		}
	}		
		
	for(i=0;i<4;i++){
			
		for(j=0;j<4;j++){
				
			printf("%d ",arr[i][j]);		
		}			
		printf("\n");	
	}
		
	return 0;
}
