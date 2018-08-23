#ifndef _FTP_H_
#define _FTP_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<arpa/inet.h>
#define FAIL -1
#define SUC 0
struct ftp_user_info
{
		char ftp_username[30];
		char ftp_passwd[30];
};
enum cmd_type{ LOGIN = 1, LS, PUT, GET, CD, PWD, MKDIR, QUIT };
struct cli_to_ser
{
		enum cmd_type cmd;
		union ftp_arg
		{
				struct ftp_user_info fui;
				char ftp_get_file[100];
				char ftp_put_file[100];
				char ftp_cd_path[100];
				char ftp_mkdir_path[100];
				char ftp_ls_path[100];
				char ftp_cmd_path[100];
		}farg;
};
struct recv_to_deal
{
		struct cli_to_ser user;
		char ip[20];
};
typedef struct msg
{
		int type;
		struct recv_to_deal data;
}Msg;
typedef struct ip_pid
{
		char ip[20];
		int pid;
		struct ip_pid *next;
		struct ip_pid *prev;
}Sip_pid, Pip_pid;


int send_to_deal(char *src_ip, struct recv_to_deal data, int msg_id);
int recevie_course(int type, struct recv_to_deal *data, int *msg_id);
int send_course(int type, struct recv_to_deal data, int msg_id);
int getsocket(struct sockaddr_in *selfaddr, int *sockfd);
int login(int sockfd);
int judge_login(char *user, char *pwd);
int put_client(char *command, int sockfd);
int get_client(char *command, int sockfd);
int other_command_client(char *command,int sockfd);
int put_server(int sockfd);
int get_server(int sockfd);
int other_command_server(int sockfd);
int send_information(void *buf, int socked);
int receive_information(void *buf, int socked);
#endif
