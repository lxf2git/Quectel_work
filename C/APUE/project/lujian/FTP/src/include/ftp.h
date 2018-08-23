#ifndef _FTP_H_
#define _FTP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include "list.h"
#include <errno.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#define _XOPEN_SOURCE
#include <shadow.h>
#include <crypt.h>
#include <unistd.h>

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
	PUT_CONT,
	PUT_OVER,
	GET,
	GET_CONT,
	GET_OVER,
	CD,
	PWD,
	MKDIR,
	QUIT,
	OVER
};

//客户端命令参数共用体
union cli_argv{
	char file_get[50];
	char file_put[50];
	char path_cd[50];
	char path_mkdir[50];
	char path_ls[50];
	char path_quit[50];
	char path_pwd[50];
};

//客户端发给服务器的结构体
struct cli_ser_pakg{
	struct user_msg cli_info;
	char cmd;
	union cli_argv argv;
};

//服务器用户链表保存的结构体
struct list_info{
	struct user_msg user_info;
	struct sockaddr_in cli_ip;
	int fifo_fd;
	time_t time;
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


struct user_list_num{
	struct list_info user;
	struct list _list;
};

extern struct list user_list_head;
extern int logfd;
#endif
