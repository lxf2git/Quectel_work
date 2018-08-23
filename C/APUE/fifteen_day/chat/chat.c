#include"../../apue.h"
char buf[100];

int rdwr_op(int fid_rd,int fid_wr)
{
	int n;	
	n = read(fid_rd,buf,sizeof(buf));
	write(fid_wr,buf,n);
	if(strcmp(buf,"byebye\n")==0)
	{
		return -1;
	}
	return 0;

}

void sig_fun(int sig)
{
	wait(NULL);
	exit(0);
}

int main(int argc,char **argv)
{    //ip+port+protocol

	int ret,confd;
	struct sockaddr_in conaddr,addr;
	socklen_t len = sizeof(addr);
	
	signal(SIGCHLD,sig_fun); 
		
	int sockfd = socket(AF_INET,SOCK_STREAM,0);//
 	 if(sockfd<0)
	 {
	 	show_err("socket");
	 }	 


	 switch(argc)
	 {
	 	case 1:
				bzero(&addr,sizeof(addr));
				addr.sin_family = AF_INET;
				addr.sin_port = htons(6111);
				addr.sin_addr.s_addr = htonl(INADDR_ANY);
				ret = bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
	 			if(ret<0)
				{
					close(sockfd);	
					show_err("bind");
				}
				ret  = listen(sockfd,10);
				if(ret<0)
				{
					close(sockfd);	
					show_err("listen");
				}
				confd = accept(sockfd,(struct sockaddr*)&conaddr,&len);
	 			if(confd<0)
				{
					close(sockfd);
					show_err("accept");
				}
				break;
		case 2:

				bzero(&conaddr,sizeof(conaddr));
				conaddr.sin_family = AF_INET;
				conaddr.sin_port = htons(6111);
				conaddr.sin_addr.s_addr = inet_addr(argv[1]);
				ret = connect(sockfd,(struct sockaddr*)&conaddr,sizeof(conaddr));
	 			if(ret<0)
				{
					close(sockfd);
					show_err("connect");
				}
				confd = sockfd;
				break;
		default:
				printf("infor err");
				break;
	 }

	 // 1 从stdin ---sockfd  2  sockfd---stdout
	 pid_t pid = fork();
	 if(pid<0)
	 {
		close(sockfd);	 
	 	show_err("fork");
	 }
	 if(pid==0)//从0---sockfd
	 {
		
	 	while(1)
		{
			ret = rdwr_op(0,confd);
			if(ret<0)
			{
				break;
			}
		}
	 }
	 else
	 {
	 	while(1)
		{
			ret = rdwr_op(confd,1);
			if(ret<0)
			{
				break;
			}
				
		}
		kill(pid,SIGKILL);
	 }
	return 0;

}
