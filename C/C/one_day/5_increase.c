#include<stdio.h>

int main()
{
	int i=0,j=0;
	if(++i>0||(++j>0))//短路 
	{
		printf("i:%d\n",i);
		
		printf("j:%d\n",j);
	}

	return 0;
}
