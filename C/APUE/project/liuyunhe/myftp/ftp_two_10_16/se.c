#include"apue.h"

int main()
{
		struct sockaddr_in selfaddr,conaddr;
		struct show_err fork_in,show_output;
		int len = sizeof(conaddr);
		int sockfd;
		int confd;
		int ret;
		char buf[1024];
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
		while(1)
		{
				confd =accept(sockfd,(struct sockaddr *)&conaddr,&len);
				printf("%d\n",confd);
				if(confd<0)
				{
						close(sockfd);
						show_err("accept");
				}
				bzero(buf,sizeof(buf));
				read(confd,buf,sizeof(buf));
				printf("buf%s\n",buf);
				fork_in.sockfd = confd;
				bzero(fork_in.ftp_arg.ftp_ls_path,sizeof(fork_in.ftp_arg.ftp_ls_path));
				strcpy(fork_in.ftp_arg.ftp_ls_path,buf);
				int pd[2];
				pipe(pd);
				pid_t pid = fork();
				if(pid<0)
				{
						show_err("fork");
				}
				if(pid>0)/*进程一*/
				{
						close(pd[0]);
						write(pd[1],&fork_in,sizeof(fork_in));
				}

				else if(pid == 0)/*进程二*/
				{
						char *enc = NULL;
						close(pd[1]);
						read(pd[0],&fork_in,sizeof(fork_in));
						printf("1:%s\n",fork_in.ftp_arg.ftp_ls_path);
#if 0
						write(fork_in.sockfd,fork_in.ftp_arg.ftp_ls_path,strlen(fork_in.ftp_arg.ftp_ls_path)+1);
						while(1)
						{
								bzero(buf,sizeof(buf));
								read(fork_in.sockfd,buf,sizeof(buf));
								printf("buf:%s\n",buf);
								write(fork_in.sockfd,buf,sizeof(buf));
						}
#endif

						struct spwd *pspwd = NULL;
						bzero(buf,sizeof(buf));
						strcpy(buf,fork_in.ftp_arg.ftp_ls_path);
						pspwd = getspnam(buf);
						if(pspwd == NULL)/*校验用户名*/
						{   
								bzero(buf,sizeof(buf));
								strcpy(buf,"sorry please input name");
								printf("%s\n",buf);
								write(fork_in.sockfd,buf,strlen(buf)+1);
								while(1)
								{
										bzero(buf,sizeof(buf));
										read(fork_in.sockfd,buf,sizeof(buf));
										pspwd = getspnam(buf);
										if(pspwd == NULL)
										{   
												bzero(buf,sizeof(buf));
												strcpy(buf,"sorry please input name");
												printf("%s\n",buf);
												write(fork_in.sockfd,buf,strlen(buf)+1);                        
										}
										else
										{
												bzero(fork_in.usr_pa.ftp_usrname,sizeof(fork_in.usr_pa.ftp_passwd));
												strcpy(fork_in.usr_pa.ftp_usrname,buf);
												strcpy(buf,"OK input password");
												printf("%s\n",buf);
												write(fork_in.sockfd,buf,strlen(buf)+1);                        

												break;
										}
								}
						}
						else
						{
								bzero(fork_in.usr_pa.ftp_usrname,sizeof(fork_in.usr_pa.ftp_passwd));
								strcpy(fork_in.usr_pa.ftp_usrname,buf);
								strcpy(buf,"OK input password");
								printf("%s\n",buf);
								write(fork_in.sockfd,buf,strlen(buf)+1);

						}

						while(1)/*校验密码*/
						{
								bzero(buf,sizeof(buf));
								read(fork_in.sockfd,buf,sizeof(buf));
								enc = crypt(buf,pspwd->sp_pwdp);
								if(strcmp(enc,pspwd->sp_pwdp)== 0)
								{
										bzero(fork_in.usr_pa.ftp_passwd,sizeof(fork_in.usr_pa.ftp_passwd));
										strcpy(fork_in.usr_pa.ftp_passwd,buf);
										bzero(buf,sizeof(buf));
										strcpy(buf,"yes input commend");
										printf("%s\n",buf);
										write(fork_in.sockfd,buf,strlen(buf)+1);
										break;
								}
								else
								{
										bzero(buf,sizeof(buf));
										strcpy(buf,"sorry input password");
										printf("%s\n",buf);
										write(fork_in.sockfd,buf,strlen(buf)+1);
								}
						}

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
										bzero(buf,sizeof(buf));
										read(fork_in.sockfd,buf,sizeof(buf));
										if(strncmp(buf,"ls",2)==0)
										{
												fork_in.cmd = LS;
										}
										else if(strncmp(buf,"put",3)==0)
										{
												fork_in.cmd = PUT;
										}
										else if(strncmp(buf,"get",3)==0)
										{
												fork_in.cmd = GET;
										}
										else if(strncmp(buf,"cd",2)==0)
										{
												fork_in.cmd = CD;
										}
										else if(strncmp(buf,"pwd",3)==0)
										{
												fork_in.cmd = PWD;
										}
										else if(strncmp(buf,"mkdir",5)==0)
										{
												fork_in.cmd = MKDIR;
										}
										else if(strncmp(buf,"quit",4)==0)
										{
												fork_in.cmd = QUIT;
										}
										else
										{

												bzero(buf,sizeof(buf));
												strcpy(buf,"input eror");
												write(fork_in.sockfd,buf,sizeof(buf));
												continue;
										}

										bzero(fork_in.ftp_arg.ftp_ls_path,sizeof(fork_in.ftp_arg.ftp_ls_path));
										strcpy(fork_in.ftp_arg.ftp_ls_path,buf);
										write(fid[1],&fork_in,sizeof(fork_in));



								}
						}
				}
		}
		return 0;
}
