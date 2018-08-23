#ifndef CLIENT_H
#define CLIENT_H
#include "/apue.h"
#include <errno.h>
#include <sys/time.h>
#include <setjmp.h>
#include <semaphore.h>
#define NONE "\e[0m"   //无色
#define RED "\e[40;31m"//黑第红
#define GRE "\e[40;32m"//黑第绿
#define YEL "\e[40;33m"//黄
#define WIT "\e[40;37m"//白
#define PRO "\e[40;35m"//紫
#define SERVIC_PORT 7563
#define CLIENT_PORT 8888
#define RECV_CHECK 6563
#define SEND_CHECK 7777
#define SERVICE_IP "192.168.1.43"
#define USER_NUMBER 10
#define PASS_NUMBER 10
#define MYDIR "/USERS"
struct UserInformation
{
		char userId[USER_NUMBER];           //用户
		char passwd[PASS_NUMBER];			//密码
		char vip;							//vip
		long balance;						//余额
};
union dataOrinformation
{
		char data[200];
		struct UserInformation loginInformation;
};



typedef struct Data
{
		int  mode;		//数据类型
		char destAddr[20]; 						//目的地址
		char sourceAddr[20];					//源地址
		char dest_user[USER_NUMBER];
		char src_user[USER_NUMBER];
		char fileName[200];
		char time[30];
		struct timeval vtime;					//微妙毫秒
		union dataOrinformation dorinform;		//数据或者信息
		int number;

		struct data *next;
		struct data *prev;


}sData_package,*pData_package;

enum
{
		LOGIN,          //登入0
		REGISTER,       //注册1
		ADDFRIEND,      //添加好友2
		DELFRIEND,		//删除好友3
		ADDVIP,			//VIP4
		ADDBALANCD,		//充值5
		SERVICE_REPLY,	//服务器答复6
		TELLS_INVITE,	//群聊邀请7
		TELLS_REPLY,	//群聊答复8
		FILE_REQUES,    //文件请求9
		TELL_REQUES,    //谈话请求10
		REQUES_EXIT,    //请求结束11
		LOGINERROR,     //登录失败12
		LOGINSUCCEED,   //登录成功13
		REGISTERERROR,  //注册失败14
		REGISTERSUCCEED,//注册成功15
		LEAVE,			//下线通知16
		CHECK,			//检测17
		FRIENDRE,		//好友回应18
		FRIENDLIST,		//好友链表19
		HEAD,
		FRENDCIRCLE_SEND,//发送朋友圈20
		FRENDCIRCLE_LOOK,//查看朋友圈21
		ONLINE,          //上线
		HIDE,			
		DISK_SEND,      //上传
		DISK_RECV,		//下载
		NEARBY,			//附近的人
		END			    //最后一个
};
typedef struct Socks
{
		int sockfd_send;                  //发送套接子
		int sockfd_recv;					//接受
		int send_check;						//发送检验
		int recv_check;						//接受校验
		struct sockaddr_in addr_send;		//发送地址
		struct sockaddr_in addr_recv;		//接送地址
		struct sockaddr_in addr_Schec;		//发送检验地址
		struct sockaddr_in addr_Rchec;		//接受检验地址
}Socks,*psock;
/*发送队列结构体*/
typedef struct data_chain
{
		sData_package data;				//等待处理数据
		pthread_t id;                    //线程id
		struct data_chain *next;		
		struct data_chain *prev;

} Thread_Data;

int login_menu();
int Send_fun(const pData_package package,const struct sockaddr_in *paddr,int sockfd);
sData_package Recv_fun(struct sockaddr_in *paddr,int rockfd);
/*初始化函数*/
int initSockfd_Serive(struct sockaddr_in *psaddr);
int initSockfd_Client(struct sockaddr_in *praddr);
int inintSend_Check(struct sockaddr_in *pcaddr);
int inintRecv_Check(struct sockaddr_in *pcaddr);
sData_package init_login(char*name,char *);
sData_package init_register(char*name,char*);
sData_package init_addfriend(char*name,char*);
sData_package init_file(char *buf_file,char*);
sData_package init_tell(char *buf_tell,char*);
int dir_init(char *path);
//////////////////////////////////////////////

//void * create_send(void* pHead);
void * Send_choose(void *pHead);
Thread_Data * read_Data(Thread_Data *pHead);       //从链表中读取数据。
void * Send_main(void *pSocks);
int SendToService(Socks Socks,sData_package data);			//发送到服务端
void * Recv_main(void *pSocks);
void * Recv_choose(void* pHead);
int Recv_addfriend(sData_package package,Socks Socks);
int Recv_file(sData_package package,Socks Socks);
int Recv_tell(sData_package package,Socks Socks);
int Recv_list(sData_package package,Socks Socks);
int Recv_service(sData_package package,Socks Socks);
int Recv_del(sData_package package,Socks Socks);
int Recv_exit(sData_package package,Socks Socks);
int Recv_head(sData_package package,Socks Socks);
sData_package login_fun(Socks Socks);
sData_package register_fun(Socks Socks);
Thread_Data * send_addfriend(int mode,char* destAddr,char* dest_user);
Thread_Data * send_file(int mode,char* destAddr,char* dest_user);
Thread_Data * send_tell(int mode,char* destAddr,char* dest_user);
Thread_Data *send_del(int mode,char*destAddr,char* dest_user);
Thread_Data *send_vip(int mode,char*destAddr,char* dest_user);
Thread_Data *send_bal(int mode,char*destAddr,char* dest_user);
Thread_Data *send_leave(int mode,char *destAddr,char* dest_user);
Thread_Data *send_tells(int mode,char *destAddr,char *dest_user);
Thread_Data * send_reply(int mode,char* destAddr,char* dest_user);
Thread_Data *send_online(int mode,char *destAddr,char *dest_user);
Thread_Data *send_hide(int mode,char *destAddr,char *dest_user);
Thread_Data *send_nearby(int mode,char *destAddr,char *dest_user);
Thread_Data *send_circleSend(int mode,char *destAddr,char *dest_user);
Thread_Data *send_circleLook(int mode,char *destAddr,char *dest_user);
Thread_Data *send_down(int mode,char *destAddr,char *dest_user);
Thread_Data *send_upload(int mode,char *destAddr,char *dest_user);
int chain_insert(Thread_Data *pHead,Thread_Data *pInsert);
int chain_init(Thread_Data **p);
void create_list(Thread_Data *pTemp);
void list_show();
sData_package list_findname(char *name);
sData_package list_del(char *name);

void my_send(int sig);
void my_login(int sig);
//void my_resigt(int sig);
void my_jmpMenu(int sig);
void my_leave(int sig);
int write_file(sData_package package);
void my_free_chain(Thread_Data *pHead);
void my_exit();
sData_package (*Sendinit[21])(char *,char*);
int free_fileName(char *fileName,Thread_Data *pHead);


int create_file_chain(Thread_Data *pHead,char *fileName);
int find_fileName(Thread_Data *pHead,char *path);
void show_chain(Thread_Data *pHead);
/*
 Sendinit[LOGIN] = init_login;
 Sendinit[REGISTER] = init_register;
 Sendintt[ADDFRIEND] = init_addfriend;
 Sendinit[FILE_REQUES] = init_file;
 Sendinit[TELL_REQUES] = init_tell;
*/
																				
static jmp_buf jmp_SendData;

#endif
