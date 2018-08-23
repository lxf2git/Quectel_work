#ifndef _SER_GLO_H_
#define _SER_GLO_H_
int sockfd;//链表及连接相关
socklen_t len;
struct sockaddr_in selfaddr;
void show_err(char*);
void set_err(int,char*);
void *con_in();
void init_chain(pchain *);
void destroy_node(pchain);
void add_to_chain(pchain);
pchain phead;
pchain find_addr(int);
pchain find_now(int);

//pool
int pool_add_worker(void *(*process)(void *arg),void *arg);
void *thread_routine(void *arg);
static Thread_pool *pool=NULL;
void pool_init(int);
void *myprocess(void*);
int pool_destroy();

//监视文件描述符
struct epoll_event event;
int epfd;
void *deal_command(void *);

void *server_command();
#endif
