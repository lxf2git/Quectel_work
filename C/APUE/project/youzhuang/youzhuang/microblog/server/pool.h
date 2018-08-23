#ifndef _POOL_MAIN_
#define _POOL_MAIN_
#include "../apue.h"
typedef struct worker
{
		/*回调函数，任务运行时会调用此函数，注意也可声明成其它形式*/
		void *(*process) (int arg);
		int arg;/*回调函数的参数*/
		struct worker *next;

} Thread_worker;
typedef struct
{
		pthread_mutex_t queue_lock;
		pthread_cond_t queue_ready;

		/*链表结构，线程池中所有等待任务*/
		Thread_worker *queue_head;

		/*是否销毁线程池*/
		int shutdown;
		pthread_t *threadid;
		/*线程池中允许的活动线程数目*/
		int max_thread_num;
		/*当前等待队列的任务数目*/
		int cur_queue_size;

} Thread_pool;

static Thread_pool *pool = NULL;

int pool_add_worker (void *(*process) (int arg), int arg);
void *thread_routine (void *arg);
void pool_init (int max_thread_num);
int pool_destroy ();
void *myprocess (int arg);

#endif
