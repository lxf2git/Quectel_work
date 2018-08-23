#include<stdio.h>
int look_for(int num);

int main()
{
	int num,num1;
	
	scanf("%d",&num);		
		
	num1 = look_for(num);	
	
	printf("%d\n",num1);
			
	return 0;		
}


int look_for(int num)
{
	int i,j = 1;
	
	for(i=0; ;i++){
			
		if(num%j == num){
				
			break;
		}
			j*=10;		
	}		
		
	return(i);	
		
}
