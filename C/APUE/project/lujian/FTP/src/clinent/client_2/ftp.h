#ifndef _FTP_H_
#define _FTP_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <shadow.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
void myperror(char *p)
{
		perror(p);
		exit(-1);
}

//用户信息结构体
struct user_msg{
	char username[50];
	char passwd[50];
};

//命令枚举
enum cli_cmd{
	ERR,
	LOGIN,
	LS,
	PUT,
	PUT_CONT,//
	PUT_OVER,
	GET,
	GET_CONT,//
	GET_OVER,
	CD,
	PWD,
	MKDIR,
	QUIT,
	OVER,
};

//客户端命令参数共用体
union cli_argv{
		char file_get[50];
		char file_put[50];
		char path_cd[50];
		char path_mkdir[50];
		char path_ls[50];
		char path_pwd[50];
		char path_quit[50];
};
//客户端发给服务器的结构体
struct cli_ser_pakg{
	struct user_msg cli_info;
	char cmd;	
	union cli_argv argv;
};

//服务器处理的结构体
struct ser_recv{
	struct cli_ser_pakg recv_data; 
	struct sockaddr_in cli_ip;
};

//服务器用户链表保存的结构体
struct list_info{
	struct user_msg user_info;
	struct sockaddr_in cli_ip;
	char fifo_name[1024];
//	time_t time;
};

//服务器发送给客户端的数据buf
union ser_cli_pakg{
	char file_buf[1024];
	char cmd_buf[1024];
};

//服务器发给客户端的包
struct send_pakg{
	char pakg_type;
	union ser_cli_pakg data_buf;
};


#endif
