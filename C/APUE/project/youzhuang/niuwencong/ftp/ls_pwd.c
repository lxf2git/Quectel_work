#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int ls_pwd(int sockfd,int dest_port,char *command)
{
	char buf[1024];
	char buf_command[50];
	memset(buf,0,sizeof(buf));
	memset(buf,0,sizeof(buf_command));
	sprintf(buf_command,"%s > /dev/null 2>&1",command);
	system(buf_command);
	read(stderr,buf,sizeof(buf));
	write(1,buf,strlen(buf));
	//sent_information(buf,sockfd);
	return 0;
}
