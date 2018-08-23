#include "ftp.h"

int login(int sockfd)
{
		int ret,verify;//认证
		struct cli_to_ser data;
		struct ftp_user_info user;
		char username[50];
		char passwd[50];
		printf("请输入用户名\n");
		scanf("%s",user.ftp_username);
		printf("请输入密码\n");
		scanf("%s",user.ftp_passwd);
		data.farg.fui = user;
		data.cmd = LOGIN;
		ret = send_information(&data,sockfd);
		if(ret < 0)
		{
				perror("send_information");
				return FAIL;
		}
		ret = receive_information(&verify,sockfd);
		if(ret < 0)
		{
				perror("receive_information");
				return FAIL;
		}
		return SUC;
}
