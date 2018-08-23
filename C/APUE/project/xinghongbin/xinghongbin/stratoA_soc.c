#include "/apue.h"


int my_strcmp(char *buf);
int main()
{
		int socid = socket(AF_INET,SOCK_STREAM,0);
		if(socid == -1)
		{
				perror("socket");
				exit(0);
		}
		struct sockaddr_in saddr,caddr;
		bzero(&saddr,sizeof(saddr));
		saddr.sin_family = AF_INET;
		saddr.sin_addr.s_addr = htonl(INADDR_ANY);
		saddr.sin_port = htons(8888);
		bind(socid,(struct sockaddr*)&saddr,sizeof(saddr));

		listen(socid , 10);
		while(1)
		{	
				bzero(&caddr,sizeof(caddr));
				int len = sizeof(caddr);
				int cocid = accept(socid,(struct sockaddr*)&caddr,&len);
				if(cocid == -1)
				{
						perror("accept");
						close(socid);
						exit(0);
				}

				char buf_wel[1024];
				char buf_data[1024];
				char buf[1024];
				bzero(buf_wel,sizeof(buf_wel));
				printf("%s go in\n",inet_ntoa(caddr.sin_addr));
				sprintf(buf_wel,"welcom to samHost(192.168.1.201)");
				write(cocid,buf_wel,strlen(buf_wel)+1);
				if(fork() == 0)
				{
						while(1)
						{
								bzero(buf_data,sizeof(buf_data));
								int ret =read(cocid,buf_data,sizeof(buf_data));
			//					printf("ret:%d\n",ret);
								printf("%s:%s\n",inet_ntoa(caddr.sin_addr),buf_data);
								if(my_strcmp(buf_data) == 1)
								{
										printf("%s:go away\n",inet_ntoa(caddr.sin_addr));
										close(cocid);
										exit(0);
								}

								bzero(buf_data,sizeof(buf_data));
								//printf("%s:",inet_ntoa(saddr.sin_addr));
								printf("samHost(192.168.1.201)  to %s:",inet_ntoa(caddr.sin_addr));
								fflush(NULL);
								bzero(buf,sizeof(buf));
								read(0,buf,sizeof(buf));
								sprintf(buf_data,"samHost(192.168.1.201):%s",buf);
								write(cocid,buf_data,strlen(buf_data)+1);
							//	sleep(1);

						}
				}
				usleep(1000*20);



		}
}
int my_strcmp(char *buf)
{
		if(buf[0]=='b'  && buf[1]=='y')
				return 1;
		else
				return 0;

}
