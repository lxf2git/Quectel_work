#include<stdio.h>
#include<time.h>

void looking(int *arr);

int main()
{	
	srand(time(NULL));
	int i,arr[10];
	
	for(i=0;i<10;i++){
				
		arr[i] = rand()%100;
		printf("%d,",arr[i]);
		
	}
	printf("\n");
		
	looking(arr);		
		
	return 0;		
}


void looking(int *arr)
{
	int input,i,count=1;
	
	scanf("%d",&input);
	
	for(i=0;i<10;i++){
					
		if(input == arr[i]){
			printf("%d\n",i);			
			count = 0;
		}
	   
	}	
		if(count == 1){
						
			printf("sorry not found\n");
		}			
		
					
}
