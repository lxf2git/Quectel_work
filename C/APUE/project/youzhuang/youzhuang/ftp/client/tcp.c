#include"ftp.h"

int send_information(void *buf)
{
	int ret,sockfd;//判断返回的结果
        struct sockaddr_in selfaddr;
        sockfd = socket(AF_INET,SOCK_STREAM,0);
        if(sockfd<0)
        {
        	perror("socket");
                return FAIL;
        }

	bzero(&selfaddr,sizeof(selfaddr));
        selfaddr.sin_family = AF_INET;
        selfaddr.sin_port = htons(8888);
        selfaddr.sin_addr.s_addr = inet_addr(ser_ip);
        ret = connect(sockfd,(struct sockaddr *)&selfaddr,sizeof(struct sockaddr_in));
        if(ret<0)
        {
        close(sockfd);
        return FAIL;
        }

	ret = write(sockfd,buf,sizeof(struct cli_to_ser));
	close(sockfd);	
	if(ret<0)
	{
			return FAIL;
	}
	return SUC;
}

int receive_information( void *buf)
{

	struct sockaddr_in selfaddr,conaddr;
        char get_buf[1024];
        int ret,fd,n;
        bzero(&get_buf,sizeof(get_buf));
        socklen_t len = sizeof(struct sockaddr_in);
        int sockfd = socket(AF_INET,SOCK_DGRAM,0);
        if(sockfd<0)
        {
                perror("socket");
        }
        bzero(&selfaddr,sizeof(selfaddr));
        selfaddr.sin_family = AF_INET;
        selfaddr.sin_port = htons(8887);
        selfaddr.sin_addr.s_addr = htonl(INADDR_ANY);

        ret = bind(sockfd,(struct sockaddr *)&selfaddr,sizeof(selfaddr));
        if(ret<0)
        {
                close(sockfd);
                perror("bind");
        }

        n = recvfrom(sockfd,buf,1024,0,(struct sockaddr *)&conaddr,&len);
        close(sockfd);
        if(n<0)
	{
		perror("recvform");
		return FAIL;
	}
	return SUC;
}
