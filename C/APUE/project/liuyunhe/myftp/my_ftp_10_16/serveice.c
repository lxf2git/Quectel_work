#include"apue.h"
typedef struct st
{
		int sockfd;
		struct ftp_usr_info nameandpasswd;
		struct st *prev;
		struct st *next;
}sStu,*pStu;
void create_memory(pStu *pnode)
{
		*pnode = (pStu) malloc(sizeof(sStu));
		if(NULL == *pnode)
		{
				show_err("malloc");
							
		}
}


void init_node(pStu *pnode)
{
		create_memory(pnode);
		(*pnode)->next = *pnode;
		(*pnode)->prev = *pnode;
}

void creat_head_chain(pStu pHead,int sockfd,struct ftp_usr_info nap)
{
		pStu pnew =NULL;
		init_node(&pnew);
		pnew->sockfd = sockfd;
		strcpy(pnew->nameandpasswd.ftp_usrname,nap.ftp_usrname);
		strcpy(pnew->nameandpasswd.ftp_passwd,nap.ftp_passwd);

		pHead->next->prev = pnew;
		pnew->prev =pHead;
		pnew->next = pHead->next;
		pHead->next = pnew;
}

void close_chain(pStu pHead,int sockfd)
{
		pStu ptmp = NULL;
		for(ptmp = pHead->next;ptmp != pHead ; ptmp = ptmp->next)
		{
				if(ptmp->sockfd == sockfd)
				{
						ptmp->prev->next = ptmp->next;
						ptmp->next->prev = ptmp->prev;
						if(ptmp!=NULL)
						{
								free(ptmp);
								ptmp = NULL;
								return;
						}
				}
		}
}

int main()

{
		struct sockaddr_in selfaddr,conaddr;
		struct ftp_ch MyFtpout;
		struct show_err show_input,show_output;
		struct spwd *pspwd =NULL;
		int sockfd,confd,ret; 
		socklen_t len = sizeof(conaddr);
		char in_buf[100];
		char out_buf[100];
		sockfd = socket(AF_INET,SOCK_STREAM,0);
		if(sockfd < 0)
		{
				show_err("socket");
		}
		
		bzero(&selfaddr,sizeof(selfaddr));
		selfaddr.sin_family = AF_INET;
		selfaddr.sin_port = htons(8888);
		selfaddr.sin_addr.s_addr = htonl(INADDR_ANY);
		ret = bind(sockfd,(struct sockaddr *)&selfaddr,sizeof(selfaddr));
		if(ret < 0)
		{
				close(sockfd);
				show_err("bind");
		}
		
		ret = listen(sockfd,10);
		if(ret < 0)
		{
				close(sockfd);
				show_err("listen");
		}

		confd = accept(sockfd,(struct sockaddr *)&conaddr,&len);
		if(confd<0)
		{
				close(sockfd);
				show_err("accept");
		}
		int fd[2];
		pipe(fd);
		pid_t pid = fork();
		if(pid <0)
		{
				close(sockfd);
				show_err("fock");
		}

		if(pid == 0)/*进程二*/
		{
				char *enc = NULL;
				sleep(1);
				close(fd[1]);
				
				pStu pHead = NULL;
				init_node(&pHead);
				while(1)/*校验用户名*/
				{
						bzero(out_buf,sizeof(out_buf));
						bzero(&MyFtpout,sizeof(MyFtpout));
						read(fd[0],&MyFtpout,sizeof(MyFtpout));
						printf("%s\n",MyFtpout.ch);
						printf("%d\n",MyFtpout.confd);
						strcpy(out_buf,MyFtpout.ch);
						pspwd = getspnam(out_buf);
						if(pspwd == NULL)
						{
								bzero(out_buf,sizeof(out_buf));
								strcpy(out_buf,"sorry please input name");
								printf("%s\n",out_buf);
						//		printf("%d\n",strlen(out_buf));
								write(MyFtpout.confd,out_buf,strlen(out_buf)+1);
						}
						else
						{
								bzero(&show_input.usr_pa.ftp_usrname,sizeof(show_input.usr_pa.ftp_usrname));
								strcpy(show_input.usr_pa.ftp_usrname,out_buf);
								bzero(out_buf,sizeof(out_buf));
								strcpy(out_buf,"OK input password");
								printf("%s\n",out_buf);
						//		printf("%d\n",strlen(out_buf));
								write(MyFtpout.confd,out_buf,strlen(out_buf)+1);
								break;
						}
				}

				while(1)/*校验密码*/
				{
						bzero(out_buf,sizeof(&out_buf));
						bzero(&MyFtpout,sizeof(MyFtpout));
						read(fd[0],&MyFtpout,sizeof(MyFtpout));
						strcpy(out_buf,MyFtpout.ch);
						enc = crypt(out_buf,pspwd->sp_pwdp);
						if(strcmp(enc,pspwd->sp_pwdp)== 0)
						{
								bzero(&show_input.usr_pa.ftp_passwd,sizeof(show_input.usr_pa.ftp_passwd));
								strcpy(show_input.usr_pa.ftp_passwd,out_buf);
								bzero(out_buf,sizeof(out_buf));
								strcpy(out_buf,"yes input commend");
								printf("%s\n",out_buf);
								write(MyFtpout.confd,out_buf,strlen(out_buf)+1);
								break;
						}
						else
						{
								bzero(out_buf,sizeof(out_buf));
								strcpy(out_buf,"sorry input password");
								printf("%s\n",out_buf);
								write(MyFtpout.confd,out_buf,strlen(out_buf)+1);
						}
				}
				show_input.sockfd = MyFtpout.confd;
				creat_head_chain(pHead,show_input.sockfd,show_input.usr_pa);
				

				int fid[2];
				pipe(fid);

				pid_t ppid = fork();
				
				if(ppid <0)
				{
						close(sockfd);
						show_err("fock_pp");
				}
				
				if(ppid == 0)/*进程三*/
				{
						sleep(1);
						close(fid[1]);
						while(1)
						{
								bzero(&show_output,sizeof(show_output));
								read(fid[0],&show_output,sizeof(show_output));
								switch(show_output.cmd)
								{
										case LS:
												printf("ls in\n");
												ls_ftp(show_output);
												printf("ls out\n");
												break;
										case PUT:
												printf("put in\n");
												put(&show_output);
												printf("put ok\n");
												break;
										case GET:
												printf("get in\n");
												get(&show_output);
												printf("get ok\n");
												break;
										case CD:
												printf("cd in\n");
												 my_cd(show_output);
												printf("cd out\n");
												break;
										case PWD:
												printf("pwd in\n");
												pwd(&show_output);
												printf("pwd ok\n");
												break;
										case MKDIR:
												printf("mkdir in\n");
												 mymkdir(show_output);
												printf("mkdir out\n");
												break;
										case QUIT:
												return ;
												break;
										default:
												;

								}
						}
				}
				else/*命令*/
				{
						close(fid[0]);
						while(1)
						{
								read(fd[0],&MyFtpout,sizeof(MyFtpout));
								bzero(&show_input.ftp_arg,sizeof(show_input.ftp_arg));
							
								if(strncmp(MyFtpout.ch,"ls",2)==0)
								{
										show_input.cmd = LS;
								}
								else if(strncmp(MyFtpout.ch,"put",3)==0)
								{
										 show_input.cmd = PUT;
								}
								else if(strncmp(MyFtpout.ch,"get",3)==0)
								{
										 show_input.cmd = GET;
								}
								else if(strncmp(MyFtpout.ch,"cd",2)==0)
								{
										 show_input.cmd = CD;
								}
								else if(strncmp(MyFtpout.ch,"pwd",3)==0)
								{
										 show_input.cmd = PWD;
								}
								else if(strncmp(MyFtpout.ch,"mkdir",5)==0)
								{
										 show_input.cmd = MKDIR;
								}
								else if(strncmp(MyFtpout.ch,"quit",4)==0)
								{
										 show_input.cmd = QUIT;
										close_chain(pHead,show_input.sockfd);
								}
								else
								{

										bzero(out_buf,sizeof(out_buf));
										strcpy(out_buf,"input eror");
										 write(show_input.sockfd,out_buf,sizeof(out_buf));
										 continue;
								}

								strcpy(show_input.ftp_arg.ftp_ls_path,MyFtpout.ch);
								write(fid[1],&show_input,sizeof(show_input));

						}
				}

		}
		else/*进程一*/
		{
				close(fd[0]);
				struct ftp_ch MyFtpCh;
				MyFtpCh.confd = confd;
				while(1)
				{
						bzero(MyFtpCh.ch,sizeof(MyFtpCh.ch));
						bzero(in_buf,sizeof(in_buf));
						read(confd,in_buf,sizeof(in_buf));

					//	printf("in_buf%s\n",in_buf);

						strcpy(MyFtpCh.ch,in_buf);
						write(fd[1],&MyFtpCh,sizeof(MyFtpCh));
				}
		}
		return 0;
}
