#include"cli_apue.h"
int main(int argc,char **argv)
{
		signal(SIGALRM,myexit);
		//输入容错
		if(argc!=2)
		{
				char buf_err[50];
				while(1)
				{
						printf("ftp>");
						scanf("%s",buf_err);
						if(!strcmp(buf_err,"quit"))
						{
								exit(-1);
						}
						puts("?Invalid command");
				}
		}
		int sockfd = socket(AF_INET,SOCK_DGRAM,0);
		if(sockfd<0)
		{
				show_err("socket");
		}
		struct sockaddr_in destaddr;

		bzero(&destaddr,sizeof(destaddr));
		destaddr.sin_family = AF_INET;
		destaddr.sin_addr.s_addr = inet_addr(argv[1]);
		destaddr.sin_port = htons(6666);

		struct cli_ser_pakg pakgSend;
		bzero(&pakgSend,sizeof(pakgSend));
		pakgSend.cmd = LOGIN;
		printf("Connected to %s(%s).\n",argv[1],argv[1]);
		printf("Name (%s:root):",argv[1]);
		scanf("%s",pakgSend.cli_info.username);
		printf("Please specify the password.\n");
		strcpy(pakgSend.cli_info.passwd,getpass("Password:"));
		//向sever发出链接申请
		if(sendto(sockfd,&pakgSend,sizeof(pakgSend),0,(struct sockaddr*)&destaddr,sizeof(destaddr))<0)
		{
				perror("sentto");
				show_err("sendto_log");
		}
		char *file_pathGet;
		//接受信息是否login成功
		struct send_pakg flag_log;
		bzero(&flag_log,sizeof(flag_log));
		//接受是否连接成功
		if(recvfrom(sockfd,&flag_log,sizeof(flag_log),0,NULL,NULL)<0)
		{
				show_err("recvfrom_log");
		}
		if((int)flag_log.pakg_type==LOGIN)
		{
				puts(flag_log.data_buf.file_buf);
				char command[1024];
				//定义要向server发送的命令结构体
				struct cli_ser_pakg cliTser_msg;

				int fd_get_put;
				//定义接收server传送回的内容结构体
				struct send_pakg recvSer_data;
				int flag=0;
				while(1)
				{
						printf("ftp> ");
						bzero(command,sizeof(command));
						if(flag==0)
						{
								getchar();
								flag++;
						}
						gets(command);
						alarm(300);//定时五分钟，若五分钟内没操作自动退出
						bzero(&cliTser_msg,sizeof(cliTser_msg));
						cliTser_msg = comd(command);//返回带有命令的结构体（命令解析）
						if(cliTser_msg.cmd == PUT)
						{
								if(access(cliTser_msg.argv.file_put,R_OK|F_OK)<0)//检测put后path是否合法
								{
										cliTser_msg.cmd = ERR;
								}
						}
						if(cliTser_msg.cmd == ERR)
						{
								puts("Input error!");
								continue;
						}
						//发送命令结构体
						if(sendto(sockfd,&cliTser_msg,sizeof(cliTser_msg),0,(struct sockaddr*)&destaddr,sizeof(destaddr))<0)
						{
								show_err("sendto_cmd");
						}
						//如果是put命令时打开文件并上传内容
						if(cliTser_msg.cmd == PUT)
						{
								fd_get_put = open(cliTser_msg.argv.file_put,O_RDONLY);
								if(fd_get_put<0)
								{
										show_err("open_put");
								}
								else
								{
										while(1)
										{
												bzero(&cliTser_msg,sizeof(cliTser_msg));
												cliTser_msg.cmd = PUT_CONT;
												if(read(fd_get_put,cliTser_msg.argv.file_put,sizeof(cliTser_msg.argv.file_put)-3)==0)
												{
														cliTser_msg.cmd = PUT_OVER;
														strcpy(cliTser_msg.argv.file_put,"put file successful.");
												}
												//发送文件内容
												if(sendto(sockfd,&cliTser_msg,sizeof(cliTser_msg),0,(struct sockaddr*)&destaddr,sizeof(destaddr))<0)
												{
														show_err("sendto_file_buf");
												}
												if(cliTser_msg.cmd==PUT_OVER)
												{
														break;
												}
										}
								}
						}
						while(1)
						{
								bzero(&recvSer_data,sizeof(recvSer_data));
								if(recvfrom(sockfd,&recvSer_data,sizeof(recvSer_data),0,NULL,NULL)<0)
								{
										show_err("recvfrom_data");
								}
								if(recvSer_data.pakg_type == GET)
								{
								  file_pathGet = strrchr(recvSer_data.data_buf.file_buf,'/');
								  if(file_pathGet==NULL)
								    {
										fd_get_put = open(recvSer_data.data_buf.file_buf,O_RDWR|O_CREAT|O_TRUNC,0666);
										if(fd_get_put<0)
										{
												show_err("open_get");
										}
								    }
								  else
								    {
								      		fd_get_put = open(file_pathGet+1,O_RDWR|O_CREAT|O_TRUNC,0666);
										if(fd_get_put<0)
										{
												show_err("open_get");
										}
								    }
								}
								else if(recvSer_data.pakg_type == GET_CONT)
								{
										if(write(fd_get_put,recvSer_data.data_buf.file_buf,strlen(recvSer_data.data_buf.file_buf))<0)
										{
												show_err("write_get");
										}
								}
								else if(recvSer_data.pakg_type == GET_OVER||recvSer_data.pakg_type==PUT_OVER)
								{
										close(fd_get_put);
										puts(recvSer_data.data_buf.file_buf);
										break;
								}
								else if(recvSer_data.pakg_type == QUIT)
								{
										puts(recvSer_data.data_buf.file_buf);
										exit(0);
								}
								else if(recvSer_data.pakg_type == LS||recvSer_data.pakg_type == PWD||recvSer_data.pakg_type == CD||recvSer_data.pakg_type == MKDIR)
								{
										puts(recvSer_data.data_buf.file_buf);
								}
								else if(recvSer_data.pakg_type == ERR)
								  {
								    puts(recvSer_data.data_buf.file_buf);
								    break;
								  }
								else if(recvSer_data.pakg_type == OVER)
								{
								  
										break;
								}
								else 
								{
										printf("CMD:%d\n" ,recvSer_data.pakg_type);
										puts(recvSer_data.data_buf.file_buf);
								}
						}
				}
		}
		else
		{
				puts("Login incorret.");
				puts("Login failed.");
		}
		return 0;
}

//命令解析函数（把命令和后缀分开并写入返回结构体）
struct cli_ser_pakg comd(char *command)
{	 
		struct cli_ser_pakg cliTser_msg;
		bzero(&cliTser_msg,sizeof(cliTser_msg));

		int flag_cmd; 
		command = wipe_space(command);
		char *first_spa = find_firstsp(command);
		if(!strncmp(command,"get",strlen(command)-strlen(first_spa)))
		{
				cliTser_msg.cmd = GET;	
		}
		else if(!strncmp(command,"put",strlen(command)-strlen(first_spa)))
		{
				cliTser_msg.cmd = PUT;	
		}
		else if(!strncmp(command,"ls",strlen(command)-strlen(first_spa)))
		{
				cliTser_msg.cmd = LS;	
		}
		else if(!strncmp(command,"pwd",strlen(command)-strlen(first_spa)))
		{
				cliTser_msg.cmd = PWD;	
		}
		else if(!strncmp(command,"cd",strlen(command)-strlen(first_spa)))
		{
				cliTser_msg.cmd = CD;	
		}
		else if(!strncmp(command,"quit",strlen(command)-strlen(first_spa)))
		{
				cliTser_msg.cmd = QUIT;	
		}
		else if(!strncmp(command,"mkdir",strlen(command)-strlen(first_spa)))
		{
				cliTser_msg.cmd = MKDIR;	
		}
		else
		{
				cliTser_msg.cmd = ERR;	
				return cliTser_msg;
		}
		char *filenameOpath;

		if(cliTser_msg.cmd == GET||cliTser_msg.cmd == PUT||cliTser_msg.cmd == CD||cliTser_msg.cmd == MKDIR)
		{
				if(strlen(first_spa)==0)
				{
						cliTser_msg.cmd = ERR;	
						return cliTser_msg;
				}
				else
				{
						filenameOpath = wipe_space(first_spa);
						if(strlen(filenameOpath)==0)
						{
								cliTser_msg.cmd = ERR;	
								return cliTser_msg;
						}
						else
						{
								strcpy(cliTser_msg.argv.file_get,filenameOpath);
						}
				}
		}
		else if(cliTser_msg.cmd==LS)
		{
				if(strlen(first_spa)==0)
				{
						bzero(cliTser_msg.argv.path_ls,sizeof(cliTser_msg.argv.path_ls));
				}
				else
				{
						filenameOpath = wipe_space(first_spa);
						if(strlen(filenameOpath)==0)
						{
								bzero(cliTser_msg.argv.path_ls,sizeof(cliTser_msg.argv.path_ls));
						}
						else
						{
								strcpy(cliTser_msg.argv.path_ls,filenameOpath);
						}
				}

		}
		return cliTser_msg;
}
//寻找第一个空格
char *find_firstsp(char *str)
{
		int i=0;
		while(1)
		{
				if(str[i] == ' ')
				{
						return str+i;
				}
				i++;
				if(str[i] == '\0')
				{
						return "\0";
				}
		}
}
//清命令中的空格
char *wipe_space(char *str)
{
		int i=0;
		while(1)
		{
				if(str[i]!=' ')
				{
						return str+i;
				}
				i++;
				if(str[i] == '\0')
				{
						return "\0";
				}
		}
}
void myexit(int sig)
{
		puts("Timeout");
		exit(0);
}
