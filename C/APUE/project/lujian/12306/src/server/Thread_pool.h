#ifndef THREAD_POOL_H
#define  THREAD_POOL_H 

typedef struct Worker
{

	void*(*process)(void* ppakg);
	struct ser_deal_pakg* ppakg;
	struct Worker* next;

}Sworker, *Pworker;

typedef struct Queue
{
	pthread_mutex_t q_lock;
	pthread_cond_t q_ready;

	Pworker q_head;
	int shutdown;
	pthread_t *thrdid;
   	int max_thrd_num;
	int cur_q_size;

}Squeue, *Pqueue;

void creat_memory(void** q, int size);
void* thread_routine(void* pakg);
void pool_init(int max_thrd_num);
int pool_destroy();
int pool_add_worker(void* (*process)(void* ppakg), void* ppakg);


#endif 


