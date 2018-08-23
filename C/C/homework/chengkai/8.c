#include<stdio.h>
int main()
{
	float i,j = 100,a = 100;
		
	for(i=0;i<10;i++){

		a = a/2;
		j = j+2*a;
	}	
		
	printf("%f\n%f\n",a,j);
	
	return 0;
	
}				
