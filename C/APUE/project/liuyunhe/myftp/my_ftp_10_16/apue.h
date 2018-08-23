#ifndef APUE_H
#define APUE_H

#define _XOPEN_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <dirent.h>
#include <shadow.h>
#include <unistd.h>
#include <pwd.h>
#include<time.h>
#include<setjmp.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/time.h>
#include<sys/mman.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/msg.h>
#include<sys/sem.h>
#include<arpa/inet.h>
#include<sys/socket.h>
typedef void (*sighandler_t)(int);
typedef  sighandler_t sig_t;

static show_err(char *str)
{
	perror(str);
	exit(-1);
}
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
struct ftp_ch
{
		int confd;
		char ch[100];
};
struct ftp_usr_info
{
		char ftp_usrname[30];
		char ftp_passwd[30];
};	
struct show_err
{
		int sockfd;
		struct ftp_usr_info usr_pa;
		enum cmd_type cmd;
		union ftp_arg
		{
				char ftp_ls_path[100];/*ls*/
				char ftp_get_file[100];/*get*/
				char ftp_put_file[100];/*put*/
				char ftp_cd_path[100];/*cd*/
				char ftp_mkdir_path[100];/*mkdir*/

		}ftp_arg;
};
#endif
