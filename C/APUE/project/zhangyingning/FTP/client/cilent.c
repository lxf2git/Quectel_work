#include"apue.h"
//子进程收尸
void sig_fun(int sig)
{
		wait(NULL);
		exit(0);
}

int main(int argc,char **argv)
{
		if(argc!=2)
		{
				perror("no argument");
				exit(-1);
		}

		char buf[1023];
		bzero(buf,sizeof(buf));
		signal(SIGCHLD,sig_fun); 

		sF ser_nameAndpasswd;
		bzero(&ser_nameAndpasswd,sizeof(ser_nameAndpasswd));

		int sockfd = socket(AF_INET,SOCK_STREAM,0);
		if(sockfd<0)
		{
				perror("socket");
				exit(-1);
		}
		
		struct sockaddr_in seraddr;
		bzero(&seraddr,sizeof(seraddr));

		seraddr.sin_family = AF_INET;
		seraddr.sin_port = htons(8888);
		seraddr.sin_addr.s_addr = inet_addr(argv[1]);
		if(connect(sockfd,(struct sockaddr*)&seraddr,sizeof(seraddr))<0)
		{
				printf("<ftp>(%s):connect fail",argv[1]);
				exit(-1);
		}
		printf("connect success.\n");
//用户名密码
		char *tmp=NULL;
		tmp = (char*)malloc(sizeof(30));	
		bzero(tmp,sizeof(tmp));

		printf("ftp>name:");
		fflush(stdout);
		scanf("%s",ser_nameAndpasswd.ftp_usrname);
		//隐身密码
		tmp= getpass("ftp>passwd:");
		strncpy(ser_nameAndpasswd.ftp_passwd,tmp,strlen(tmp)); 
		printf("ser_nameAndpasswd.ftp_passwd:%s\n",ser_nameAndpasswd.ftp_passwd);
		free(tmp);

		write(sockfd,&ser_nameAndpasswd,sizeof(ser_nameAndpasswd));

		usleep(100);
		read(sockfd,buf,sizeof(buf));
		if(strncmp(buf,"login_success",13)!=0)
		{
				printf("username or passwd worry.\n");
				exit(-1);
		}
		int ret;
		sG_p rewr;
		bzero(&rewr,sizeof(rewr));
		pid_t pid = fork();
		if(pid<0)
		{
				close(sockfd);	 
				perror("fork");
		}
		if(pid==0)//从0---sockfd
		{

				while(1)
				{
						read(sockfd,&rewr,sizeof(rewr));
						if(strlen(rewr.file_name)!=0)
						{
								bzero(buf,sizeof(buf));
					/*			sprintf(buf,"touch %s",rewr.file_name);
								printf("^^^^^^^^^\n");
								system(buf);
								bzero(buf,sizeof(buf));*/
								printf("********\n");
								int s_fd = open(rewr.file_name,O_CREAT|O_RDWR|0666);
								printf("%%%%%%%%\n");
								printf("%d\n",s_fd);
								if(s_fd<0)
								{
										perror("s_fd fail");
										exit(-1);
								}
								printf("%s\n",rewr.file_buf);
								write(s_fd,rewr.file_buf,strlen(rewr.file_buf)+1);
								close(s_fd);

						//		sprintf(buf,"rewr.file_buf > rewr.file_name");

						}
						else
						{
								printf("%s\n",rewr.file_buf);
						}						
				}
		}
		else
		{
				while(1)
				{
						bzero(&rewr,sizeof(sG_p));
						printf("ftp>");
						fflush(stdout);	
						getchar();	
						scanf("%[^\n]",rewr.file_name);
				//		getchar();
						printf("%s\n",rewr.file_name);
						if(strncmp(rewr.file_name,"quit",4)==0)
						{
								break;
						}
						else
						if(strncmp(rewr.file_name,"put",3)==0)
						{

								printf("jin ru put\n");
								char sys[30]={'\0'};
								bzero(buf,sizeof(buf));
								strncpy(sys,&rewr.file_name[4],strlen(rewr.file_name)-3);
								printf("sys:%s\n",sys);
								int fd = open(sys,O_RDONLY);
								if(fd<0)
								{
										perror("open fail");
										exit(-1);
								}
								read(fd,rewr.file_buf,sizeof(rewr.file_buf));
							//	sprintf(buf,"cat %s > rewr.file_buf",sys);
								printf("%s\n",rewr.file_buf);
						}
						
						write(sockfd,&rewr,sizeof(rewr));
				}
				kill(pid,SIGKILL);
		}
		return 0;
}
