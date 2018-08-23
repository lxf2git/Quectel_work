#include"main.h"
void swap(char *p)
{
		while(*p!=0)
		{
				if(*p>='a' && *p<='z')
				{
						*p-=32;
				}
				p++;
		}
}

int main()
{
		int sockfd = socket(AF_INET, SOCK_STREAM, 0);
		if(sockfd < 0)
		{
				perror("socket");
				exit(-1);
		}

		struct sockaddr_in selfaddr, conaddr;
		selfaddr.sin_family = AF_INET;
		selfaddr.sin_port = htons(8888);
		selfaddr.sin_addr.s_addr = htonl(INADDR_ANY);
		int ret = bind(sockfd, (struct sockaddr*)&selfaddr, sizeof(selfaddr));
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

		char buf[256];
		read(confd, buf, sizeof(buf));
		printf("%s\n", buf);
		swap(buf);
		write(confd, buf, strlen(buf)+1);

		close(confd);
		return 0;
}
