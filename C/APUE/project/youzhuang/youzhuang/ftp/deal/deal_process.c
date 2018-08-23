#include"ftp.h"

int main()
{
		struct recv_to_deal recv_data;
		int ret, sockfd, msg_id,pid;
		msg_id = msgget(0x6666, O_RDWR);
		sockfd = socket(AF_INET, SOCK_DGRAM, 0);
		signal(SIGUSR1, fun);
		while(1)
		{
				recevie_course(7777, &recv_data, msg_id);
				if(judge_first_connect(recv_data, msg_id) == SUC)
				{
						pid = fork();
						if(pid == 0)
						{
								ret = judge_login(recv_data.user.farg.fui.ftp_username, recv_data.user.farg.fui.ftp_passwd);
								if(ret == SUC)
								{
										to_client(recv_data.ip,sockfd,&ret,sizeof(ret));
										deal(recv_data, msg_id, sockfd);
								}
								else
								{
										to_client(recv_data.ip,sockfd,&ret,sizeof(ret));
							 			del_user(recv_data, msg_id);
										kill(getppid(), SIGUSR1);
										exit(-1);
								}
						}
				}
				else
				{
						send_course(inet_addr(recv_data.ip), recv_data, msg_id);
				}

		}
		return 0;
}

int deal(struct recv_to_deal data, int msg_id, int sockfd)
{
		struct recv_to_deal recv_data;
		while(1)
		{
				recevie_course(inet_addr(data.ip),&recv_data,msg_id);
				switch(recv_data.user.cmd)
				{
						case LS:
							 ls_pwd(recv_data, sockfd);
							 break;
						case PUT:
							 put_server(recv_data, sockfd, msg_id);
							 break;
						case GET:
							 get_server(recv_data, sockfd, msg_id);
							 break;
						case CD:
							 cd(recv_data, sockfd, msg_id);
							 break;
						case PWD:
							 ls_pwd(recv_data, sockfd);
							 break;
						case MKDIR:
							 mkdir_s(recv_data, sockfd, msg_id);
							 break;
						case QUIT:
							 del_user(recv_data, msg_id);
							 kill(getppid(), SIGUSR1);
							 exit(-1);
							 break;
				}
		}
}

void fun(int sid)
{
		wait(NULL);
}


int to_client(char *ip,int sockfd, void *buf,int len)
{
		struct sockaddr_in dest;
		dest.sin_family = AF_INET;
		dest.sin_port =  htons(8887);
		dest.sin_addr.s_addr = inet_addr(ip);
		sendto(sockfd, buf,len, 0 ,(struct sockaddr *)&dest, sizeof(dest));
}

int del_user(struct recv_to_deal data, int msg_id)
{
		Txt t,m;
		m.type = 6666;
		strcpy(m.text,"#");
		msgsnd(msg_id, &m, sizeof(m)-sizeof(m.type), 0);
		strcpy(m.text,data.ip);
		msgsnd(msg_id, &m, sizeof(m)-sizeof(m.type), 0);
		msgrcv(msg_id, &t, sizeof(t)-sizeof(t.type),6667, 0);
		printf("%s\n",t.text);
}

int judge_first_connect(struct recv_to_deal data, int msg_id)
{
		Txt t,m;
		m.type = 6666;
		strcpy(m.text,data.ip);
		msgsnd(msg_id, &m, sizeof(m)-sizeof(m.type), 0);
		msgrcv(msg_id, &t, sizeof(t)-sizeof(t.type),6667, 0);
		printf("%s\n",t.text);
		if(strcmp(t.text,"add")==0)
		{
				return SUC;
		}
		return FAIL;
}

