#include"main.h"
long generatorId()
{
	char ch;
	int i;
	printf("please input card :\n");

	srand(time(NULL));
	
	ch = getchar();
	for (i = 0; i <= 3; i++)
	{
		printf("*************\n");
		sleep(1);
	}
	id = rand();


	return id;
}
