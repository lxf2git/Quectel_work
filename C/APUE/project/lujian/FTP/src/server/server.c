#include "../include/ftp.h"
#include "server.h"
#include "../include/list.h"


struct list user_list_head;
int logfd;
int ser_deal_cmd(int confd, struct cli_ser_pakg lv_cli_ser_pakg,  \
			   	struct sockaddr_in conaddr);	
static void sig_wait(int signo);
int deal_process(int sockfd, struct cli_ser_pakg lv_cli_ser_pakg, struct sockaddr_in conaddr);
void init_list(struct list*node);

int main() 
{
	
		daemon(0,  0);
		signal(SIGCHLD, sig_wait);
		init_list(&user_list_head);
		
		int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
		int reuse =1;
		setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (void*)&reuse, sizeof(int));
		if (sockfd < 0)
		{
				perror("socket");
				exit(-1);
		}

		int confd;
		struct sockaddr_in seraddr, conaddr;
		socklen_t len = sizeof(conaddr);
		memset(&seraddr, 0, sizeof(seraddr));
		memset(&conaddr,0, sizeof(conaddr));

		seraddr.sin_family = AF_INET;
		seraddr.sin_port   = htons(6666);
		seraddr.sin_addr.s_addr = htonl(INADDR_ANY);

		int re;
		re = bind(sockfd, (struct sockaddr*)&seraddr, sizeof(seraddr));
		if (re < 0)
		{
				perror("bind");
				goto Err;
		}

		pid_t pid;
		struct cli_ser_pakg lv_cli_ser_pakg;
		memset(&lv_cli_ser_pakg, 0, sizeof(lv_cli_ser_pakg));
		umask(0);
		mkdir("/tmp/ftp", 0777);
		logfd = open("/tmp/ftp/log", O_RDWR|O_CREAT|O_TRUNC, 0666);
		if (logfd < 0)
		{
			perror("open");
			exit(-1);
		}

		while(1)
		{		
				re = recvfrom(sockfd, &lv_cli_ser_pakg, sizeof(lv_cli_ser_pakg), 0,	(struct sockaddr*)&conaddr, &len);
		 		if (re < 0)
				{
						perror("recvfrom");
						goto Err;
				}

				if ((re = deal_process(sockfd, lv_cli_ser_pakg, conaddr)) < 0)
				{
						continue;
				}
				
				else if (re == 0)
				{
						if ((pid = fork()) < 0)

						{
								perror("fork");
								goto Err;	
						}
						else if (pid == 0)
						{
								char usr_home_dir[256];
								bzero(usr_home_dir, sizeof(usr_home_dir));
								sprintf(usr_home_dir,"/home/%s",
												lv_cli_ser_pakg.cli_info.username);

								if (chdir(usr_home_dir) < 0)
								{
										perror("chdir");
										goto Err;
								}

								char fifo_path[256];
								memset(fifo_path, 0, sizeof(fifo_path));
								sprintf(fifo_path, "/tmp/ftp/%s-%d", 
												inet_ntoa(conaddr.sin_addr), ntohs(conaddr.sin_port));
								int fifo_rfd;
								printf("[%s = %d line] \n", __FUNCTION__, __LINE__ ); 
								printf("fifo:%s\n", fifo_path);
								fifo_rfd = open(fifo_path, O_RDONLY);
								printf("[%s = %d line] \n", __FUNCTION__, __LINE__ ); 
								if (fifo_rfd < 0)
								{
										printf("[%s = %d line] \n", __FUNCTION__, __LINE__ ); 
										perror("open");
										goto Err;
								}
								while(1)
								{
										re = read(fifo_rfd, &lv_cli_ser_pakg, sizeof(lv_cli_ser_pakg));
										if (re < 0)
										{
												perror("read");
												close(fifo_rfd);
												goto Err;
										}	
										else if (re == 0)
										{
												break;
										}
										else
										{
											if (ser_deal_cmd(sockfd, lv_cli_ser_pakg, conaddr) == QUIT)	
												break;
										}
										
								}
										close(sockfd);
										unlink(fifo_path);
										exit(0);		
						}
				}
		}

		close(sockfd);
		return TURE; 
Err:
		close(sockfd);
		close(confd);
		return FALSE;  
}

void sig_wait(int  signo)
{
	switch(signo)
	{	
		case SIGCHLD:  
				{
				while(waitpid(-1, NULL, WNOHANG) > 0);
				break;		
				}	
			default:
				{
					break;
				}
	}
		return;
}



