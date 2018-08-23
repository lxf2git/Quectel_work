
#include "P12306.h"
#include "Thread_pool.h"


extern Pqueue pool;

void creat_memory(void** q, int size)
{
	(*q) = malloc(size);

	if ((*q) == NULL)
	{
		printf("malloc fail\n");
	}

}

void pool_init(int max_thrd_num)
{
	creat_memory((void**)&pool, sizeof(Squeue));

	pthread_mutex_init(&(pool->q_lock), NULL);

	pthread_cond_init(&pool->q_ready, NULL);
	
	pool->q_head = NULL;
	
	creat_memory((void**)(&pool->thrdid), max_thrd_num *sizeof(pthread_t));
	pool->max_thrd_num = max_thrd_num;
	
	pool->cur_q_size = 0;

	int i=0;

	for (i=0; i< max_thrd_num; i++)
	{
		pthread_create(&(pool->thrdid[i]), NULL, thread_routine, NULL);	
	}
	
}

void* thread_routine(void* arg)
{
		while(1)
		{
		
				pthread_mutex_lock(&(pool->q_lock));

				while(pool->cur_q_size == 0 && !(pool->shutdown))
				{
						printf("[%s = %d line] wait \n", __FUNCTION__, __LINE__ ); 
						pthread_cond_wait(&(pool->q_ready), &(pool->q_lock)); 
				}

				if (pool->shutdown)
				{
						pthread_mutex_unlock(&(pool->q_lock));
						pthread_exit(NULL);
				}

				assert(pool->cur_q_size != 0);

				pool->cur_q_size--;

				Pworker worker = pool->q_head;
				pool->q_head = worker->next;
				pthread_mutex_unlock(&(pool->q_lock));
				(* (worker->process))(worker->ppakg);
				free(worker);
				worker = NULL;
		}

		pthread_exit(NULL);
}

int pool_add_worker(void*(*process)(void* ppakg), void* ppakg)
{
	Pworker newworker =NULL;
	creat_memory((void**)&(newworker), sizeof(Sworker));
	newworker->process = process;
	newworker->ppakg = ppakg;
	newworker->next  =NULL;
	
	pthread_mutex_lock(&(pool->q_lock));
	
	Pworker ptravl = pool->q_head;
	if (ptravl !=NULL)
	{
			while(ptravl->next !=NULL)
			{
					ptravl = ptravl->next;
			}
			ptravl->next = newworker;
	}
	else
	{
		pool->q_head = newworker;
	}

		pool->cur_q_size++;

		assert(pool->q_head !=NULL);
		assert(pool->cur_q_size != 0);

		pthread_cond_signal(&(pool->q_ready));
		pthread_mutex_unlock(&(pool->q_lock));
		return 1;
}

int pool_destroy()
{
	if (pool->shutdown == 1)
	{
		return FALSE;  
	}

	pool->shutdown = 1;
	pthread_cond_broadcast(&(pool->q_ready));

	int i=0; 
	for (i=0; i<pool->max_thrd_num; i++)
	{
		pthread_join(pool->thrdid[i], NULL);
	}
	free(pool->thrdid);	

	pool->thrdid = NULL;
	Pworker  worker = pool->q_head;
	while(pool->q_head !=NULL)
	{
		worker = pool->q_head;
		pool->q_head = pool->q_head->next;
		free(worker);
	}

	pthread_cond_destroy(&(pool->q_ready));
	pthread_mutex_destroy(&(pool->q_lock));
	free(pool);
	pool = NULL;
	return TRUE; 
}





















