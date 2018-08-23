#include "apue.h"
int recv_friendCircle_recv(sData_package data,sSocks socket_structure,pOnlineUser pHeadOnline)
{
		char buf[30];
		bzero(&buf,sizeof(buf));
		sprintf(buf,"./%s/friendCircle",data.src_user);
		int fd = open(buf,O_WRONLY);
		if(fd < 0){
				perror("open");
				return -1;
		}
		int ret = write(fd,data.dorinform.data,strlen(data.dorinform.data));
		if(ret < 0){
				close(fd);
				return -1;
		}
		close(fd);
		return 0;
}
