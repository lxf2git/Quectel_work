
#include"../apue.h"
pthread_mutex_t m;
pthread_cond_t c;
int flag;

void *thread1(void *p)
{
	for(;;)
	{
		pthread_mutex_lock(&m);	
		if(flag==0)
		{
			//printf("thread:%s\n",(char*)p);
			pthread_cond_wait(&c,&m);//
		}
		
		
			write(1,p,1);
			sleep(1);
		pthread_mutex_unlock(&m);
	}
}

int main()
{
	char ch;	
	pthread_mutex_init(&m,NULL);
	pthread_cond_init(&c,NULL);
	pthread_t tid1,tid2;
	pthread_create(&tid1,NULL,thread1,".");
	pthread_create(&tid2,NULL,thread1,"*");

	for(;;)
	{
		scanf("%c",&ch);
		getchar();
		if(ch=='a')
		{
			flag = 1;	
			pthread_cond_signal(&c);
		}
		else if(ch=='b')
		{
			flag = 1;
			pthread_cond_broadcast(&c);
		}
		
			flag = 0;
	}

	return 0;

}
