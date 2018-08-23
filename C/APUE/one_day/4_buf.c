#include<stdio.h> //input output
int main()
{
	int i=0;
	for(i=0;i<3;i++)
	{
		sleep(1);	
		printf("%d ",i);
		fflush(stdout);
	}	
	return 0;

}
