#include"main.h"

int main(int argc, char **argv)
{
		if(argc < 3)
		{
				perror("ip");
				exit(-1);
		}
		char buf[256];
		struct sockaddr_in seraddr;
		int sockfd = socket(AF_INET, SOCK_STREAM, 0);
		if(sockfd < 0)
		{
				perror("socket");
				exit(-1);
		}
		seraddr.sin_family = AF_INET;
		seraddr.sin_port = htons(atoi(argv[2]));
		seraddr.sin_addr.s_addr = inet_addr(argv[1]);
		int ret = connect(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
		if(ret < 0)
		{
				close(sockfd);
				perror("connect");
				exit(-1);
		}
		scanf("%s",buf);
		write(sockfd, buf, strlen(buf)+1);
		read(sockfd, buf, sizeof(buf));
		printf("%s\n", buf);

		close(sockfd);
}
