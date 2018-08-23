#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i,j;
	char arr[100];

	scanf("%s",arr);
		
		for(i=0;arr[i]!='\0';i++){		
			if(arr[i] == 'c'){
				for(j=i;arr[j]!='\0';j++){
							
					 arr[j]= arr[j+1];
				}
					 i--;		
			}
		}		
			
	printf("%s",arr);

	putchar('\n');

	return 0;
}
