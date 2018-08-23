#include"../apue.h"

void *func(void *p)
{
	int *a = (int *)p;
	*a = 200;	
	printf("pid:%d thread_id:%lu\n",getpid(),pthread_self());
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
	int x=100;
	pthread_create(&id,NULL,func,&x);	
	
	//sleep(5);
	for(i=0;i<5;i++)
	{
		write(1,"*",1);
		sleep(2);
	}

	//printf("x-main:%d\n",x);
	printf("main-pid:%d thread_id:%lu\n",getpid(),pthread_self());
	pthread_join(id,NULL);//wait
	puts("辅助线程结束");
	return 0;

}
