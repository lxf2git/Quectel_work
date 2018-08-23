#include"main.h"

int main(int argc, char **argv)
{
		if(argc < 3)
		{
				perror("ip");
				exit(-1);
		}

		struct sockaddr_in dest_addr;
		dest_addr.sin_family = AF_INET;
		dest_addr.sin_port = htons(atoi(argv[2]));
		dest_addr.sin_addr.s_addr = inet_addr(argv[1]);;

		int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
		if(sockfd < 0)
		{
				perror("socket");
				exit(-1);
		}

		char buf[256];
		scanf("%s",buf);
		int size = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
		if(size < 0)
		{
				perror("sendto");
				close(sockfd);
				exit(-1);
		}

		int len = sizeof(dest_addr);
		size = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&dest_addr, &len);
		if(size < 0)
		{
				perror("sendto");
				close(sockfd);
				exit(-1);
		}
		printf("%s\n",buf);

		close(sockfd);
		return 0;
}
