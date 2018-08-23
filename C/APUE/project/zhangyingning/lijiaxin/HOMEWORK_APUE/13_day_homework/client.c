#include"../../apue.h"

int main(int argc,char **argv)
{
		if(argc!=3)
		{
				perror("no argument");
				exit(-1);
		}

		char buf[50];
		struct sockaddr_in seraddr;
		bzero(buf,sizeof(buf));
		bzero(&seraddr,sizeof(seraddr));

		int sockfd = socket(AF_INET,SOCK_STREAM,0);
		if(sockfd<0)
		{
				perror("socket");
				exit(-1);
		}

		seraddr.sin_family = AF_INET;
		seraddr.sin_port = htons(atoi(argv[2]));
		seraddr.sin_addr.s_addr = inet_addr(argv[1]);
		int ret = connect(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));

		printf("please enter need to op string\n");
		scanf("%s",buf);
		write(sockfd,buf,sizeof(buf)+1);
		bzero(buf,sizeof(buf));
		usleep(100);
		read(sockfd,buf,sizeof(buf));
		printf("%s\n",buf);

		return 0;
}
