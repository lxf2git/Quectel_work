
#include "qqclient.h"
#include <sys/time.h>
sData_package login_fun(int sockfd,struct sockaddr_in *psaddr,int rockfd)
{
				struct sockaddr_in raddr;
				sData_package login_package;
		do{
				bzero(&login_package,sizeof(login_package));
				login_package = init_login(NULL,NULL);
				///////////////////////////////////////////
				setjmp(jmpbuffer);
				signal(SIGALRM,myalarm);
				Send_fun(&login_package,psaddr,sockfd);
				alarm(2);
					
				bzero(&raddr,sizeof(struct sockaddr_in));
				bzero(&login_package,sizeof(login_package));
				login_package = Recv_fun(&raddr,rockfd);
				signal(SIGALRM,SIG_IGN);
		}while((login_package.mode == LOGINERROR) && (printf("%s\n",login_package.dorinform.data)));
		return login_package;
}
sData_package register_fun(int sockfd,struct sockaddr_in *psaddr,int rockfd)
{
	/*	
		struct itimerval time;
		
		time.it_interval.tv_sec = 2;
		time.it_interval.tv_usec = 0;
		time.it_value.tv_sec = 2;
		time.it_value.tv_usec = 0;
*/				
					
				struct sockaddr_in raddr;
				sData_package login_package;

		//do
		//{
	
				signal(SIGALRM ,myalarm);
				//bzero(&login_package,sizeof(sData_package));
				//login_package = init_register(NULL,NULL);	
				/////////////////////////////////////////
				int ret = setjmp(jmpbuffer);
//				setitimer( ITIMER_REAL,&time,NULL);
				//Send_fun(&login_package,psaddr,sockfd);	
			
			printf("ret:%d\n",ret);
				alarm(1);
				pause();
                             

				puts("----------");	
				//bzero(&raddr,sizeof(struct sockaddr_in));
				//bzero(&login_package,sizeof(login_package));
while(1);				
/*login_package = Recv_fun(&raddr,rockfd);
				printf("ok\n");
				signal(SIGALRM,SIG_IGN);
		//}while((login_package.mode == REGISTERERROR) && printf("%s\n",login_package.dorinform.data));
		printf("%s\n",login_package.dorinform.data);
		return login_package;
*/}
void myalarm(int sig)
{
		printf("data 重发\n");
		
		longjmp(jmpbuffer,3);

}
