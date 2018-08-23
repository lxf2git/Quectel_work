#include"apue.h"
void clean_upground()
{
	int i=0;
	while(i++ < 50)
	{
		printf("\n");
	}
}




void clean_downground()
{
	int i=0;
	while(i++ < 5)
	{
		printf("\n");
	}
}
void space()
{
	int i=0;
	printf("                            ");
	printf("         ");
}


void sleep1()
{
	int i=0;
	space();
	printf("等待跳转...\n");
	while(i++ < 2)
	{
		space();
		printf(".\n");
		sleep(1);
	}
}


