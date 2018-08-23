#include"main.h"

int main(int argc, char **argv)
{
		if(argc < 3)
		{
				perror("ip");
				exit(-1);
		}
		char buf[256];

		struct sockaddr_in sevaddr;
		sevaddr.sin_family = AF_INET;
		sevaddr.sin_port = htons(atoi(argv[2]));
		sevaddr.sin_addr.s_addr = inet_addr(argv[1]);

		int sockfd = socket(AF_INET, SOCK_STREAM, 0);
		if(sockfd < 0)
		{
				perror("sockfd");
				exit(-1);
		}

		int ret = connect(sockfd, (struct sockaddr *)&sevaddr, sizeof(sevaddr));
		if(ret < 0)
		{
				perror("connect");
				exit(-1);
		}

		while(1)
		{
		scanf("%s", buf);
		write(sockfd, buf, strlen(buf)+1);
		memset(buf, 0, sizeof(buf));
		read(sockfd, buf, sizeof(buf));
		printf("%s\n", buf);
		}

		close(sockfd);
		return 0;
}
