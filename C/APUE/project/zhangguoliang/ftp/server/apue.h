#ifndef APUE_H_
#define APUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <strings.h>
#include <shadow.h>
#include <time.h>
#include <grp.h>
#include <setjmp.h>
#include <unistd.h>
#include <pwd.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <errno.h>
#define CREAT_NEW_SON 1
#define INTO_SON 0
#define OUT_SON -1
#define MAX_USR 10
#define MAX_SIZE 2048
#define COM_SIZE 100
#define USR_INFO_SIZE 30
#define EMPTY 0
#define TRUE 1
#define ZERO 0
void show_err(char *);
void set_err(int,char *);
in_addr_t now_login[MAX_USR];
int login_pid[MAX_USR];

struct ftp_usr_info
{
	char ftp_usrname[USR_INFO_SIZE];
	char ftp_passwd[USR_INFO_SIZE];
};

enum cmd_type
{
	LOGIN,
	LS,
	PUT,
	GET,
	CD,
	PWD,
	MKDIR,
	QUIT
};

struct cli_to_ser
{
	int cmd;

	union //ftp_arg
	{
		struct ftp_usr_info user_info;//LOGIN
		char ftp_ls_path[COM_SIZE];//LS
		char ftp_get_file[COM_SIZE];//GET
		char ftp_put_file[COM_SIZE];//PUT
		char ftp_cd_path[COM_SIZE];//CD
		char ftp_mkdir_path[COM_SIZE];//MKDIR
	};
};

struct recv_to_deal
{
	struct cli_to_ser to_ser;
	struct sockaddr_in conaddr;
};


typedef void (*sighandler_t)(int);
typedef sighandler_t sig_t;
int semid;
struct sembuf sem;
void recv_process(struct recv_to_deal*);
void deal_process();
int child_log(struct ftp_usr_info);
void child(struct recv_to_deal);
int fd[2];
struct recv_to_deal to_deal;
struct sockaddr_in conaddr;
int sockfd;
char buf[MAX_SIZE];
#endif

