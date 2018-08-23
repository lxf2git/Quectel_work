#include "ftp.h"


int get_client(char *command, int sockfd)
{
		int fd,ret;
		char filename[100],buf[1024];
		memset(buf,0,sizeof(buf));
		memset(filename,0,sizeof(filename));
		struct cli_to_ser data;
		data.cmd = GET;
		strcpy(filename,command+4);
		strcpy(data.farg.ftp_get_file,filename);

		send_information(&data,sockfd);
		receive_information(&data,sockfd);
		fd = open(filename,O_WRONLY|O_CREAT|O_EXCL,0666);
		if(fd < 0)
		{
				perror("open");
				return FAIL;
		}
		while(1)
		{
				ret = read(sockfd,buf,sizeof(buf));
				if(ret <= 0)
				{
						break;
				}
				write(fd,buf,sizeof(buf));
		}
		close(fd);
}


int put_client(char *command,int sockfd)
{
		char *buf,filename[100];
		struct cli_to_ser data;
		data.cmd = GET;
		strcpy(filename,command+4);
		strcpy(data.farg.ftp_get_file,filename);

		send_information(&data,sockfd);
		int fd;
		fd = open(filename,O_RDONLY);
		if(fd<0)
		{
				perror("open");
				return 0;
		}
		int len;
		while(1)
		{
				len = read(fd,buf,sizeof(buf));
				if(len <= 0)
				{
						perror("null file");
						return FAIL;
				}
				write(sockfd,buf,sizeof(buf));
		}
		close(fd);
}

int main(int argc,char **argv)
{
		int sockfd;
		if(argc!=2)
		{
				perror("argument");
		}

		struct sockaddr_in addr;
		bzero(&addr,sizeof(addr));
		addr.sin_family = AF_INET;
		addr.sin_port = htons(8888);
		addr.sin_addr.s_addr = inet_addr(argv[1]);
		int ret = getsocket(&addr, &sockfd);//获得sockfd
		if(ret < 0)
		{
				perror("getsocket");
				exit(-1);
		}
		ret = getsocket(NULL, &sockfd);//获得sockfd
		if(ret < 0)
		{
				perror("getsocket");
				exit(-1);
		}
		ret = login(sockfd);
		if(ret < 0)
		{
				perror("login");
				close(sockfd);
				exit(-1);
		}
/*		
		char command[256];
		bzero(command,sizeof(command));
		while(1)
		{
				printf("ftp > ");
	  			scanf("%[^\n]",command);
				getchar();
 				if(strncmp(command,"get",3)==0)
			 	{
						get_client(command,sockfd);//客户端 get
						bzero(command,sizeof(command));
				}
				if(strncmp(command,"put",3)==0)
				{
						put_client(command,sockfd);//客户端 put
						bzero(command,sizeof(command));
				}
				else
				{
						other_command_client(command,sockfd);
				}

		}
*/
}
