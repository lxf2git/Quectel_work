#include<stdio.h>

int main()
{
	int times=10;
	float high=100,lenght=0,temp=0;
	
	while(times)
	{
			
		lenght+=2*high;
		high/=2;

		times--;
	}
	lenght-=100;
	
	printf("10th's height is %f\n",high);
	printf("10th's lenght is %f\n",lenght);

	return 0;
}
