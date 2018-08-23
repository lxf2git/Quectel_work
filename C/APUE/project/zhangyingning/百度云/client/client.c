#include"baiduy.h"

static int sockfd;
/*
 * 利用tcp进行网络连接
 * 创建网络tcp链接 
*/
int con_link(char *p)
{
		struct sockaddr_in seraddr;
		bzero(&seraddr,sizeof(seraddr));

		sockfd = socket(AF_INET,SOCK_STREAM,0);
		if(sockfd<0)
		{
				perror("socket");
				return -1;
		}
		seraddr.sin_family = AF_INET;
		seraddr.sin_port = htons(8888);
		seraddr.sin_addr.s_addr = inet_addr(p);
		if(connect(sockfd,(struct sockaddr*)&seraddr,sizeof(seraddr))<0)
		{
				return -1;
		}
		return 0;
}
/*
 *注册用户
 */
int creat_usr(pBdy per)
{
		char *passwd=NULL;
		passwd = (char *)malloc(30*sizeof(char));
		bzero(passwd,sizeof(passwd));

		per->cmd=REGISTER;
		printf("username:");
		fflush(stdout);scanf("%s",per->usrname);
		passwd = getpass("passwd:");
		strcpy(per->passwd,passwd);

//		printf("strlen:%d\n",strlen(passwd));
		bzero(passwd,strlen(passwd));
		passwd = getpass("请在次确认passwd:");

		if(strcmp(per->passwd,passwd)==0)
		{
				free(passwd);
				write(sockfd,per,sizeof(sBdy));
		}
		else
		{
				printf("两次密码不一致.\n");
				free(passwd);
				return -1;
		}
		bzero(per,sizeof(sBdy));
		read(sockfd,per,sizeof(sBdy));
		if(strncmp("register_success",per->buf,16)==0)
		{
				printf("注册成功.\n");
		}
		else
		{
				printf("该用户已经存在.\n");
		}
		return 0;
}
/*
 *登录用户
 */
int login_usr(pBdy per)
{
		char *passwd=NULL;
		passwd = (char *)malloc(30*sizeof(char));
		bzero(passwd,sizeof(passwd));

		per->cmd=LOGIN;
		printf("username:");
		fflush(stdout);scanf("%s",per->usrname);
		
		passwd = getpass("passwd:");
	
		strncpy(per->passwd,passwd,strlen(passwd));
		write(sockfd,per,sizeof(sBdy));
		usleep(10);

		read(sockfd,per,sizeof(sBdy));
		if(strncmp("login_success",per->buf,13)==0)
		{
				printf("登录成功.\n");
				return 0;
		}
		else
		{
				printf("用户名或密码错误.\n");
				return -1;
		}
		return 0;
}
/*
 *利用命令行输入链接电脑的ip地址
 *
 */
int main(int argc,char **argv)
{
		assert(argc==2);
		int ret = con_link(argv[1]);
		if(ret==-1)
		{
				printf("请检查您的网络连接是否正确.\n");
				exit(-1);
		}
		printf("欢迎使用百度云服务\n\n");
		sleep(1);					   //等待1秒，模拟载入
		sBdy cli_data;                 //建立结构体变量
		bzero(&cli_data,sizeof(sBdy)); //清空结构体
		int username_login;
		while(1)
		{
				printf("  0  用户注册 \n");
				printf("  1  用户登录 \n");
				printf("  2    退出   \n");
				scanf("%d",&username_login);
				switch(username_login)
				{
						case 0: creat_usr(&cli_data);break; 
						case 1:if(login_usr(&cli_data)==0)
							   {
									 if(op_deal(sockfd)<0)
									 {
											 break;
									 }
							   }break;
						case 2:return 0;break;
						default:printf("无效操作\n");break;
				}
		}
}
