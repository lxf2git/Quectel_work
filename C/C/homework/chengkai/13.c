#include<stdio.h>
int main()
{
	int flag=0,n=0,num=0;
		
		for(num=6; ;){
		
				num++;
				flag=num;
				n=0;
				
			
				while((flag-1)%5==0){

					flag=4*(flag-1)/5;
					n++;			
				}		
					
					if(n==5){
							
						printf("%d\n",num);
						break;	
					}
			
		}
	return 0;		

}


