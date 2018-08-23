#include "qqclient.h"
int Recv_addfriend(sData_package package,Socks Socks)
{
		int fd = open(package.sourceAddr,O_CREAT|O_APPEND);
		char buf[1024];
		bzero(buf,sizeof(buf));
		sprintf(buf,"好友请求(%s)\n",package.sourceAddr);
		write(fd,buf,sizeof(buf));
		printf(GRE"你有新的好友请求(%s)"NONE"\n",package.sourceAddr);
		sData_package send_friend;
		send_friend.mode = FRIENDRE;
		sprintf(send_friend.destAddr,"%s",package.sourceAddr);
		SendToService(Socks,send_friend);
		close(fd);
		return 0;
}


int Recv_file(sData_package package,Socks Socks)
{
		int fd,ch;
		if( strncmp(package.fileName,"$",1) == 0)
		{
				printf("you want file down%s",package.fileName);
				ch == getchar();
				if(ch == 'n')
						return 0;
				fd = open(package.fileName+1,O_WRONLY|O_CREAT|O_EXCL,0666);
				if(fd == -1)
				{
								perror(package.fileName+1);
								printf("overwrite? y/n\n");
						if(errno == EEXIST)
						{
								ch = getchar();
								if(ch == 'n')
										return 0;
						
						}
						else
								return -1;
				}
				close(fd);
		}
		else
		{
				fd = open(package.fileName,O_WRONLY|O_APPEND);
				write(fd,package.dorinform.data,strlen(package.dorinform.data));
				close(fd);
		}
		return 0;
}

int Recv_tell(sData_package package,Socks Socks)
{
	
		int fd = open(package.destAddr,O_CREAT|O_APPEND);
		char buf[1024];
		bzero(buf,sizeof(buf));
		sprintf(buf,"from(%s):(%s):%s\n",package.sourceAddr,package.time,package.dorinform.data);
		write(fd,buf,sizeof(buf));
		printf("(%s):(%s):%s\n",package.sourceAddr,package.time,package.dorinform.data);
		close(fd);
		return 0;
}
