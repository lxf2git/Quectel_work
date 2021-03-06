/***   密码错误或者推出返回-1 其余返回0
 * */
#include "service.h"
#include <errno.h>


int  deal_child_process(struct info judge,int sockfd)
{
		printf("deal_child_processs\n");
		char buf[200];
		bzero(buf,sizeof(buf));
		if(judge.mode == 0){
				struct spwd *pspwd;
				char *p = NULL;
				pspwd = getspnam(judge.uoc.user);
				if(pspwd == NULL)
						return -1;
				p = crypt(judge.pod.passwd,pspwd->sp_pwdp);
				if( strcmp(p,pspwd->sp_pwdp) == 0)
						return 0;
				else
						return -1;
		}
		int fid;
		fid = open("file2",O_RDWR|O_CREAT|O_EXCL,0600);
		if(fid < 0){
				if(errno == EEXIST){
						fid = open("file2",O_RDWR);
						if(fid < 0){
								perror("open-1");
								return -2;
						}
				}else{
						perror("open-2");
						return -3;
				}
		}
		deal_apply(judge.uoc.cmd,fid,sockfd);
		lseek(fid,0,SEEK_SET);
		while(1){
				bzero(buf,sizeof(buf));
				int ret = read(fid,buf,1);
				if(ret <= 0)
						break;
				else
						write(sockfd,buf,strlen(buf));
		}

		system("rm -f file2");
				
				
}

/*
 *ls cd get cat mkdir pwd
 *
 */

int deal_apply(char *cmd,int fd,int sockfd)
{
		int len = 0;
		char str[3] ;
		bzero(str,sizeof(str));

		char *buf;
		buf = (char *)malloc(200*sizeof(char *));
		bzero(buf,sizeof(buf));

		char tmp[200];
		bzero(tmp,sizeof(tmp));

		char content[100];
		//content = (char *)malloc(200);
		bzero(content,sizeof(content));

		strncpy(str,cmd,1);
		int ret;
		int num,n;
		char string[200];
		int fd_tmp;
		char ch;
        switch(str[0])
        {
            case 'l':  //ls /home
					fd_tmp = open("a.txt",O_RDWR|O_CREAT|O_EXCL);
					if(fd_tmp < 0)
					{
						if(errno == EEXIST)
						{
							fd_tmp = open("a.txt",O_RDWR);
							if(fd_tmp < 0)
							{
								perror("open-ls");
								return -1;
							}
						}
					}
					strcat(cmd," > a.txt");
					system(cmd);
					lseek(fd_tmp,0,SEEK_END);
					bzero(buf,sizeof(buf));
					strcat(buf,"^");
					write(fd_tmp,buf,1);

					lseek(fd_tmp,0,SEEK_SET);
					while(1)
					{
							bzero(buf,sizeof(buf));
							num = read(fd_tmp,buf,1);
							if(num <= 0)
							{
									return -1;
							}
							printf("%s",buf);
							write(fd,buf,num);

					}
					close(fd_tmp);
					system("rm -f a.txt");
                    break;

            case 'c':   //cd /home
					bzero(buf,sizeof(buf));
					strcat(buf,"c");
					write(fd,buf,1);
					chdir(cmd+3);
                    break;

            case 'g': //get a
					bzero(string,sizeof(string));
					strcat(string,"~");
				
					strcat(string,&cmd[4]);
					printf("cmd:%s\n",cmd);
					num = write(fd,string,sizeof(string)); 
					if(num < 0)
					{
						perror("write");
						return -1;
					}					

					int fid = open(cmd+4,O_RDWR);
					if(fid< 0)
					{
						perror("open");
						return -1;
					}

					while(1)
					{
							bzero(buf,sizeof(buf));
							ret = read(fid,buf,sizeof(buf));
							if(ret <= 0)
							{
									sleep(0.001);
									write(fd,"^",1);			
									break;
							}
							else
									write(fd,buf,ret);							
					}					
					close(fid);
					break;

			case 'm': //mkdir file file1
					
					bzero(buf,sizeof(buf));
					strcat(buf,"m");
					write(fd,buf,1);
					system(cmd);
					break;

            case 'p': //pwd
					if(cmd[1] == 'w'){
                    		getcwd(content,sizeof(content));
							printf("content:%s\n",content);
							write(fd,content,strlen(content));
							bzero(buf,sizeof(buf));
							strcat(buf,"^");
							write(fd,buf,1);
					}else if(cmd[1] == 'u'){
							puts("put");
							bzero(str,sizeof(str));
							strcat(str,"p");
							write(sockfd,str,1);
							write(sockfd,cmd+4,strlen(cmd+4));
							int fd_put  = open(cmd+4,O_RDWR|O_EXCL|O_CREAT,0600);
							if(fd_put < 0)
							{
									if(errno == EEXIST)
									{
											printf("文件已存在，是否覆盖？(y/n)\n");
											scanf("%c",&ch);
											if(ch == 'y')
											{
													fd_put = open(cmd+4,O_RDWR);
													if(fd_put < 0)
													{
															perror("open-put");
															return -1;
													}
											}
											if(ch == 'n')
											{
													printf("取消下载.\n");
													return -1;
											}             
									}
									else
									{
											perror("open");
											return -1;
									}
							}
							while(1)
							{
									bzero(buf,sizeof(buf));
									ret = read(sockfd,buf,1);
									printf("buf:%s\n",buf);
									if(buf[strlen(buf)-1] == '^')
									{
											break;
									}
									if(ret <= 0)
									{
											break;
									}
									write(fd_put,buf,ret);

							}

							close(fd_put);
							return 10;
					}
					else
							printf("cmd error.\n");
					break;
			default:
					printf("cmd error.\n");
					break;
		}
}
