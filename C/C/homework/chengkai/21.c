#include<stdio.h>
int main()
{
	char arr[5]={0};
	int i,j,num;

	for(i=0;i<5;i++){
			
		scanf("%d",&num);
			
			if(num>=0&&num<=9){
				arr[i] = num+48;
						
			}else{
				arr[i] = num;		
			}
			
	}
			
	for(i=0;i<5;i++){
		
		if(arr[i] == '\0'){
			break;		
		}	
		printf("%c ",arr[i]);		
	}
		
	return 0;		
}
