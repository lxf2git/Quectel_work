#include<stdio.h>
#include<time.h>

void exchange(int *arr,int max1,int min1);
int max(int *arr);
int min(int *arr);

int main()
{	
	srand(time(NULL));

	int i,arr[10],num1,num;

	for(i=0;i<10;i++){

		arr[i] = rand()%100;		
		printf("%d ",arr[i]);			
	}
	printf("\n");

	num1 = max(arr);
	num  = min(arr);
	exchange(arr,num1,num);

			
	return 0;		
}


int max(int *arr)
{
	printf("$$$");
	int median,i,j=1,k;

	for(i=0;i<10;i++){
			
		if(arr[j]<arr[i]){
			j = i;				
		}		
	}			
		
	return(j);	
		
}


int min(int *arr)
{
	int median=0,i,j=1,k;
	
	for(i=0;i<10;i++){
			
		if(arr[i]<arr[j]){
				j = i;	
		}				
	}
	
	return(j);
}	
	
	
void exchange(int *arr,int max1,int min1)
{
	int i,median;
	
	median = arr[9];
	arr[9] = arr[max1];
	arr[max1] = median;

	median = arr[0];
	arr[0] = arr[min1];
	arr[min1] = median;
			
	for(i=0;i<10;i++){
			
		printf("%d ",arr[i]);		
	}		
		
}
	
	
			
		
		











