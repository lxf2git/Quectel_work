#include<stdio.h>
#include<string.h>

int main()
{
	char  arr[11],num;
	int  median1 = 0,k,median,i,j;

	scanf("%s",arr);
	getchar();	
	scanf("%c",&num);
	getchar();

	i = strlen(arr);

	if(num>arr[i-1]){
		arr[i] = num;	
		arr[i+1] = '\0';	
	}else{

		for(i=0;i<strlen(arr);i++){
		
			if(num<arr[i]){
				median = arr[i];
				arr[i] = num;
				median1 = i;
				break;						
			}				
		}
		
		for(j=median1+1;j<(strlen(arr))+1;j++){				
				 k = arr[j];
				 arr[j] = median;
			 	median = k;	
		}		

	}
	printf("%s",arr);
		
	return 0;		
}
