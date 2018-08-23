#include"main.h"

int main()
{
	signal(SIGINT, service);
	init_red(&phead);
	start_sina();
//	printf("%p", phead);
	pool_init(LINE_NUM);
	int sockfd = socket_fun();
	int confd, i;
	struct sockaddr_in conaddr;
	socklen_t len = sizeof(conaddr);
	for(;;)
	{
		bzero(&conaddr, sizeof(conaddr));
		confd = accept(sockfd, (struct sockaddr*)&conaddr, &len); 
		pool_add_task(myprocess, &confd);
	}

	return 0;
}


int socket_fun()
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		perror("socket");
		return FAILURE;
	}
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9999);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int ret = bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));
	if(ret < 0)
	{
		perror("bind");
		close(sockfd);
		return -1;
	}
	listen(sockfd, 10);
	return sockfd;
}

void creat_memory(void **p, int size)
{
	*p = malloc(size);
	if(NULL == *p)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void pool_init(int max_line)
{
	creat_memory((void **)&pool, sizeof(Thread_pool));
	pthread_mutex_init(&pool->queue_lock, NULL);
	pthread_cond_init(&pool->queue_ready, NULL);

	pool->queue_head = NULL;

	pool->shutdown = 0;

	creat_memory((void**)&pool->threadid, max_line*sizeof(int));
	pool->max_thread_num = max_line;
	pool->cur_queue_size = 0;
	int i;
	for(i = 0; i < max_line; i++)
	{
		pthread_create(&pool->threadid[i], NULL, thread_routine, NULL);
	}
}

void *thread_routine(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&pool->queue_lock);
		if(pool->shutdown == 0 && pool->cur_queue_size == 0)
		{
			printf("line:%dwaiting\n", pthread_self());
			pthread_cond_wait(&pool->queue_ready, &pool->queue_lock);
		}
		if(pool->shutdown == 1)
		{
			pthread_mutex_unlock(&pool->queue_lock);
			pthread_exit(NULL);
		}
		printf("line:%dstart\n", pthread_self());
		pool->cur_queue_size--;
		Thread_worker *worker = pool->queue_head;
		pool->queue_head = worker->next;
		pthread_mutex_unlock(&pool->queue_lock);

		worker->usrFun(worker->confd);
		worker->next = NULL;
		free(worker);
		worker = NULL;
	}
}

void *myprocess(void *confd)
{
	sCts buf;
	int sockfd = *(int*)confd;
	int line = -1;
	while(1)
	{
		bzero(&buf, sizeof(buf));
		int ret = read(sockfd, &buf, sizeof(buf));
		if(ret <= 0 )
		{
			continue;
		}
		printf("%d\n", buf.type);
		func(sockfd, buf, line);
		if(buf.type == QUIT_S)
		{
			break;
		}
	}
}

int pool_add_task(void *(*process)(void *), void *confd)
{
	Thread_worker *new = NULL;
	creat_memory((void **)&new, sizeof(Thread_worker));
	new->usrFun = process;
	new->confd = confd;
	
	pthread_mutex_lock(&pool->queue_lock);
	Thread_worker *member = pool->queue_head;
	if(member != NULL)
	{
		while(member->next != NULL)
		{
			member = member->next;
		}
		member->next = new;
	}
	else
	{
		pool->queue_head = new;
	}
	pool->cur_queue_size++;
	pthread_mutex_unlock(&pool->queue_lock);
	pthread_cond_signal(&pool->queue_ready);
}

int pool_destroy()
{
	if(pool->shutdown == 1)
	{
		return -1;
	}
	pool->shutdown =1;
	pthread_cond_broadcast(&pool->queue_ready);
	int i;
	for(i < 0; i < 10; i++)
	{
		pthread_join(pool->threadid[i], NULL);
	}
	free(pool->threadid);
	Thread_worker *head = NULL;
	while(pool->queue_head != NULL)
	{
		head = pool->queue_head;
		pool->queue_head = pool->queue_head->next;
		free(head);
	}
	pthread_mutex_destroy(&pool->queue_lock);
	pthread_cond_destroy(&pool->queue_ready);
	free(pool);
	pool = NULL;
	return 0;
}
