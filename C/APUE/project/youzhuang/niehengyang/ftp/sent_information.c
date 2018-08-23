#include "main.h"

int send_information(char *command,int sockfd)
{
	char information[100];
	printf("请输入发送信息\n");
	read(0,information,strlen(information));
	
}
