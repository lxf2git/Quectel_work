#include"ftp.h"

int put_server(struct recv_to_deal dest_data, int sockfd, int msg_id)
{
		struct recv_to_deal sver;
		int fp,verify=0;
		char buf[1024];
		bzero(buf,sizeof(buf));
		fp = open(dest_data.user.farg.ftp_get_file,O_RDWR|O_CREAT|O_EXCL,0666);
		if(fp < 0)
		{
				verify=-1;
				to_client(dest_data.ip, sockfd,&verify, sizeof(verify));
				recevie_course(inet_addr(dest_data.ip), &sver, msg_id);
				if(sver.user.cmd == 0)
				{
						fp = open(dest_data.user.farg.ftp_get_file,O_RDWR|O_TRUNC);
						if(fp < 0)
						{
								perror("open");
								return FAIL;
						}
				}
				else
				{
		to_client(dest_data.ip, sockfd,buf, strlen(buf));
						return FAIL;
				}
		}
		else
		{
				to_client(dest_data.ip, sockfd,&verify, sizeof(verify));
		}
		while(1)
		{
				bzero(&sver,sizeof(sver));
				recevie_course(inet_addr(dest_data.ip), &sver, msg_id);
				write(fp,sver.user.farg.ftp_get_file,strlen(sver.user.farg.ftp_get_file));
				printf("%s!!!\n",sver.user.farg.ftp_get_file);
				if(sver.user.cmd == FAIL)
				{
						break;
				}
		}
		printf("!!\n");
		close(fp);
		return SUC;
}
