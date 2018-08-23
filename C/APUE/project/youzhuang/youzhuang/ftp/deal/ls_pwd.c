#include"ftp.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int ls_pwd(struct recv_to_deal recv_data, int sockfd)
{
		int i,j=0;
		char buf[1024];
		char ls_buf[1024];
		char command[256];
		bzero(command,sizeof(command));
		bzero(buf,sizeof(buf));
		bzero(ls_buf,sizeof(ls_buf));
		int fp = open(recv_data.ip,O_CREAT|O_RDWR,0666);
		if(recv_data.user.cmd == LS)
		{
				sprintf(command,"ls > %s",recv_data.ip);
				system(command);
		}
		else
		{
				sprintf(command,"pwd > %s",recv_data.ip);
				system(command);
		}
		read(fp,buf,sizeof(buf));
		char *p = strstr(buf,recv_data.ip);
		int len = strlen(recv_data.ip);
		if(p != NULL)
		{
				strcpy(p, p+len+1);
		}	
		close(fp);
		sprintf(command,"rm -rf %s",recv_data.ip);
		system(command);
		for(i=0;i<strlen(buf);i++)
		{
				if(buf[i]!='\n')
				{
						ls_buf[j]=buf[i];
				}
				else
				{
						ls_buf[j]=' ';
						j++;
						ls_buf[j]=' ';
				}
				j++;
		}
		printf("%s\n",ls_buf);
		to_client(recv_data.ip, sockfd, ls_buf, strlen(ls_buf));
		return 0;
}

int cd(struct recv_to_deal recv_data, int sockfd, int msg_id)
{
		char buf[1024];
		bzero(&buf,sizeof(buf));
		strcpy(buf,recv_data.user.farg.ftp_cd_path);
		chdir(buf);
		strcpy(buf,"目录切换成功！");
		printf("%s\n",buf);
		to_client(recv_data.ip, sockfd, buf, strlen(buf));
}

int mkdir_s(struct recv_to_deal recv_data, int sockfd, int msg_id)
{
		char buf[1024];
		bzero(&buf,sizeof(buf));
		strcpy(buf,recv_data.user.farg.ftp_mkdir_path);
		mkdir(buf,0777);
		strcpy(buf,"文件创建成功！");
		printf("%s\n",buf);
		to_client(recv_data.ip, sockfd, buf, strlen(buf));
}
