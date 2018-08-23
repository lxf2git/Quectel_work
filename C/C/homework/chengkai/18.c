#include<stdio.h>
#include<time.h>

int max(int *arr);
int min(int *arr);
void average(int *arr,int num,int num1);

int main()
{	
	srand(time(NULL));

	int arr[10],i,num,num1;

	for(i=0;i<10;i++){
		
		arr[i] = rand()%100;	
		printf("%d ",arr[i]);		
	}
	
	printf("\n");
		
	num = min(arr); 
	num1 = max(arr);
	average(arr,num,num1);
	
	printf("min:%dmax:%d\n",num,num1);	
	return 0;		
}

int max(int *arr )
{			
	int i,j=0,median=0;

	for(i=0;i<10;i++){
			
		if(arr[j]<arr[i]){			
					
			median = arr[j];		
			arr[j] = arr[i];
			arr[i] = median;
		}					
	}		
		
	return(arr[j]);
}

int min(int *arr)
{
	int i,j = 0,median=0;

	for(i=0;i<10;i++){
			
		if(arr[j]>arr[i]){

			median = arr[j];
			arr[j] = arr[i];
			arr[i] = median;
		}		
	}

	return(arr[j]);
}

void average(int *arr,int num,int num1)
{
	int i;
	float aver;		
	
	for(i=0;i<10;i++){
			
		if(arr[i] == num||arr[i] == num1){
				continue;		
		}		
		aver+=arr[i];	
	}	
	
	printf("$%f\n",aver = aver/8);
		
}












