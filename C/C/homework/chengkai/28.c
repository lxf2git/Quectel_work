#include<stdio.h>
#include<time.h>

void max(int arr[][5],int arr1[]);
void min(int arr1[]);

int main()
{	
	srand(time(NULL));
	int arr[5][5],arr1[5];
	int i,j;

	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			arr[i][j] = rand()%100;		
		}				
	}
	
	max(arr,arr1);

	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%d ",arr[i][j]);		
		}
		printf("\n");		
	}
		
		
return 0;		
}

void max(int arr[][5],int arr1[])
{
	int i,j,k = 0,num;
		
	for(i=0;i<5;i++,k++){
		num = arr[i][0];
			for(j=0;j<5;j++){
				if(arr[i][j]>num){
					num = arr[i][j];				 		
				}					
			}	
		arr1[k] = num;
	}		
				
	min(arr1);				
}

void min(int arr1[])
{
	int i,j;
	
	j = arr1[0];
	for(i=0;i<5;i++){
		if(arr1[i]<j){
			j = arr1[i];		
		}		
	}
			
	printf("min:%d\n",j);

	for(i=0;i<5;i++){
		printf("max%d:%d",i,arr1[i]);		
	}
	printf("\n");
}




