#include<stdio.h>


int main() 
{
	unsigned long  positive_num, sum = 1;
	unsigned int power, unit, ten, hund;
	int i;
	printf("positive_num power\n");

	scanf("%lu%u",&positive_num,&power); 	


	for (i =0; i<power; i++)
	{
		
	 sum *=positive_num;
		
	}
	
	unit = sum%10;
	ten = sum/10%10;
	hund = sum/10/10%10;

	printf("%u %u %u",hund, ten, unit); 
	 return 0; 
}
