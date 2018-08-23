#include"ftp.h"
void get_file(struct send_pakg ser_cli_info);
void judge_choose(struct send_pakg ser_cli_data);//判断服务器的返回值
void judge_cli_ser(struct cli_ser_pakg *cli_ser_info)  //判断客户端命令 
{
		int num =0;
		static char cmd_info[100];
		static int i = 0;
		memset(cmd_info,0,sizeof(cmd_info));
		char *cmd_temp = NULL;
		printf("ftp>");
		fflush(stdout);
		if( i == 0)
		{
			getchar();
		}
		gets(cmd_info);
		if(strncmp(cmd_info,"ls",2)==0)
		{
			 (*cli_ser_info).cmd = LS;
			 cmd_temp = strrchr(cmd_info,' ');
			 if(NULL == cmd_temp)
			 {
			 	bzero(cli_ser_info->argv.file_get,sizeof(cli_ser_info->argv.file_get));
			 }
			 else 
			 {
			 	strcat(cli_ser_info->argv.path_ls,cmd_temp+1);
			 }
			 num++;
		}
		if(strncmp(cmd_info,"put ",4)==0)
		{
			 (*cli_ser_info).cmd = PUT;
			 cmd_temp = strrchr(cmd_info,' ');
			 if(NULL == cmd_temp)
			 {
			 	bzero(cli_ser_info->argv.file_put,sizeof(cli_ser_info->argv.file_put));
			 }
			 else 
			 {
			 	strcat(cli_ser_info->argv.file_put,cmd_temp+1);
			 }
			 num++;
		}
		if(strncmp(cmd_info,"get ",4)==0)
		{
			 (*cli_ser_info).cmd = GET;
			 cmd_temp = strrchr(cmd_info,' ');
			 if(NULL == cmd_temp)
			 {
			 	bzero(cli_ser_info->argv.file_get,sizeof(cli_ser_info->argv.file_get));
			 }
			 else 
			 {
			 	strcat(cli_ser_info->argv.file_get,cmd_temp+1);
			 }
			 num++;
		}
		if(strncmp(cmd_info,"cd ",3)==0)
		{
			 (*cli_ser_info).cmd = CD;
			 cmd_temp = strrchr(cmd_info,' ');
			 if(NULL == cmd_temp)
			 {
			 	bzero(cli_ser_info->argv.path_cd,sizeof(cli_ser_info->argv.path_cd));
			 }
			 else 
			 {
			 	strcat(cli_ser_info->argv.path_cd,cmd_temp+1);
			 }
			 num++;
		}
		if(strncmp(cmd_info,"pwd",3)==0)
		{
			 (*cli_ser_info).cmd = PWD;
			 cmd_temp = strrchr(cmd_info,' ');
			 if(NULL == cmd_temp)
			 {
			 	bzero(cli_ser_info->argv.path_pwd,sizeof(cli_ser_info->argv.path_pwd));
			 }
			 else 
			 {
			 	strcat(cli_ser_info->argv.path_pwd,cmd_temp+1);
			 }
			 num++;
		}
		if(strncmp(cmd_info,"mkdir ",6)==0)
		{
			 (*cli_ser_info).cmd = MKDIR;
			 cmd_temp = strrchr(cmd_info,' ');
			 if(NULL == cmd_temp)
			 {
			 	bzero(cli_ser_info->argv.path_mkdir,sizeof(cli_ser_info->argv.path_mkdir));
			 }
			 else 
			 {
			 	strcat(cli_ser_info->argv.path_mkdir,cmd_temp+1);
			 }
			 num++;
		}
		if(strncmp(cmd_info,"quit",4)==0)
		{
			 (*cli_ser_info).cmd = QUIT;
			 cmd_temp = strrchr(cmd_info,' ');
			 if(NULL == cmd_temp)
			 {
			 	bzero(cli_ser_info->argv.path_quit,sizeof(cli_ser_info->argv.path_quit));
			 }
			 else 
			 {
			 	strcat(cli_ser_info->argv.path_quit,cmd_temp+1);
			 }
			 num++;
		}
		if(num == 0)
		{	
				(*cli_ser_info).cmd = ERR;	
				printf("?Tnvalid command\n");
		}
		i++;
}
void myexit(int sig)
{
	printf("connect fail\n");
	exit(0);
}
int main(int argc,char **argv)
{
	if(argc !=2 )
	{
		printf("%s ip\n",argv[0]);
		return 0;
	}
	signal(SIGALRM,myexit);	//ip错误
	int sendret,readret,recvret; 
	int i = 0;  
	char *user_pass; 
	struct sockaddr_in conaddr;   //链接服务器的信息结构体
	socklen_t len = sizeof(conaddr); 
	struct cli_ser_pakg cli_ser_info;
	struct send_pakg ser_cli_info;
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);//建立socket
	if(sockfd < 0)
	{
		myperror("socket");
	}
	bzero(&cli_ser_info,sizeof(cli_ser_info));
	printf("Connected to %s(%s)\n",argv[1],argv[1]);
	printf("NAME (%s:root):",argv[1]);
	fflush(stdout);
	scanf("%s",cli_ser_info.cli_info.username);
	printf("please speclfy the password.\n");
	user_pass= getpass("Password:");
	sprintf(cli_ser_info.cli_info.passwd,"%s",user_pass);
	cli_ser_info.cmd = LOGIN;
	bzero(&conaddr,sizeof(conaddr));
	conaddr.sin_family = AF_INET;
	conaddr.sin_port = htons(6666);
	conaddr.sin_addr.s_addr = inet_addr(argv[1]);	
	while(1)
	{
		if(i != 0)
		{
			bzero(&cli_ser_info,sizeof(cli_ser_info));
			judge_cli_ser(&cli_ser_info);
			if(cli_ser_info.cmd == ERR)
			{
				continue;
			}
		}
		if(cli_ser_info.cmd == PUT)
		{
				i = 0;
				int fd = open(cli_ser_info.argv.file_put,O_RDONLY);
				if(fd < 0)
				{
					i = 1;
					printf("local:%s remote :%s\n",cli_ser_info.argv.file_put,cli_ser_info.argv.file_put);
					printf("local:%s :No such file or directory\n",cli_ser_info.argv.file_put);
					continue;
				}
				while(1)
				{	
						if(i == 0)
						{
							readret = strlen(cli_ser_info.argv.file_put);
						}
							if(i != 0)
						{	
								bzero(&cli_ser_info,sizeof(cli_ser_info));
								readret = read(fd,cli_ser_info.argv.file_put,sizeof(cli_ser_info.argv.file_put)-3);
								if(readret < 0)
								{
										myperror("read");	
								}
						}
						if(readret == 0)
						{
								cli_ser_info.cmd = PUT_OVER;
								sendret = sendto(sockfd,&cli_ser_info,sizeof(cli_ser_info),0,(struct sockaddr *)&conaddr,len);//发送信息							
								if(sendret < 0)
								{
										close(sockfd);
										myperror("sendto");
								}
								break;	
						}
						if(i != 0)
						{
								cli_ser_info.cmd = PUT_CONT;
						}
	
						sendret = sendto(sockfd,&cli_ser_info,sizeof(cli_ser_info),0,(struct sockaddr *)&conaddr,len);//发送文件内容
						if(sendret < 0)
						{
								close(sockfd);
								myperror("sendto");
						}
						bzero(&cli_ser_info,sizeof(cli_ser_info));
						i++;
				}
		}
		else
		{
				
				sendret = sendto(sockfd,&cli_ser_info,sizeof(cli_ser_info),0,(struct sockaddr *)&conaddr,len);//发送命令
				alarm(1);
				if(sendret < 0)
				{
						close(sockfd);
						myperror("sendto");
				}
		}
		while(1)
		{		
				bzero(&ser_cli_info,sizeof(ser_cli_info));
				recvret = recvfrom(sockfd,&ser_cli_info,sizeof(ser_cli_info),0,NULL,NULL);	//接受服务器返回内容
				alarm(0);
				if(recvret < 0)
				{
						myperror("recvfrom");
				}
				judge_choose(ser_cli_info);
				if((ser_cli_info.pakg_type == PUT_OVER)||(ser_cli_info.pakg_type == OVER)||(ser_cli_info.pakg_type == GET_OVER)||(ser_cli_info.pakg_type == LOGIN)||(ser_cli_info.pakg_type == ERR))
				{
					 break;
				}
		}
		i++;
	}
}
void judge_choose(struct send_pakg ser_cli_data)//判断服务器的返回值
{
	switch(ser_cli_data.pakg_type)
	{
		case ERR:
				printf("%s\n",ser_cli_data.data_buf.cmd_buf);
				break;
	    case LOGIN:
				printf("%s\n",ser_cli_data.data_buf.cmd_buf);
				break;
		case LS:
				printf("%s\n",ser_cli_data.data_buf.cmd_buf);
				break;
		case PUT_OVER:
				printf("%s\n",ser_cli_data.data_buf.cmd_buf);
				break;
		case GET:
				get_file(ser_cli_data);
				break;
		case GET_CONT:
				get_file(ser_cli_data);
				break;
		case GET_OVER:
				printf("%s\n",ser_cli_data.data_buf.cmd_buf);
				break;
		case CD:
				printf("%s\n",ser_cli_data.data_buf.cmd_buf);
				break;
		case PWD:
				printf("%s\n",ser_cli_data.data_buf.cmd_buf);
				break;
		case MKDIR:
				printf("%s\n",ser_cli_data.data_buf.cmd_buf);
				break;
		case QUIT:
				printf("%s\n",ser_cli_data.data_buf.cmd_buf);
				exit(0);
		case OVER:
				break;
		default:
				break;
	}
}
void get_file(struct send_pakg ser_cli_info)
{
	static char file_name[256];
	
	if(ser_cli_info.pakg_type == GET)
	{
		char *p =NULL; 
		memset(file_name,0,sizeof(file_name));
			if((p=strrchr(ser_cli_info.data_buf.file_buf,'/'))!=NULL)
			{			
				strcpy(file_name,p+1);
			}
			else
			{
				strcpy(file_name,ser_cli_info.data_buf.file_buf);
			}
		int fd = open(file_name,O_CREAT|O_EXCL|O_RDWR,0666);
		if(fd < 0)
		{
			if(errno ==EEXIST)
			{
				fd = open(ser_cli_info.data_buf.file_buf,O_TRUNC|O_RDWR);		
			}
		}
		close(fd);
	}
	if(ser_cli_info.pakg_type == GET_CONT)
	{
		int fd = open(file_name,O_APPEND|O_RDWR);
	
		write(fd,ser_cli_info.data_buf.file_buf,strlen(ser_cli_info.data_buf.file_buf));
		close(fd);
	}	
}

