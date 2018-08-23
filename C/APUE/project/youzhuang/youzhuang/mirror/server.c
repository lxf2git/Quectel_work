#include"main.h"

int main()
{
		char buf[256];
		struct sockaddr_in selfaddr, conaddr;
		selfaddr.sin_family = AF_INET;
		selfaddr.sin_port = htons(8888);
		selfaddr.sin_addr.s_addr = htonl(0);
		int sockfd = socket(AF_INET, SOCK_STREAM, 0);
		if(sockfd < 0)
		{
				perror("socket");
				exit(-1);
		}

		int ret = bind(sockfd, (struct sockaddr *)&selfaddr, sizeof(selfaddr));
		if(ret < 0)
		{
				perror("bind");
				close(sockfd);
				exit(-1);
		}

		listen(sockfd, 10);

		int len = sizeof(conaddr);
		int confd = accept(sockfd, (struct sockaddr *)&conaddr, &len);
		if(confd < 0)
		{
				perror("accept");
				close(sockfd);
				exit(-1);
		}
while(1)
{
		read(confd, buf, sizeof(buf));
		printf("%s\n", buf);
		write(confd, buf, strlen(buf)+1);
}

		close(confd);
		return 0;
}
