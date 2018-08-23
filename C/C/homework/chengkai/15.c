#include<stdio.h>
void count(int num);

int main()
{
	int num;
	
	scanf("%d",&num);
	
	count(num);
	
	return 0;
		
}

void count(int num)
{
	int sum = 0,i,few = 0;

	if(100>=num||num>=500){
		
		printf("input error\n");		
		return;
	}
		
	for(i=2;i<num;i++){
		
		if(num%i == 0){			
			sum+=i;
			few++;	
		}			
	}		
	
	printf("count:%dsum:%d\n",few,sum);	
		
}
