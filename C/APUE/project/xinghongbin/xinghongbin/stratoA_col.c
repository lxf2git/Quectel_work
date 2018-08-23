#include "/apue.h"




int socid;
void func(int sig)
{
		char buf[1024];
		bzero(buf,sizeof(buf));
		sprintf(buf,"by");
		printf("\nclose....\n");
		write(socid,buf,strlen(buf)+1);
		close(socid);
		exit(0);
}
int main(int argc, char **argv)
{
		signal(SIGINT,func);
		signal(SIGTSTP,func);
		if(argc<3)
		{
				printf("user.....");
				exit(-1);
		}

		socid = socket(AF_INET,SOCK_STREAM,0);
		if(socid == -1)
		{
				perror("socket");
				exit(-1);
		}

		struct sockaddr_in caddr;
		bzero(&caddr,sizeof(caddr));
		caddr.sin_family = AF_INET;
		caddr.sin_port = htons(atoi(argv[2]));
		caddr.sin_addr.s_addr = inet_addr(argv[1]);
		if(connect(socid,(struct sockaddr*)&caddr,sizeof(caddr)) < 0)
		{
				perror("conect");
				close(socid);
				exit(-1);
		}
		printf("go in%s\n",argv[1]);
		char buf_data[1024];
		char buf_dataR[1024];
		char buf[1024];
		while(1)
		{
				bzero(buf_dataR,sizeof(buf_dataR));
				int ret = read(socid,buf_dataR,sizeof(buf_dataR));
		//		printf("ret %d",ret);
				puts(buf_dataR);
//				sleep(1);

				bzero(buf_data,sizeof(buf_data));
				bzero(buf,sizeof(buf));
				printf("clien:");
				fflush(NULL);
				read(0,buf_data,sizeof(buf_data));
				write(socid,buf_data,strlen(buf_data)+1);
				if(my_strcmp(buf_data) == 1)
				{
						printf("close...\n");
						close(socid);
						exit(0);	
				}
		}

		

}

int my_strcmp(char *buf)
{
		if(buf[0]=='b'  && buf[1]=='y')
				return 1;
		else
				return 0;

}
