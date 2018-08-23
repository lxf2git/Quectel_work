#include<stdio.h>

int main()
{
#if 0		
	int a=0;	
	int *point=&a;
	//point=&a;
	
	*point = 100;//a=100;
	//printf("*point:%d \n",*point);	
#endif





	int *point1=NULL;// (void*)0  '\0'  0
	//int *point2;

	*point1=1000;//NULL=1000
	printf("*point1:%d \n",*point1);	
	return 0;

}
