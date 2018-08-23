#include"apue.h"

void pwd(struct show_err *cli_to_ser)
{
	char buf[30]={'\0'};
	getcwd(buf,sizeof(buf));
//	printf("%s",buf);
	write(cli_to_ser->sockfd,buf,sizeof(buf));
}
