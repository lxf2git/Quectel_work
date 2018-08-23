#ifndef STRUCT_H
#define STRUCT_H

#define SER_PORT 2333
#define ARG_SIZE 100
#define DATA_SIZE 1024
#define FAILED  -1
#define SUCCESS 1
enum cmd_type	//功能枚举
{
	LOGIN,
	LS,
	GET,
	PUT,
	CD,
	PWD,
	MKDIR,
	QUIT
};
struct ftp_usr_info 	//用户信息
{
	char ftp_usrname[32];
	char ftp_passwd[32];
};
union ftp_arg	//参数
{
	struct ftp_usr_info usr;
	char ftp_ls_path[100];
	char ftp_get_file[100];
	char ftp_put_file[100];
	char ftp_cd_path[100];
	char ftp_mkdir_path[100];
};

struct cli_to_ser	//客户to 服务
{
	enum cmd_type cmd;
	union ftp_arg arg;
};

struct ser_to_cli   //服务到客户
{
	enum cmd_type cmd;
	int ret;
	char ftp_data[DATA_SIZE+1];
	//待定
};

typedef struct LoginInformation //用户登录链表
{
		struct sockaddr_in savaddr;
		struct LoginInformation *prev;
		struct LoginInformation *next;

}sLogin,*pLogin;

typedef struct msg   //消息队列
{
		long type;
		struct cli_to_ser cli_to_ser;
}Msg;

struct recv_to_deal //recv to deal
{
		struct cli_to_ser cli_to_ser;
		struct sockaddr_in sockaddr;
};
#endif
