#include "ftp.h"


int getfile(void *buf,char *filename)
{
	struct sockaddr_in selfaddr,conaddr;
	char get_buf[1024];	
	int ret,fd,n;
	char verify;
	struct cli_to_ser data;
	bzero(&get_buf,sizeof(get_buf));
	socklen_t len = sizeof(struct sockaddr_in);
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd<0)	
	{
		perror("socket");
	}
	bzero(&selfaddr,sizeof(selfaddr));
	selfaddr.sin_family = AF_INET;
	selfaddr.sin_port = htons(8887);
	selfaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	ret = bind(sockfd,(struct sockaddr *)&selfaddr,sizeof(selfaddr));
	if(ret<0)
	{
		close(sockfd);
		perror("bind");
	}
	fd = open(filename,O_WRONLY|O_CREAT|O_EXCL,0666);
	if(fd < 0)
	{
		printf("当前文件已存在，是否覆盖!Y/N\n");
		scanf("%c",&verify);
		getchar();
		if(verify=='Y'||verify=='y')
		{
			fd = open(filename,O_RDWR);
			if(fd<0)
			{
				perror("open");
				data.cmd = FAIL;
				send_information(&data);
				return SUC;
			}
			else
			{
			data.cmd = SUC;
			send_information(&data);
			while(1)
			{
				recvfrom(sockfd,get_buf,sizeof(get_buf),0,(struct sockaddr *)&conaddr,&len);
				write(fd,get_buf,strlen(get_buf));
				if(strlen(get_buf)<1024)
				{
					break;
				}
			}
			printf("下载成功!\n");
			close(fd);
			close(sockfd);
			return SUC;
			}
		}
		else
		{
			data.cmd = FAIL;
			send_information(&data);
			return SUC;
		}
	}
	else
	{
		data.cmd = SUC;
		send_information(&data);
		for(;;)
		{
			n = recvfrom(sockfd,get_buf,sizeof(get_buf),0,(struct sockaddr *)&conaddr,&len);

			write(fd,get_buf,strlen(get_buf));
			if(strlen(get_buf)<1024)
			{
				break;
			}
		}
		printf("下载成功!\n");
		close(fd);
		close(sockfd);
	}
	return SUC;

}

int putfile(void *buf,char *filename)
{
	int fd;
	char put_buf[100];
	struct cli_to_ser data;
	int ret,sockfd;//判断返回的结果
	struct sockaddr_in selfaddr;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
	printf("13**\n");
		perror("socket");
		return FAIL;
	}

	bzero(&selfaddr,sizeof(selfaddr));
	selfaddr.sin_family = AF_INET;
	selfaddr.sin_port = htons(8888);
	selfaddr.sin_addr.s_addr = inet_addr(ser_ip);
	ret = connect(sockfd,(struct sockaddr *)&selfaddr,sizeof(struct sockaddr_in));
	if(ret<0)
	{
	printf("23**\n");
		close(sockfd);
		return FAIL;
	}
	fd = open(filename,O_RDWR);
	if(fd<0)
	{
	printf("3**\n");
		perror("open");
		return SUC;
	}
	int len;
	while(1)
	{
		data.cmd = SUC;
		bzero(&data.farg.ftp_put_file,sizeof(data.farg.ftp_put_file));
		len = read(fd,data.farg.ftp_put_file,100);
		send_information(&data);
		//bzero(&put_buf,sizeof(put_buf));
		//len = read(fd,put_buf,99);
		//write(sockfd,put_buf,strlen(put_buf));
		if(len<=0)
		{
			data.cmd = FAIL;
			send_information(&data);
			break;
		}
	}
	printf("上传成功!\n");
	close(fd);
	close(sockfd);


}

int get_client(char *command)
{
	int ret;
	char filename[100],buf[1024];
	memset(buf,0,sizeof(buf));
	memset(filename,0,sizeof(filename));
	struct cli_to_ser data;
	data.cmd = GET;
	strcpy(filename,command+4);
	strcpy(data.farg.ftp_get_file,filename);

	send_information(&data);
	getfile(&data,filename);
	return SUC;
}


int put_client(char *command)
{
	char filename[100];
	struct cli_to_ser data;
	char verify;
	int buf;
	data.cmd = PUT;
	strcpy(filename,command+4);
	strcpy(data.farg.ftp_put_file,filename);

	send_information(&data);
	receive_information(&buf);
	if(buf==0)
	{
		putfile(&data,filename);
	}
	else
	{
		printf("当前文件已存在，是否覆盖?Y/N\n");
		scanf("%c",&verify);
		getchar();
		if(verify=='y'||verify=='Y')
		{
			data.cmd=SUC;
			send_information(&data);
			putfile(&data,filename);
		}
		else
		{
			data.cmd=FAIL;
			send_information(&data);
			return SUC;
		}
	}
}

int main(int argc,char **argv)
{
	int ret;
	if(argc!=2)
	{
		perror("argument");
	}
	strcpy(ser_ip,argv[1]);
	ret = login();
	if(ret < 0)
	{
		exit(-1);
	}

	char command[256];
	bzero(command,sizeof(command));
	while(1)
	{
		printf("ftp > ");
		scanf("%[^\n]",command);
		getchar();
		if(strncmp(command,"get",3)==0)
		{
			get_client(command);//客户端 get
			bzero(command,sizeof(command));
		}
		if(strncmp(command,"put",3)==0)
		{
			put_client(command);//客户端 put
			bzero(command,sizeof(command));
		}
		else
		{
			other_command_client(command);
		}

	}

}
