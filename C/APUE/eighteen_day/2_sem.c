#include"../apue.h"
sem_t s;
void *func(void *p)
{
	int i;	
	int *a = (int *)p;
	for(i=0;i<5;i++)
	{			
		sem_wait(&s);//让主线程先执行 等待主线程输入一个数据
		a[i] +=i;//1 3  5  7  9
		printf("a[%d]=%d\n",i,a[i]);
	}
}

int main()
{
	int a[5]={0},i;	
	sem_init(&s,0,0);
	pthread_t id;
	pthread_create(&id,NULL,func,a);
	for(i=0;i<5;i++)
	{
		printf("请输入第%d个数据\n",i+1);	
		scanf("%d",&a[i]);//1 2 3 4 5 
		sem_post(&s);//给辅助线程sem_wait放行 
	}

	pthread_join(id,NULL);
	for(i=0;i<5;i++)
	{
		printf("%d ",a[i]);
	}
	puts("\n");

	return 0;

}

