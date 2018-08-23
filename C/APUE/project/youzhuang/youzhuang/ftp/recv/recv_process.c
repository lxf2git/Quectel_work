#include"ftp.h"

int main()
{
		struct cli_to_ser user_data;
		struct recv_to_deal to_deal_data;
		int socket, sockfd, ret, len, src_port, msg_id;
		char src_ip[20];
		struct sockaddr_in src_addr;
		ret = getsocket(NULL, &socket);
		if(ret < 0)
		{
				perror("getsocket");
				close(socket);
				exit(-1);
		}
		msg_id = msgget(0x6666, O_RDWR|IPC_CREAT|0600);
		msgctl(msg_id, 0, NULL);
		msg_id = msgget(0x6666, O_RDWR|IPC_CREAT|0600);
		len = sizeof(src_addr);

		while(1)
		{
				memset(&user_data,0,sizeof(user_data));
				memset(&to_deal_data,0,sizeof(to_deal_data));
				sockfd = accept(socket, (struct sockaddr *)&src_addr, &len);
				if(sockfd < 0)
				{
						perror("accept");
						close(socket);
						msgctl(msg_id, 0, NULL);
						exit(-1);
				}
	
				strcpy(to_deal_data.ip,inet_ntoa(src_addr.sin_addr));
				src_port = ntohs(src_addr.sin_port);

				ret = receive_information(&user_data, sockfd);
				if(ret < 0)
				{
						perror("receive");
						close(socket);
						msgctl(msg_id, 0, NULL);
						exit(-1);
				}
				printf("ip:%s\n",to_deal_data.ip);
				printf("type:%d\n",user_data.cmd);
				printf(":%s\n",user_data.farg.ftp_cd_path);
				to_deal_data.user = user_data;
#if 1
				ret = send_course(7777, to_deal_data, msg_id);
				if(ret < 0)
				{
						perror("send_course");
						close(socket);
						msgctl(msg_id, 0, NULL);
						exit(-1);
				}
#endif
		}
}
