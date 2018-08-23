#include"../apue.h"

void *func(void *p)
{
	for(;;)
	{
		write(1,".",1);
		sleep(1);
	}
}

int main()
{
	pthread_t id;
	int i;	
	pthread_create(&id,NULL,func,NULL);	

	for(i=0;i<10;i++)
	{
		write(1,"*",1);
		sleep(2);
	}
	return 0;

}
