#ifndef MAIN_H
#define MAIN_H
#define suc 0
#define fail -1
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>

int getsocket(struct sockaddr_in addr, int *sockfd);//获得sockfd
//int send_information(const void *buf, int sockfd);//tcp发送
int receive_information(void *buf, int sockfd);//tcp接收
int login();//登录
int judge_login(char *user, char *pwd);//登录判断
int receive_course(void *buf);//进程接收
int send_course(void *buf);//进程发送
//int put_client(int sockfd);//客户端 put
//int get_client(int sockfd);//客户端 get
int other_command_client(int sockfd);//客户端 其他命令
int put_server(int sockfd);//服务器put
int get_server(int sockfd);//服务器 get
int other_command_server(int sockfd);//服务器 其他命令

struct ftp_usr_info 		//登录信息
{
	char ftp_usrname[30];
	char ftp_passwd[30];		
};
enum cmd_type  //消息类型
{
	LOGIN = 1,
	LS,
	PUT,
	GET,
	CD,
	PWD,
	MKDIR,
	QUIT		
};

struct cli_to_ser	//	客户端发送内容
{
	enum cmd_type cmd;//	消息类型

	union ftp_arg  // 消息内容
	{
		struct ftp_usr_info fui;//LOGIN
		char ftp_get_file[100];//get
		char ftp_put_file[100];//put
		char ftp_cd_path[100];//cd
		char ftp_mkdir_path[100];//mkdir
	}farg;	
};



struct recv_to_deal  //进程传送结构题
{
	struct cli_to_ser user;  //用户
	struct sockaddr_in addr;//ip		
};


#endif

