
#ifndef _STRUTCT_H_
#define _STRUTCT_H_
#define NAME_SIZE 20
#define PARTNER_SIZE 20
#define PASSWD_SIZE 10
#define TELE_SIZE 12
#define BIRTH_SIZE 11
typedef struct//该结构体存储在文件里
{
		int id;
		char virtual_name[NAME_SIZE];
		char passwd[PASSWD_SIZE];
		int age;
		char vip;//1表示vip 0表示非vip
		char real_name[NAME_SIZE];
		char birthday[BIRTH_SIZE];
		char telephone_num[TELE_SIZE];
		int for_passwd;
		int partner[PARTNER_SIZE];
		char gender[4];
}creat_data;
jmp_buf FLAG;
struct list_friend
{
	char is_on;
	int id;
	char virtual_name[NAME_SIZE];
};

struct client_myinfo
{
	int id;
	char virtual_name[NAME_SIZE];
	char birthday[BIRTH_SIZE];
	char telephone_num[TELE_SIZE];
	char gender[4];
	char vip;
	char real_name[NAME_SIZE];
	int age;
};
struct client_friends
{
		int id;
		char virtual_name[NAME_SIZE];
		char birthday[BIRTH_SIZE];
		char telephone_num[TELE_SIZE];

};
struct client_login
{
		int id;
		char passwd[PASSWD_SIZE];
};
struct client_apply
{
		char virtual_name[NAME_SIZE];
		char passwd[PASSWD_SIZE];
		char real_name[NAME_SIZE];
		char telephone[TELE_SIZE];
		char birthday[BIRTH_SIZE];
		int age;
		int for_passwd;
		char gender[4];
};
struct to_udp
{
	int flag;
	int id;
	char virtual_name[NAME_SIZE];
	struct sockaddr_in conaddr;
};
struct client_found
{
		int id;
		char real_name[NAME_SIZE];
		char telephone[TELE_SIZE];
		int for_passwd;
};
typedef struct
{
		int flag;//登录、退出、注册
		//creat_data user_info;//传过来的信息
		union
		{
			struct client_login login_info;
			struct client_apply apply_info;
			struct client_found found_info;
		};
}main_tran;

main_tran message;
struct client_apply apply;
struct client_myinfo myinfo;
creat_data data;
struct list_friend lsfd;
struct to_udp sudp;
static char puf[2]={0},buf[30]={0};
static int a,m,i=0;
struct sockaddr_in selfaddr,tmpaddr,conaddr;
struct sockaddr_in seraddr;
int sockfd;

int sockfdu;
static socklen_t len;
static char tm[1024]={0};
int ret,n;

#if 0
typedef struct	exist_chain//当前q存在链表的信息
{
		int confd;
		struct sockaddr_in conaddr;
		creat_data data;
		struct exist_chain *next;
}chain,*pchain;
//线程池相关
typedef struct worker
{
		void *(*process)(void*arg);
		void *arg;/*回调函数的参数*/
		struct worker *next;
}Thread_worker;
typedef struct
{
		pthread_mutex_t queue_lock;
		pthread_cond_t queue_ready;
		/*链表结构，线程池中所有等待任务*/
		Thread_worker *queue_head;
		/*是否销毁线程池*/
		int shutdown;
		pthread_t *threadid;
		/*线程池中允许的活动线程项目*/
		int max_thread_num;
		/*当前等待队列的任务数目*/
		int cur_queue_size;
}Thread_pool;

#endif
#endif

