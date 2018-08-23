		开发文档

一 项目名称 ：12306票务系统

二项目功能：
实现一个火车票订票系统
用户登录 注册
列车时刻查询
余票查询
买票
订单功能
退票功能

三 思路：
	1 采用C/S架构，服务器采用多线程工作，服务器与客户端通过UDP协议互相通信。
	2 服务器启动后，绑定端口创建线程池，等待客户端发送请求。 客户端启动后，根据菜单选项 发送请求命令（用户登录 注册 列车查询 余票查询 订单 等）.
	3 服务器收到请求后，添加到任务队列中，激活线程池，调用相应的处理函数，包括通过调用数据库，匹配数据库后 得到结果通过UDP协议返还给客户端，同时数据库更新
	  任务完成后，回到线程池等待下一个任务的激活。
	4 服务器关闭时，会销毁线程池释放内存。
四 分工：
	客户端：祁路方
	服务器：陆剑（架构服务器创建线程池） 胡鑫（处理命令请求） 陈宇鸣 （数据库处理）
五 结构体：


//命令枚举
enum CMD_VALUE{
	REGISTER,	//注册
	REG_ERR,	//注册失败
	LOGIN,		//登录
	LOG_ERR,	//登录失败
	QUE_TKT,	//查询票
	QUE_ERR,	//查询失败
	QUE_ORDER,	//查询订单
	QUE_OVER,	//查询信息发送结束
	ORD_TKT,	//订票
	ORD_ERR,	//订票失败
	CHA_TKT,	//改签
	CHA_ERR,	//改签失败
	BACK_TKT       	//退票
};


客户端：

//flag标志
enum FLAG_VALUE{
	LOG_UNSUC,
	LOG_SUC,
};

//用户信息
struct user_info{
	char username[30];
	char userpasswd[20];
};

//用户请求详细信息
union user_req{
	char que_buf[1024];
	char ord_num[1024];

};

//客户端发送的包

struct cli_ser_pakg{
	int cmd;			//命令
	int flag;			//标志（成功未成功）
	struct user_info user;	        //用户信息
	union user_req req;		//用户请求（目的地,车次）
};


服务器：

//服务器收到数据包后封装给线程

struct ser_deal_pakg{
	struct cli_ser_pakg recv_pakg;
	struct sockaddr_in cli_ip;
	int sockfd;
};

//发回给客户端的数据buf
union deal_ret{
	char reg_buf[1024];	//注册，登录buf
	char ord_buf[1024];	//订票buf
	char cha_buf[1024];	//改签buf
	char que_buf[1024];	//查询buf
	char back_buf[1024];    //退票buf
};

//服务器发给客户端的包
struct ser_cli_pakg{
	int cmd;
	int flag;
	union deal_ret ret;  
};

线程池：

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

}Squeue, *Pque

数据库：

struct db_user{
	char name[30];
	char passwd[20];
	unsigned long index;
};

struct db_user_info{
	char train[10];
	unsigned long next_index;
};

typedef struct db_fd{
	FILE *db_train_po;
	int db_index_fd;
	int db_data_fd;
}DB;





