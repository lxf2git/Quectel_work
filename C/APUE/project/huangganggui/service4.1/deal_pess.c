#include "function.h"

pData pHead;
void pool_init (int max_thread_num)
{

    /*  创建在线链表头节点  */
    pOnlineUser pOnlineHead = NULL;
    create_memory((void **)&pOnlineHead,sizeof(sOnlineUser));
    init_online_node(pOnlineHead);

    printf("pHead:%p\n",pOnlineHead);
    printf("pHead->next:%p\n",pOnlineHead->next);
    
    read_all_user(pOnlineHead, "./userinfo");
    show_all_user(pOnlineHead);


    pool = (Thread_pool *) malloc (sizeof (Thread_pool));
    pthread_mutex_init (&(pool->queue_lock), NULL);
    pool->pHead  =  pHead;


    pool->max_thread_num = max_thread_num;


    pool->threadid =(pthread_t *) malloc (max_thread_num * sizeof (pthread_t));
    int i = 0;
    for (i = 0; i < max_thread_num; i++)
    { 
        pthread_create (&(pool->threadid[i]), NULL, thread_routine,(void*)pOnlineHead);
    }
}

void read_all_user(pOnlineUser const pHead, const char *pathname)
{
    pOnlineUser pNew = NULL;
    int fd, ret;
    fd = open(pathname, O_RDONLY|O_CREAT, 0777);
    if (fd < 0)
    {
        perror("open");
        exit(-1);
    }

    while(1)
    {
        create_memory((void **)&pNew ,sizeof(sOnlineUser));
        ret = read(fd, pNew, sizeof(sOnlineUser));
        if(ret < 0)
        {
            perror("read");
            exit(-1);
        }else if(0 == ret)
        {   
            free_memory((void **)&pNew );
            printf("All user has been read.\n");
            break;
        }else
        {
            init_online_node(pNew);
            printf("insertting %s\n", pNew->userId);

            pNew->state = OFFLINE;              // 设置状态为离线      
            bzero(pNew->userIp,USERIPSIZE);     // 清空ip信息

            insert_user_to_chain(pHead, pNew);

        }
    }

    close(fd);

    
    
}

void *thread_routine (void *pOnlineHead)
{
    
	 pData pTemp;
     printf ("生成线程函数0x%x\n", pthread_self ());
    while (1)
     {
        pthread_mutex_lock (&(pool->queue_lock));
     printf ("正在工作的线程函数0x%x\n", pthread_self ());
        while(1)
        {
            pTemp = read_chain();
            if (END == pTemp->buf.mode)
            {
                free(pTemp);
                continue;
            }
            else
                break;
        }
        pthread_mutex_unlock(&(pool->queue_lock));  
        
        printf("mode:%d\n", pTemp->buf.mode);

		printf ("thread 0x%x is starting to work\n", pthread_self ());

        /*调用回调函数，执行任务*/
        
        function_of_chat(pTemp->buf, pTemp->sockfd ,(pOnlineUser)pOnlineHead);

     }
    
}
int deal_pess(int *fdPipe,struct sembuf buf,int semid)
{
		pData pTemp;
		init_chain(&pHead);
		sData_package bufData;
		pool_init(10);
		sSocks Sockfd;
		close(fdPipe[1]);
		while(1){
				int ret = read(fdPipe[0],&bufData,sizeof(bufData));
				if(ret < 0){
						perror("read_1");
						return -1;
				}

				buf.sem_op = 1;
				semop(semid,&buf,1);

				ret = read(fdPipe[0],&Sockfd,sizeof(Sockfd));
				if(ret < 0){
						perror("read_2");
						return -1;
				}
				init_chain(&pTemp);
				pTemp->buf = bufData;
				pTemp->sockfd = Sockfd;
				insert_chain(pTemp);
                show_chain();
		}
}


int init_chain(pData *p)
{
		*p = malloc(sizeof(sData));
		if(*p == NULL){
				perror("malloc");
				exit(-1);
		}
		(*p)->next = (*p);
		(*p)->prev = (*p);
}

int insert_chain(pData pnew)
{
        printf("insert chain\n");
		pnew->prev = pHead->prev;
		pHead->prev->next = pnew;
		pHead->prev = pnew;
		pnew->next = pHead;
        printf("insert successfully\n");
}

pData read_chain()
{
		pData pnew = pHead->next;
        
		while(pnew != pHead)
        {
        printf("read\n");
				pnew->prev->next = pnew->next;
				pnew->next->prev = pnew->prev;
                printf("read mode :%d\n",pnew->buf.mode);
				return pnew;
		}

		init_chain(&pnew);
		pnew->buf.mode = END;
		return pnew;
		
}
void show_chain()
{
		pData pnew = pHead->next;
		while(pnew != pHead)
        {
            printf("mode :%d\n",pnew->buf.mode);
            pnew = pnew->next;
		}
        printf("_________________________END\n");
}


