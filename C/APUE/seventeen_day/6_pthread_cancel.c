#include"../apue.h"

void *thread(void *p)
{
	for(;;)
	{
		printf("%s",(char*)p);
		fflush(stdout);
		sleep(1);
	}

	return NULL;
}

int main()
{
	pthread_t id;
	pthread_create(&id,NULL,thread,".");	

	sleep(5);
	pthread_cancel(id);
	puts("--------------");

	sleep(5);
	pthread_exit(NULL);
	puts("***********");
	return 0;

}
