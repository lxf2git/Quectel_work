#include"../apue.h"

void *func(void *p)
{
	int i;	
	int *a = (int *)p;
	*a = 200;	
	printf("pid:%d thread_id:%lu\n",getpid(),pthread_self());
	for(i=0;i<10;i++)
	{
		write(1,".",1);
		sleep(1);
	}
	//pthread_exit((void*)0x8888);
	return((void*)0x8888);
}

int main()
{
	pthread_t id;
	int i;	
	void *v;
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
	pthread_join(id,&v);//wait
	printf("return:%x\n",(int)v);
	puts("辅助线程结束");
	return 0;

}
