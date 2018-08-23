#include<stdio.h>

int* input(int* p,int n);
void looking(int* p,int n);

int main()
{
	int arr[50],n;
	int *p=NULL;
	
	scanf("%d",&n);

	p = input(arr,n);
	looking(p,n);	
		
		
	return 0;
}

int* input(int* p,int n)
{
	int i;
	
	for(i=0;i<=n;i++){
				
		*(p+i) = i;	
	}		
		
	return(p);	
}

void looking(int* p,int n)
{
	int i,j=0,k=0;
	
	while(n-k>1){
			
		for(i=0;i<=n;i++){
					
			if(*(p+i) != 0){	
				j++;
				if(j == 3){
					*(p+i) = 0;
					k++;
					j = 0;		
				}		
			}
		}		
	}		
		
	while(*p == 0)p++;	
		printf("%d\n",*p);
		
}


