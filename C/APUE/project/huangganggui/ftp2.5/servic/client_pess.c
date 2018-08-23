

#include "service.h"
int client_pess(char* name,int semid,struct sembuf buf)
{
		printf(PRO"client_pess"NONE"\n");
		sData bufData;
		int cockfd = socket(AF_INET,SOCK_STREAM,0);
		struct sockaddr_in caddr;
		bzero(&caddr,sizeof(caddr));
		caddr.sin_family = AF_INET;
		caddr.sin_port = htons(8888);
		caddr.sin_addr.s_addr = inet_addr(name);
		if(connect(cockfd,(struct sockaddr*)&caddr,sizeof(caddr)) < 0)
		{
				perror("8888 conect");
				return -1;
		}
		printf(PRO"client 链接客户8888"NONE"\n");

		int fd = open(name,O_RDWR);
		if(fd < 0)
		{
				perror("open client	");
				exit(-1);
		}
		printf(PRO"client 打开管道"NONE"\n");
		int ret;
		while(1)
		{
				bzero(&bufData,sizeof(bufData));
				printf(PRO"client 读管道"NONE"\n");
				ret = read(fd,&bufData,sizeof(bufData));
				if(ret < 0)
				{
						printf("ret:%d\n",ret);
						perror("read");
						close(cockfd);
						exit(-1);
				}
				if(ret == 0)
				{
						printf(RED"client 管道关闭 子进程结束"NONE);
						close(fd);
						exit(0);
				}
				if( (bufData.mode == 0) | (my_strcmp(bufData.uoc.cmd) == 1) )
				{
						sData bufPw;
						printf(PRO"user:%s passwd:%s"NONE"\n",bufData.uoc.user,bufData.pod.passwd);
						buf.sem_op = 1;
						semop(semid,&buf,1);
						if(bufData.mode == 0)
						{
								ret =deal_child_process(bufData,cockfd);
								ret = 0;
						}
						else
						{
								printf(GREED"client%s:go away"NONE"\n",inet_ntoa(caddr.sin_addr));
								ret = 3;
						}
						send_data(cockfd,ret);
						sprintf(bufPw.uoc.cmd,"%d",ret);
						write(fd,&bufPw,sizeof(bufPw));	
						if(ret != 0 )
						{
								printf(RED"子进程结束 密码错误"NONE"\n");
								close(fd);
								exit(0);
						}
				}

				else
						deal_child_process(bufData,cockfd);
		}


}




int send_data(int sockfd,int mode)
{
		sData bufData;

		bzero(&bufData,sizeof(bufData));
		if(mode == 0)
		{
				printf(PRO"passwd Ok\n");
				sprintf(bufData.uoc.cmd,"succed");
		}

		if(mode == -1)
		{
				printf(RED"passwd error"NONE"\n");
				sprintf(bufData.uoc.cmd,"f");
		}
		if(mode == 2)
		{
				printf(PRO"通知客户重复"NONE"\n");
				sprintf(bufData.uoc.cmd,"double");
		}

		if(mode == 3)
		{
				printf(PRO"通知客户结束"NONE"\n");
				sprintf(bufData.uoc.cmd,"$");
		}

		printf(PRO"写入客服8888端口"NONE"\n");
		int ret = write(sockfd,&bufData,sizeof(bufData));
		if(ret == -1)
		{
				perror("write");
				return -1;
		}

}





















