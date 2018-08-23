#include<stdio.h>
int main()
{
	float hour=0,minute=0,send=0;
	float hour1,send1;
	scanf("%f%f%f",&hour,&minute,&send);
	
	hour1 = hour*60.0;
	send1 = send/60.0;

	printf("%f\n",hour1+send1+minute);

	return 0;

}		
