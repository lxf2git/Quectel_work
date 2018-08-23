#include"apue.h"

int main()
{	
		struct sockaddr_in selfaddr,conaddr;	
		int ret,confd;
		socklen_t len = sizeof(conaddr);
		char buf[100];

		int sockfd = socket(AF_INET,SOCK_STREAM,0);	
		if(sockfd<0)
		{
				perror("socket");
		}

		bzero(&selfaddr,sizeof(selfaddr));
		selfaddr.sin_family = AF_INET;
		selfaddr.sin_addr.s_addr =htonl(INADDR_ANY); 
		selfaddr.sin_port = htons(8888);
		ret = bind(sockfd,(struct sockaddr*)&selfaddr,sizeof(selfaddr));
		if(ret<0)
		{
				close(sockfd);
				perror("bind");
		}

		listen(sockfd,10);
		//反复等待客户连接	
		bzero(&conaddr,sizeof(conaddr));
		bzero(buf,sizeof(buf));
		while(1)
		{	
				confd = accept(sockfd,(struct sockaddr*)&conaddr,&len);
				if(confd<0)
				{
						perror("accept");
				}

				pid_t pid;
				pid = fork();
				if(pid<0)
				{
						perror("deal_fork");
				}
				if(pid==0)  //deal  进程
				{	
						pF buf_data=NULL;			
						sF buf_data1;			
						pF pHead = NULL;
						init_node(&pHead);			
						init_node(&buf_data);
						while(1)
						{	
								read(confd,&buf_data1,sizeof(buf_data1));
								//读取帐号密码
								strcpy(buf_data->ftp_usrname ,buf_data1.ftp_usrname);
								strcpy(buf_data->ftp_passwd , buf_data1.ftp_passwd);
								int n = login_infor(pHead,buf_data1.ftp_usrname,buf_data1.ftp_passwd);  //建立链表
								if(n==1)
								{
										break;
								}
								else  //链表不同过
								{
										char msg[20]="login_again";
										write(confd,msg,strlen(msg)+1);
										continue;
								}
						}				
						if(fork()==0)
						{
								sleep(1);
								//验证密码帐号*/
								sG_p P_buf1;
								printf("开始命令\n");
								while(1)
								{
										bzero(&P_buf1,sizeof(P_buf1));
										int num = read(confd,&P_buf1,sizeof(P_buf1));
										if(num <=0)
										{
												delete(pHead,buf_data->ftp_usrname);
												char temp[50]={'\0'};
												bzero(temp,sizeof(temp));
												sprintf(temp,"kill %d",getpid());
												system(temp);
										
										}
										//循环读取命令	
										printf("%s\n",P_buf1.file_name);
										choose_command(P_buf1.file_name,P_buf1.file_buf,confd);
										//当命令为quit的时候 自杀
										
										
										
								}
						}
						else
						{
								printf("验证:%s\n%s\n",buf_data->ftp_usrname,buf_data->ftp_passwd);
								int l_psw = login_user_psw(buf_data->ftp_usrname,buf_data->ftp_passwd);
								if(l_psw==1)
								{
										char buf1[50]="login_success";
										write(confd,buf1,strlen(buf1)+1);
								}
								else    //不通过
								{ 
										char buf2[20]="login_failed";
										write(confd,buf2,strlen(buf2)+1);
										delete(pHead,buf_data->ftp_usrname);
										bzero(buf2,sizeof(buf2));
										sprintf(buf2,"kill %d",pid);  //失败 自杀 
										system(buf2);
								}
								wait(NULL);
						}	
				}
		}
}
