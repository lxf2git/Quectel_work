#include"apue.h"
struct client_myinfo
{
        int id;
        char virtual_name[20];
        char birthday[11];
        char telephone_num[12];
        char gender[4];
        char vip;
        char real_name[20];
        int age;
};

void *reciv()
{
		printf("按#键退出聊天室\n");
		int sockfd1;
		struct sockaddr_in selfaddr;
		char buf2[1024]={0};
		sockfd1 = socket(AF_INET,SOCK_DGRAM,0);
		bzero(&selfaddr,sizeof(selfaddr));
		selfaddr.sin_family = AF_INET;
		selfaddr.sin_port = htons(5677);
		selfaddr.sin_addr.s_addr = htonl(INADDR_ANY);
		bind(sockfd1,(struct sockaddr*)&selfaddr,sizeof(selfaddr));
		while(1)
		{
			bzero(&buf2,sizeof(buf2));
			recvfrom(sockfd1,buf2,sizeof(buf2),0,NULL,NULL);
			printf("%s\n",buf2);
		}

		pthread_exit(NULL);	
}
int room(struct client_myinfo myinfo)
{
	int n;	
	struct sockaddr_in conaddr;
	int on = 1;
	socklen_t len = sizeof(struct sockaddr_in);
	char buf3[1024]={0};
	char buf1[1024]={0};	
	char myname[20]={0};
	int sockfd1;
	pthread_t pname;
	pthread_create(&pname,NULL,reciv,NULL);
	//printf("input your name:");
	//scanf("%s",myinfo.virtual_name);
	sockfd1 = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd1<0)
	{
		show_err("socket");
	}

	setsockopt(sockfd1,SOL_SOCKET,SO_BROADCAST,&on,sizeof(on));

	bzero(&conaddr,sizeof(conaddr));
	conaddr.sin_family = AF_INET;
	conaddr.sin_port = htons(5677);
	conaddr.sin_addr.s_addr  = inet_addr("192.168.1.255");
	
	while(1)
	{	
		scanf("%[^\n]",buf3);
		getchar();
		sprintf(buf1,"%s:%s",myinfo.virtual_name,buf3);
		n = sendto(sockfd1,buf1,sizeof(buf1),0,(struct sockaddr*)&conaddr,len);
		if(n<0)
		{
			close(sockfd1);
			show_err("sendto");
		}
		if(buf3[0]=='#')
			{
			close(sockfd1);
			pthread_cancel(pname);
			break;
			}
	}

		return ;

}
