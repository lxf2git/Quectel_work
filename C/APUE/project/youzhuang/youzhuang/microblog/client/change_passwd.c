#include"apue.h"
#include"microblog.h"

void change_passwd(SUer_basic_info *data,int sockfd)
{
	int Ture;
	char *passwd = NULL;
	char *passwd1 = NULL;
	char *passwd2 = NULL;
	int i;
	write(sockfd,data->s_user_name,sizeof(data->s_user_name));
	while(1)
	{
		passwd = getpass("                                     密码:");
		write(sockfd,passwd,strlen(passwd)+1);
		read(sockfd,&Ture,sizeof(int));
		if(Ture == 0)
		{
			while(1)
			{
				passwd1=getpass("                                     新密码:");
				passwd = (char *)malloc(20*sizeof(char));
				bzero(passwd,20*sizeof(char));
				for(i=0;i<strlen(passwd1);i++)
				{   
					*(passwd+i) = *(passwd1+i);
				}
				passwd2=getpass("                                     确认新密码:");
				if(strcmp(passwd,passwd2) == 0)
				{
					write(sockfd,passwd,strlen(passwd)+1);
					read(sockfd,&Ture,sizeof(Ture));
					if(Ture == 0)
					{
						space();
						printf("修改成功\n");
						return;
					}
					else
					{
						space();
						printf("修改失败\n");
						return;
					}
				}
				else
				{
					space();
					printf("密码不一致\n");
					continue;
				}	
			}
		}
		else
		{
			space();
			printf("密码不正确\n");
			break;
		}
	}
}
