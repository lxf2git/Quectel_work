#include"apue.h"

pUser pHead=NULL;

/*
*线程池里所有运行和等待的任务都是一个Thread_worker
*由于所有任务都在链表里
，所以是一个链表结构
*/
typedef struct worker
{
    /*回调函数，任务运行时会调用此函数，注意也可声明成其它形式*/
    void *(*process) (void *arg);
    void *arg;/*回调函数的参数*/
    struct worker *next;

} Thread_worker;


/*线程池结构*/
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


int pool_add_worker (void *(*process) (void *arg), void *arg);
void *thread_routine (void *arg);


static Thread_pool *pool = NULL;
void   pool_init (int max_thread_num)
{
     pool = (Thread_pool *) malloc (sizeof (Thread_pool));
     pthread_mutex_init (&(pool->queue_lock), NULL);
     pthread_cond_init (&(pool->queue_ready), NULL);

     pool->queue_head = NULL;

     pool->max_thread_num = max_thread_num;
     pool->cur_queue_size = 0;

     pool->shutdown = 0;

     pool->threadid =(pthread_t *) malloc (max_thread_num * sizeof (pthread_t));
    int i = 0;
    for (i = 0; i < max_thread_num; i++)
     { 
         pthread_create (&(pool->threadid[i]), NULL, thread_routine,NULL);
     }
}


/*向线程池中加入任务*/
int pool_add_worker (void *(*process) (void *arg), void *arg)
{
//	printf("arg1:%d\n",(int *)arg);
    /*构造一个新任务*/
     Thread_worker *newworker =(Thread_worker *) malloc (sizeof (Thread_worker));
     newworker->process = process;
     newworker->arg = arg;
     newworker->next = NULL;

     pthread_mutex_lock (&(pool->queue_lock));
    /*将任务加入到等待队列中*/
     Thread_worker *member = pool->queue_head;
if (member != NULL)
     {
        while (member->next != NULL)
             member = member->next;
         member->next = newworker;
     }
    else
     {
         pool->queue_head = newworker;
     }

     assert (pool->queue_head != NULL);

     pool->cur_queue_size++;
     pthread_mutex_unlock (&(pool->queue_lock));
    //唤醒一个等待线程 如果所有线程都在忙碌，这句没有任何作用
     pthread_cond_signal (&(pool->queue_ready));
    return 0;
}


/*销毁线程池，等待队列中的任务不会再被执行，但是正在运行的线程会一直
把任务运行完后再退出*/
int pool_destroy ()
{
    if (pool->shutdown)
        return -1;/*防止两次调用*/
     pool->shutdown = 1;

    //唤醒所有等待线程，线程池要销毁
     pthread_cond_broadcast (&(pool->queue_ready));

    /*阻塞等待线程退出，否则就成僵尸了*/
    int i;
    for (i = 0; i < pool->max_thread_num; i++)
    { 
		pthread_join (pool->threadid[i], NULL);
	}
     free (pool->threadid);

    /*销毁等待队列*/
     Thread_worker *head = NULL;
    while (pool->queue_head != NULL)
     {
         head = pool->queue_head;
         pool->queue_head = pool->queue_head->next;
         free (head);
     }
    /*条件变量和互斥量也别忘了销毁*/
     pthread_mutex_destroy(&(pool->queue_lock));
     pthread_cond_destroy(&(pool->queue_ready));
    
     free (pool);
    /*销毁后指针置空是个好习惯*/
     pool=NULL;
    return 0;
}


void *thread_routine (void *arg)
{
	//printf("arg:%d\n",(int * )arg); 
   // printf ("starting thread 0x%x\n", pthread_self ());
    while (1)
     {
         pthread_mutex_lock (&(pool->queue_lock));
        //如果等待队列为0并且不销毁线程池，则处于阻塞状态
        while (pool->cur_queue_size == 0 && !pool->shutdown)
         {
         //    printf ("thread 0x%x is waiting\n", pthread_self ());
             pthread_cond_wait (&(pool->queue_ready), &(pool->queue_lock));
         }

        //线程池销毁
        if (pool->shutdown)
         {
             pthread_mutex_unlock (&(pool->queue_lock));
         //    printf ("thread 0x%x will exit\n", pthread_self ());
             pthread_exit (NULL);
         }

        // printf ("thread 0x%x is starting to work\n", pthread_self ());

        //assert--调试用
         assert (pool->cur_queue_size != 0);
         assert (pool->queue_head != NULL);
        
        //等待队列长度减去1，并取出链表中的头元素
         pool->cur_queue_size--;
         Thread_worker *worker = pool->queue_head;
         pool->queue_head = worker->next;
         pthread_mutex_unlock (&(pool->queue_lock));

        /*调用回调函数，执行任务*/
         (*(worker->process)) (worker->arg);
         free (worker);
         worker = NULL;
     }
    
     pthread_exit (NULL);
}

   
void *myprocess (void *arg)
{
    // printf ("threadid is 0x%x, working on task %d\n", pthread_self (),*(int *) arg);
     int confd = *(int *)arg;
	int buf;
	struct message mess;
	mess.sockfd = confd;
	bzero(mess.userid,sizeof(mess.userid));
	bzero(mess.destid,sizeof(mess.destid));
	while(1)
	{
	read(confd,&buf,sizeof(buf));
	printf("传入buf:%d\n",buf);
	switch(buf)
	{
		case 1:
			printf("注册:%d\n",buf);
			my_register(&mess,pHead);
			printf("******\n");
			break;
		case 2: 
			printf("登录:%d\n",buf);
			log_in_id(&mess,pHead);
			printf("******\n");
			break;
		
		case 3:
			printf("id搜索:%d\n",buf);
			seek_id(&mess,pHead);
			printf("******\n");
			break;
		case 4:
			printf("name搜索:%d\n",buf);
			seek_name(&mess,pHead);
			printf("******\n");
			break;
		case 5:
			printf("关注:%d\n",buf);
			attenrion(mess,pHead);
			printf("******\n");
			break;
		case 6:
			printf("查看某人围博:%d\n",buf);
			look_self_webo(mess,pHead);
			printf("******\n");
			break;
		case 7:
			printf("查看粉丝列表:%d\n",buf);
			look_fans(&mess,pHead);
			printf("******\n");
			break;
		case 8:
			printf("查看关注列表:%d\n",buf);
			look_atten(mess,pHead);
			printf("******\n");
			break;
		case 9:
			printf("查看关注人的围博:%d\n",buf);
			look_weibo(&mess,pHead);
			printf("******\n");
			break;
		case 10:
			printf("发微博:%d\n",buf);
			send_webo(mess,pHead);
			printf("******\n");
			break;
		case 11:
			printf("查看个人信息:%d\n",buf);
			user_info(mess,pHead);
			printf("******\n");
			break;
		case 12:
			printf("取消关注:%d\n",buf);
			cancel_attenrion(&mess,pHead);
			printf("******\n");
			break;
		case 0:
			printf("return:%d\n",buf);
			printf("******\n");
    		return ;
			break;
		default:
			printf("%d\n",buf);
			break;
	}
	}
}




int  main (int argc, char **argv)
{
	init_pUser(&pHead);

	 read_head(pHead);/*加载*/

	pool_init (5);
	struct sockaddr_in selfaddr,conaddr;
	int len = sizeof(conaddr);
	int sockfd;
	int confd;
	int ret;
	char buf[1024];
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		show_err("socket");
	}
	bzero(&selfaddr,sizeof(selfaddr));
	selfaddr.sin_family = AF_INET;
	selfaddr.sin_port = htons(6666);
	selfaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	ret = bind(sockfd,(struct sockaddr *)&selfaddr,sizeof(selfaddr));
	if(ret < 0)
	{
		close(sockfd);
		show_err("bind");
	}

	ret = listen(sockfd,10);
	if(ret < 0)
	{
		close(sockfd);
		show_err("listen");
	}
	while(1)
	{
		confd =accept(sockfd,(struct sockaddr *)&conaddr,&len);
		printf("confd1:%d\n",confd);
		if(confd<0)
		{
			close(sockfd);
			show_err("accept");
		} 
		pool_add_worker (myprocess, &confd);
	
	}     
	sleep (5);

	pool_destroy ();

	return 0;
}


