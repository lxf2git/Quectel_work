#include "ftp.h"

int login()
{
		int i=0;
		int ret,verify = 10;//认证
		struct cli_to_ser data;
		struct ftp_user_info user;
		char username[50];
		char *passwd;
		printf("请输入用户名\n");
		scanf("%s",user.ftp_username);
		getchar();
		passwd= getpass("请输入密码:");
		strcpy(user.ftp_passwd,passwd);
		data.farg.fui = user;
		data.cmd = LOGIN;
		ret = send_information(&data);
		if(ret < 0)
		{
				perror("send_information");
				return FAIL;
		}
		receive_information(&verify);
		if(verify < 0)
		{
				printf("帐号密码错误!\n");
				return FAIL;
		}
		return SUC;
}
