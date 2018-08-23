#include<stdio.h>
#include<string.h>
#define N 20

char* sorting(char* arr,char* arr1);
void delete(char* arr);

int main()
{	
	char arr[N]={0},arr1[N]={0};
	char *p=NULL;
	scanf("%s",arr);
	scanf("%s",arr1);

	p = sorting(arr,arr1);
	delete(p);	

	return 0;		
}

char* sorting(char* arr,char* arr1)
{	
	int i,j,tmep=0,t=0;
	char ch='\0';
			
	strcat(arr,arr1);		
	t = strlen(arr)-1;
	
	
	for(i=0;i<t;i++){
		for(j=0;j<t-i;j++){
			if(arr[j]>arr[j+1]){
				tmep = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmep;	
			}			
		}			
	}
	
	printf("%s\n",arr);

	return(arr);
	
}


void delete(char* arr)
{
	int i,k=0,n=0;
	char *p = NULL;
	p = arr;

	while(n<strlen(arr)){
		
		for(i=n+1;i<strlen(arr);i++){
				if(*(p+n) == *(p+i)){
					*(p+i) = *(p+i+1);
					if(*(p+i) == *(p+i+1)){
							k = 1;	
					}		
				}		
		}		
		if(k == 1){k = 0;continue;}
		n++;
	}
	
	printf("%s\n",arr);
	
}	
	
			
		
		







