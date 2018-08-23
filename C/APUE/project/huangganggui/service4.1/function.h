#ifndef _FUNCTION_H
#define _FUNCTION_H

#define FRIENDLISTSIZE  124 /*  最大好友数  */

#define USERIDSIZE    10    /*  用户名长度  */
#define PASSWDSIZE    10    /*  密码长度  */
#define USERIPSIZE    20    /*  IP长度  */
#define FILENAMESIZE 200

#define VIP     1
#define NOTVIP  0

#define ONLINE 1
#define OFFLINE 0

#include "./apue.h"


typedef struct OnlineUser     //在线用户列表
{
    char userId[USERIDSIZE];    /*  用户名  */
    char passwd[PASSWDSIZE];    /*  密码  */
    char userIp[USERIPSIZE];
    
    char vip;           /*  是否为VIP  */
    long balance;       /*  余额  */
    char state;      /*  状态 ：在线、离线*/    
    

    struct OnlineUser *prev;
    struct OnlineUser *next;

}sOnlineUser, *pOnlineUser;




typedef struct UserInformation
{
    char userId[USERIDSIZE];    /*  用户名  */
    char passwd[PASSWDSIZE];    /*  密码  */
    char vip;           /*  是否为VIP  */
    long balance;       /*  余额  */

}sUserInfo, *pUserInfo;

union dataOrinformation
{
    char data[200];
    struct UserInformation loginInformation;

};

typedef struct Data
{
    int  mode;                              //数据类型
    char destAddr[USERIPSIZE];                      //目的地址   
    char sourceAddr[USERIPSIZE];                    //源地址

    char dest_user[USERIDSIZE];                     //目的用户
    char src_user[USERIDSIZE];                      //源用户

    char fileName[FILENAMESIZE];                      //文件名
    char time[30];                          //当前时间
    struct timeval vtime;                   //微妙毫秒
    union dataOrinformation dorinform;      //数据或者信息

    struct data *next;
    struct data *prev;


}sData_package, *pData_package;

typedef struct user_chain
{
    char user_id[USERIDSIZE];
    char user_ip[USERIPSIZE];
    struct user_chain *next;
    struct user_chain *prev;
}sUser,*pUser;

typedef struct 
{
    int sockfd_send;
    int sockfd_recv;
    int sockfd_chec;
    int sockfd_rech;

    socklen_t len;

//    int len = sizeof(struct sockaddr_in);
    struct sockaddr_in paddr_send;      //服务器向客户端发送消息
    struct sockaddr_in paddr_send_n;

    struct sockaddr_in paddr_recv;      //服务器接客户端消息
    struct sockaddr_in paddr_recv_n;

    struct sockaddr_in paddr_chec;      //接客户端向服务器发送的认证
    struct sockaddr_in paddr_chec_n;

    struct sockaddr_in paddr_rech;      //服务器返回客户端请求
    struct sockaddr_in paddr_rech_n;
}sSocks;
#if 0
enum
{
    LOGIN,          //登入
    REGISTER,       //注册
    ADDFRIEND,      //请求添加好友
    DELFRIEND,      //删除好友
    FILE_REQUES,    //文件请求
    TELL_REQUES,    //谈话请求
    REQUES_EXIT,    //请求结束
    LOGINERROR,     //登录失败
    LOGINSUCCEED,   //登录成功
    REGISTERERROR,  //注册失败
    REGISTERSUCCEED,//注册成功
    LEAVE,          //下线通知
    CHECK,          //检测
    FRIENDRE,       //好友回应
    FRIENDLIST,     //开始发送好友ip
    END,            //最后一个
};  
#endif

enum
{
        LOGIN,          //登入       0
        REGISTER,       //注册       1
        ADDFRIEND,      //添加好友    2
        DELFRIEND,      //删除好友    3

        ADDVIP,         //VIP       4
        ADDBALANCD,     //充值       5
        SERVICE_REPLY,  //服务器答复  6

        TELLS_INVITE,   //群聊邀请   7
        TELLS_REPLY,    //群聊答复   8
        FILE_REQUES,    //文件请求   9
        TELL_REQUES,    //谈话请求   10
        REQUES_EXIT,    //请求结束   11

        LOGINERROR,     //登录失败   12
        LOGINSUCCEED,   //登录成功   13
        REGISTERERROR,  //注册失败   14
        REGISTERSUCCEED,//注册成功   15
        LEAVE,          //下线通知   16

        CHECK,          //检测      17 
        FRIENDRE,       //好友回应   18
        FRIENDLIST,     //好友链表   19
        HEAD,


        END             //最后一个
};

int function_of_chat(sData_package data,sSocks socket_structure,pOnlineUser pHeadOnline);


int register_account(sData_package data, sSocks socket_structure, pOnlineUser pHeadOnline);
void create_file_systerm(pOnlineUser pNode);
pOnlineUser search_user_by_id(pOnlineUser pHead, char *userId);
void send_info_to_client(sData_package data, sSocks socket_structure);
void create_memory(void **p, int size);
void free_memory(void **p);
void init_online_node(pOnlineUser pNode);

int login_account( sData_package data, sSocks socket_structure,pOnlineUser pHeadOnline);
void send_friendList(sData_package data, sSocks socket_structure, pOnlineUser pOnlineHead);
void send_leaveRecord(sData_package data, sSocks socket_structure, pOnlineUser pOnlineHead);


int logout( sData_package data, sSocks socket_structure,pOnlineUser pHeadOnline);
void insert_online_user_to_chain(pOnlineUser pHead, pOnlineUser pNew);
int show_all_user(pOnlineUser pHead);
void read_all_user(pOnlineUser const pHead, const char *pathname);
void write_all_user(const pOnlineUser pHead, const char *pathname);
void insert_user_to_chain(pOnlineUser pHead, pOnlineUser pNew);
void distory_chain(pOnlineUser pHead);

int add_friend( sData_package data,sSocks socket_structure,pOnlineUser pHeadOnline);
int add_friend_reply(sData_package data, sSocks socket_structure,pOnlineUser pHeadOnline);

int del_friend( sData_package data,sSocks socket_structure,pOnlineUser pHeadOnline);


int retransmission(sData_package bufData,sSocks Sockfd,pOnlineUser pHeadOnline);//转发

typedef void (*sighandler_t)(int);
typedef sighandler_t sig_t;

typedef struct fun_chain
{
		struct Data buf;
		sSocks sockfd;
		struct fun_chain *next;
		struct fun_chain *prev;
}sData,*pData;


typedef struct
{
     pthread_mutex_t queue_lock;
     pthread_cond_t queue_ready;

    /*链表结构，线程池中所有等待任务*/
     pData pHead;

    /*是否销毁线程池*/
    int shutdown;
     pthread_t *threadid;
    /*线程池中允许的活动线程数目*/
    int max_thread_num;
    /*当前等待队列的任务数目*/
    int cur_queue_size;

} Thread_pool;

pData read_chain();
int insert_chain(pData pnew);
int init_chain(pData *p);
void *thread_routine (void *arg);

void show_chain();
static Thread_pool *pool = NULL;

#endif

