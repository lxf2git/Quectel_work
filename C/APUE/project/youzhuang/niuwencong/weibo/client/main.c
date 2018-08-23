#include"apue.h"
#include"microblog.h"
//#include"client_func.h"


int main()
{

	SUer_basic_info data;
	struct sockaddr_in seraddr;
	int sockfd;
	int id;
	while(1)
	{
		while(1)
		{
			Connect_Server(&seraddr,&sockfd);
			int log_reg = User_Login(&data,&id);
			if( (send_receive_login(&log_reg,sockfd,&data)) == 0 )
			{
				close(sockfd);
				sleep1();
				break ;
			}
			close(sockfd);
			sleep1();
		}
		Menu(&data,sockfd,&seraddr);
	}

}
