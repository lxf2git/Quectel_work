#include "apue.h"
#include "microblog.h"


void *Register(int confd)
{
	int ret,n;
	PUser_basic_info data;
	
	bzero(&data,sizeof(SUer_basic_info));
	ret = read(confd,data,sizeof(SUer_basic_info));
	if(ret<0)
	{
		perror("register_write");
		exit(-1);
	}
	n = Add_user(data);
	write(confd,&n,sizeof(int ));
	close(confd);
	return SUC;
}
