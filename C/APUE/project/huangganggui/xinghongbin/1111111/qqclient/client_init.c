#include "qqclient.h"


int initSockfd_Serive(struct sockaddr_in *psaddr)
{
		int sockfd = socket(AF_INET,SOCK_DGRAM,0);
		if(sockfd == -1)
		{
				perror("sockfd");
				exit(-1);
		}
		struct sockaddr_in saddr;
		bzero(&saddr,sizeof(struct sockaddr_in));
//#ifdef MAKE_SERVICE
		printf(RED"使用默认服务器端口"NONE"\n");
		saddr.sin_family = AF_INET;
		saddr.sin_port = htons(SERVIC_PORT);
		saddr.sin_addr.s_addr = inet_addr(SERVICE_IP);
/*
#else
		printf(RED"使用用户自定义端口"NONE"\n");
		printf("input ip and id\n");
		char addr[20];
		int  port;
		bzero(addr,sizeof(addr));
		scnaf("%s",addr);
		getchar();
		scanf("%d",&port);
		saddr.sin_family = AF_INET;
		saddr.sin_port = htons(port);
		saddr.sin_addr.s_addr = inet_addr(addr);
#endif
*/
		*psaddr = saddr;
		return sockfd;

}
int initSockfd_Client(struct sockaddr_in *praddr)
{
		int sockfd = socket(AF_INET,SOCK_DGRAM,0);
		if(sockfd == -1)
		{
				perror("sockfd");
				exit(-1);
		}
		struct sockaddr_in saddr;
		bzero(&saddr,sizeof(struct sockaddr_in));
		saddr.sin_family = AF_INET;
		saddr.sin_port = htons(CLIENT_PORT);
		saddr.sin_addr.s_addr = htonl(INADDR_ANY);
		int ret = bind(sockfd,(struct sockaddr *)&saddr,sizeof(saddr));
		if(ret == -1)
		{
				perror("bind");
				exit(-1);
		}
		*praddr = saddr;
		return sockfd;
		
}
int initSend_Check(struct sockaddr_in *pcaddr)
{
		int sockfd = socket(AF_INET,SOCK_DGRAM,0);
		if(sockfd == -1)
		{
				perror("sockfd");
				exit(-1);
		}
		struct sockaddr_in saddr;
		bzero(&saddr,sizeof(struct sockaddr_in));
		saddr.sin_family = AF_INET;
		saddr.sin_port = htons(SEND_CHECK);
		saddr.sin_addr.s_addr = htonl(INADDR_ANY);
		int ret = bind(sockfd,(struct sockaddr *)&saddr,sizeof(saddr));
		if(ret == -1)
		{
				perror("bind");
				exit(-1);
		}
		*pcaddr = saddr;
		return sockfd;

}
int initRecv_Check(struct sockaddr_in *pcaddr)
{
		int sockfd = socket(AF_INET,SOCK_DGRAM,0);
		if(sockfd == -1)
		{
				perror("sockfd");
				exit(-1);
		}
		struct sockaddr_in saddr;
		bzero(&saddr,sizeof(struct sockaddr_in));
		saddr.sin_family = AF_INET;
		saddr.sin_port = htons(RECV_CHECK);
		saddr.sin_addr.s_addr = inet_addr(SERVICE_IP);
		*pcaddr = saddr;
		return sockfd;

}
sData_package init_login(char*name,char*deatAddr)
{
		sData_package login_package;
		bzero(&login_package,sizeof(login_package));
		login_package.mode = LOGIN;
		printf(GRE"user id:"NONE);
		fflush(stdout);
		scanf("%s",login_package.dorinform.loginInformation.userId);
		sprintf(login_package.dorinform.loginInformation.passwd,"%s",getpass(""GRE"user passwd:"NONE));
		time_t mytime;
		mytime = time(NULL);
		sprintf(login_package.time,"%s",ctime(&mytime));
		return login_package; 

}
sData_package init_register(char*name,char*destAddr)
{
		char buf_pass[10];
		sData_package login_package;
		bzero(&login_package,sizeof(login_package));
		login_package.mode = REGISTER;
		printf(GRE"user id:"NONE);
		fflush(stdout);
		scanf("%s",login_package.dorinform.loginInformation.userId);
		do{
				printf(GRE"user passwd:"NONE);
				fflush(stdout);
				bzero(buf_pass,sizeof(buf_pass));
				scanf("%s",buf_pass);
				printf(RED"user passwd again:"NONE);
				fflush(stdout);
				scanf("%s",login_package.dorinform.loginInformation.passwd);
		}while(strcmp(login_package.dorinform.loginInformation.passwd,buf_pass)&&printf("两次不一致\n"));
		time_t mytime;
		mytime = time(NULL);
		sprintf(login_package.time,"%s",ctime(&mytime));
		return login_package; 
}
sData_package init_addfriend(char*name,char *destAddr)
{
		char buf[20];
		sData_package data_package;
		bzero(&data_package,sizeof(data_package));
		data_package.mode = ADDFRIEND;
		do{
				printf(GRE"you want addfriend:"NONE);
				fflush(stdout);
				bzero(buf,sizeof(buf));
				scanf("%s",buf);
				printf(RED"please again:"NONE);
				fflush(stdout);
				scanf("%s",data_package.destAddr);
				
		}while((strcmp(data_package.destAddr,buf)) &&(printf("两次输入不一致\n")) );
		time_t mytime;
		mytime = time(NULL);
		sprintf(data_package.time,"%s",ctime(&mytime));
		sprintf(data_package.destAddr,"%s",destAddr);


		return data_package; 


}
sData_package init_file(char *buf_file,char* destAddr)
{
		int ret;
		
		sData_package data_package;
		bzero(&data_package,sizeof(data_package));
		data_package.mode = FILE_REQUES;
		sprintf(data_package.dorinform.data,"%s",buf_file);
		time_t mytime;
		mytime = time(NULL);
		sprintf(data_package.time,"%s",ctime(&mytime));
		sprintf(data_package.destAddr,"%s",destAddr);
		gettimeofday(&(data_package.vtime),NULL);



		return data_package; 

}
sData_package init_tell(char *buf_tell,char *destAddr)
{
		sData_package data_package;
		bzero(&data_package,sizeof(data_package));
		data_package.mode = TELL_REQUES;
		sprintf(data_package.dorinform.data,"%s",buf_tell);
		time_t mytime;
		mytime = time(NULL);
		sprintf(data_package.time,"%s",ctime(&mytime));
		sprintf(data_package.destAddr,"%s",destAddr);
		gettimeofday(&(data_package.vtime),NULL);
		return data_package; 
}
