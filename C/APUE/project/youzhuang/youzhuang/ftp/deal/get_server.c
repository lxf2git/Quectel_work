#include"ftp.h"

int get_server(struct recv_to_deal dest_data,int sockfd,int msg_id)
{
		char buf[1024];
		bzero(buf,sizeof(buf));
		int fp;
		struct recv_to_deal verify;
		recevie_course(inet_addr(dest_data.ip),&verify,msg_id);

		if(verify.user.cmd == FAIL)
		{
				return SUC;
		}
		if((fp = open(dest_data.user.farg.ftp_get_file,O_RDWR)) < 0)
		{
				perror("open");
				return FAIL;
		}
		int ret = read(fp,buf,sizeof(buf)-1);
		while(ret > 0)
		{
				to_client(dest_data.ip, sockfd, buf, ret);
				ret = read(fp,buf,sizeof(buf)-1);
		}
		close(fp);
		return SUC;
}
