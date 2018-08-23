#include "main.h"


int get_client(struct cli_to_ser get_command,int sockfd)
{
	printf("get_command.cmd:%d ftp_get_file:%s\n",get_command.cmd,get_command.farg.ftp_get_file);
	//send_information(get_command,sockfd);
	char filebuff[1024*20],fileinfo[100],filename[20];
	strcpy(filename,get_command.farg.ftp_get_file);
	printf("file to save as:%s\n",filename);
	int Creat;
	Creat = open(filename,O_WRONLY|O_CREAT|O_EXCL,0666);
	if(Creat>=0)
	{
		perror("open");
		return 0;
	}
	memset(filebuff,0,1024*20);
	//receive_course(filebuff);
	write(Creat,filebuff,sizeof(filebuff));
	close(Creat);
	printf("文件下载成功\n");
}


int put_client(struct cli_to_ser put_command,int sockfd)
{
	printf("command.cmd:%d ftp_put_file:%s\n",put_command.cmd,put_command.farg.ftp_put_file);
	//send_information(command,sockfd);
        char filebuff[1024*20],fileinfo[100],filename[20];
	strcpy(filename,put_command.farg.ftp_put_file);
	int Read;
	Read = open(filename,O_RDONLY);
	if(Read<0)
	{
		perror("open");
		return 0;
	}
	int len = read(Read,filebuff,sizeof(filebuff));
	if(len==0)
	{
		perror("null file");
	}
	printf("%s\n",filebuff);
	//send_course(filebuff);//进程发送
	close(Read);
	printf("文件上传成功\n");
}

int main(int argc,char **argv)
{
	if(argc!=3)
	{
		perror("argument");
	}
	struct sockaddr_in addr;
	int sockfd;
	bzero(&addr,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[2]));
	addr.sin_addr.s_addr = inet_addr(argv[1]);
	//getsocket(struct sockaddr_in addr, int *sockfd);//获得sockfd
	int ret = login();//登录
	if(ret==-1)
	{
		perror("login");
		return 0;
	}	
	printf("argv[1]:%s,argv[2]:%s\n",argv[1],argv[2]);
	char arg[256];
while(1)
{
	printf("ftp > ");
        scanf("%[^\n]",arg);
        if(strncmp(arg,"get",3)==0)
        {
		char filename[20];
		struct cli_to_ser get_command;
		get_command.cmd = GET;
		strcpy(filename,arg+4);
		strcpy(get_command.farg.ftp_get_file,filename);
		get_client(get_command,sockfd);//客户端 get
		printf("get_command.cmd:%d filename:%s\n",get_command.cmd,filename);
		bzero(arg,sizeof(arg));
	}
	if(strncmp(arg,"put",3)==0)
	{
		char filename[20];
		strcpy(filename,arg+4);
		struct cli_to_ser put_command;
		put_command.cmd = PUT;
		strcpy(put_command.farg.ftp_put_file,filename);
		put_client(put_command,sockfd);//客户端 put
		printf("put_command.cmd:%d filename:%s\n",put_command.cmd,filename);
		bzero(arg,sizeof(arg));
	}
	else
	{
		break;
	}

}

}
