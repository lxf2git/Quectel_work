#include "service.h"
void my_look(int sig);
int main()
{
//		signal(SIGUSR1,my_exit);
//		signal(SIGCHLD,my_wait);
		int sockfd = socket(AF_INET,SOCK_DGRAM,0);
		if(sockfd == -1)
		{
				perror("socket");
				exit(0);
		}
		struct sockaddr_in saddr,caddr;
		int len = sizeof(caddr);
		bzero(&saddr,sizeof(saddr));
		saddr.sin_family = AF_INET;
		saddr.sin_addr.s_addr = htonl(INADDR_ANY);
		saddr.sin_port = htons(7563);
		int ret = bind(sockfd,(struct sockaddr*)&saddr,sizeof(saddr));
		if(ret == -1)
		{
				perror("bind");
				exit(-1);
		}
		int fdPipe[2];
		ret = pipe(fdPipe);
		printf(YEL"service 创建处理管道"NONE"\n");
		if(ret == -1)
		{
				perror("pipe");
				exit(-1);
		}
		int pid = fork();
		if(pid!=0)
		{
				usleep(1000*100);
				read_data(sockfd,caddr,fdPipe);

		}


		else
		{
				deal_pess(fdPipe);
				exit(0);


		}
		return 0;

}
int read_data(int sockfd,struct sockaddr_in caddr,int *fdPipe)
{
		sData bufData;
		int len = sizeof(caddr);
		close(fdPipe[0]);
		while(1)
		{
				printf(YEL"service 等待数据"NONE"\n");
				bzero(&bufData,sizeof(bufData));
				int ret ;
				ret = recvfrom(sockfd,&bufData,sizeof(bufData),0,(struct sockaddr *)&caddr,&len);
				printf(YEL"service 数据读入"NONE"\n");
				if(ret < 0)
				{
						perror("recvfrom");
						exit(-1);
				}
				printf(RED"ip(%s) id(%d):->"WIT" us: %s ps:%s"NONE"\n",inet_ntoa(caddr.sin_addr),ntohs(caddr.sin_port),bufData.uoc.cmd,bufData.pod.data);
				strcpy(bufData.addr,inet_ntoa(caddr.sin_addr));
				printf(YEL"service 添加IP"NONE"\n");
				printf(YEL"service: mode %d"NONE"\n",bufData.mode);
				write(fdPipe[1],&bufData,sizeof(bufData));
				printf(YEL"service 写入处理管道"NONE"\n");
				if(my_strcmp(bufData.uoc.cmd) == 1)
				{
						printf(GREED"service:%s:go away"NONE"\n",inet_ntoa(caddr.sin_addr));
				}
		}
		return 0;

}


int my_strcmp(char *buf)
{
		if(buf[0]=='b'  && buf[1]=='y')
				return 1;
		else
				return 0;

}
void my_wait(int sig)
{
		while(waitpid(-1,NULL,WNOHANG) >0)
				;
}
void my_exit(int sig)
{
		if(getpid() != getpgrp())
		{
				printf("%d\n",getpid());
				exit(0);
		}
}
void my_jump(int sig)
{
		if(sig == SIGPIPE)
		{
				printf("SICPIPE\n");
		}
		else
				printf("time over\n");

}
void my_look(int sig)
{
		printf("sigpipe\n");
}
