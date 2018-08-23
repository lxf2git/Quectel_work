#include "../include/apue.h"
//static Thread_pool *pool=NULL;
void pool_init(int max_thread_num)
{
	pool=(Thread_pool *)malloc(sizeof(Thread_pool));
	pthread_mutex_init(&(pool->queue_lock),NULL);
	pthread_cond_init(&(pool->queue_ready),NULL);
	pool->queue_head=NULL;
	pool->max_thread_num=max_thread_num;
	pool->cur_queue_size=0;
	pool->shutdown=0;
	pool->threadid=(pthread_t*)malloc(max_thread_num * sizeof(pthread_t));
	int i;
	for(i=0;i<max_thread_num;i++)
			pthread_create(&(pool->threadid[i]),NULL,thread_routine,NULL);
}
void *myprocess(void *arg)
{
		printf("threadid is 0x%x,working on task %d\n",pthread_self(),*(int*)arg);
		sleep(1);
		return NULL;
}
/*销毁线程池，等待队列中的任务不会再被执行，但是正在运行的线程会一直把任务运行完后再退出*/
int pool_destroy()
{
		if(pool->shutdown)
				return -1;/*防止两次调用*/
		pool->shutdown=1;
		//唤醒所有等待线程，线程池要销毁
		pthread_cond_broadcast(&(pool->queue_ready));
		/*阻塞等待线程退出，否则就成了僵尸*/
		int i;
		for(i=0;i<pool->max_thread_num;i++)
		pthread_join(pool->threadid[i],NULL);
		free(pool->threadid);
		/*销毁等待队列*/
		Thread_worker *head=NULL;
		while(pool->queue_head!=NULL)
		{
				head=pool->queue_head;
				pool->queue_head=pool->queue_head->next;
				free(head);
		}
		/*条件变量和互斥量也别忘了销毁*/
		pthread_mutex_destroy(&(pool->queue_lock));
		pthread_cond_destroy(&(pool->queue_ready));

		free(pool);
		/*销毁后指针置空是个好习惯*/
		pool=NULL;
		return 0;
}
void *thread_routine(void *arg)
{
		//printf("starting thread 0x%x\n",pthread_self());
		while(1)
		{
				pthread_mutex_lock(&(pool->queue_lock));
				//如果等待队列为0并且不销毁线程池，则处于阻塞状态
				while(pool->cur_queue_size==0&&!pool->shutdown)
				{
				//**		printf(" 0x%x 线程美女正在待命！\n",pthread_self());
						pthread_cond_wait(&(pool->queue_ready),&(pool->queue_lock));
				}
				if(pool->shutdown)
				{
						pthread_mutex_unlock(&(pool->queue_lock));
				//**		printf(" 0x%x 线程美女下班了！\n",pthread_self());
						pthread_exit(NULL);
				}
				//printf(" 0x%x 线程美女正在工作！\n",pthread_self());
				printf("\n");

				//assert--调试用
				assert(pool->cur_queue_size!=0);
				assert(pool->queue_head!=NULL);

				//等待队列长度减去1,并取出链表中的头元素
				pool->cur_queue_size--;
				Thread_worker *worker=pool->queue_head;
				pool->queue_head=worker->next;
				pthread_mutex_unlock(&(pool->queue_lock));

				/*调用回调函数，执行任务*/
				(*(worker->process))(worker->arg);
				free(worker);
				worker=NULL;
		}
		pthread_exit(NULL);
}
/*向线程池中加入任务*/
int pool_add_worker(void *(*process)(void *arg),void *arg)
{
		/*构造一个新任务*/
		Thread_worker *newworker=(Thread_worker*)malloc(sizeof(Thread_worker));
		newworker->process=process;
		newworker->arg=arg;
		newworker->next=NULL;

		pthread_mutex_lock(&(pool->queue_lock));
		/*将任务加入到等待队列中*/
		Thread_worker *member=pool->queue_head;
		if(member!=NULL)
		{
				while(member->next!=NULL)
						member=member->next;
				member->next=newworker;
		}
		else
		{
			pool->queue_head=newworker;
		}
		assert(pool->queue_head!=NULL);
		pool->cur_queue_size++;
		pthread_mutex_unlock(&(pool->queue_lock));
		//唤醒一个等待线程 如果所有线程都在忙碌，这句没有任何作用
		pthread_cond_signal(&(pool->queue_ready));
		return 0;

}
