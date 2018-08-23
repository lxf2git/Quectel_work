#include<stdio.h>
#include<time.h>

int main()
{
	int n=5;	
	while(n>0)
	{	
		long t = time(NULL);	
		//printf("time:%s\n",ctime(&t);
		t+=1;
		while(time(NULL)<t)
		{
				;
		}
		printf(".\n");
		n--;
	}
	
	return 0;
}
