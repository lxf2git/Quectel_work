#include<stdio.h>
#define SMILE
int main()
{
	#ifdef SMILE
		printf("^_^\n");
	#else
		printf("hehe\n");
	#endif 	
	return 0;

}
