#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void min(int arr[][5]);
void max(int arr[][5]);


int main()
{	
	srand(time(NULL));
	int arr[5][5]={0};
	int i,j,k;
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
				
			arr[i][j] = rand()%100;		
		}				
	}
	
	min(arr);
	max(arr);


	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%4d",arr[i][j]);		
		}		
		printf("\n");	
	}	
		
		
	return 0;		
}


void min(int arr[][5])
{
	int i,j,median =0;
	
	median = arr[0][0];
	for(i=0;i<5;i++){
		for(j=i;j<5;j++){
			if(arr[i][j]<median){
				median = arr[i][j];
						
			}				
		}		
	}		
			
	printf("min:%d\n",median);		
}			
		
	
void max(int arr[][5])
{
	int i,j,median;
	
	median = arr[0][0];
	
	for(i=0;i<5;i++){
		for(j=0;j<i;j++){
			if(median<arr[i][j]){
				median = arr[i][j];		
			}		
		}				
	}		
		
	printf("max:%d\n",median);	
		
}
		
		
		







