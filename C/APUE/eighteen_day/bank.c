#include"../apue.h"
char *list[10]={"person1","person2","person3","person4","person5",
"person6","person7","person8","person9","person10"};
int pos=0;//当前位置

pthread_mutex_t mutex;
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *func(void *p)//排队 
{
	for(;;)
	{
		pthread_mutex_lock(&mutex);		
		if(pos>=10)
		{
			break;//出来
		}	
		printf("%d号美女为%s服务\n",*(int*)p,list[pos]);
		pos++;
		pthread_mutex_unlock(&mutex);
		sleep(5);//模拟服务时间
	}

		pthread_mutex_unlock(&mutex);//服务完毕 退出循环 还没解锁
		//所以要解锁互斥量
}

int main()
{
	pthread_mutex_init(&mutex,NULL);
	pthread_t id[3];
	int i,j;

#if 0
	for(i=1;i<4;i++)
	{
		pthread_create(&id[i-1],NULL,func,(void *)i);
	}

	for(j=0;j<3;j++)
	{
		pthread_join(id[j],NULL);
	}
#endif

#if 0
	pthread_t id1,id2,id3;	
	pthread_create(&id1,NULL,func,"1");
	pthread_create(&id2,NULL,func,"2");
	pthread_create(&id3,NULL,func,"3");

	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	pthread_join(id3,NULL);
#endif
	pthread_mutex_destroy(&mutex);
	return 0;

}
