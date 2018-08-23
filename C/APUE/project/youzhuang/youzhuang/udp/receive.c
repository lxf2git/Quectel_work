#include"main.h"

void swap(char *p)
{
		while(*p!=0)
		{
				if(*p >= 'a' && *p <= 'z')
				{
						*p-=32;
				}
				p++;
		}
}

int main()
{
		char buf[256];
		struct sockaddr_in addr, src_addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(5678);
		addr.sin_addr.s_addr = htonl(INADDR_ANY);

		int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
		if(sockfd < 0 )
		{
				perror("socket");
				exit(-1);
		}
		int ret = bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));
		if(ret < 0)
		{
				perror("bind");
				close(sockfd);
				exit(-1);
		}

		int len = sizeof(src_addr);
		int size = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&src_addr, &len);
		if(size < 0)
		{
				perror("recvfrom");
				close(sockfd);
				exit(-1);
		}
		printf("%s\n",buf);
		swap(buf);

		size = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&src_addr, sizeof(src_addr));
		if(size < 0)
		{
				perror("recvfrom");
				close(sockfd);
				exit(-1);
		}

		close(sockfd);
		return 0;
}
