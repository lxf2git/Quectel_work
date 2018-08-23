#include"apue.h"

void put(struct show_err *sli_to_ser)
{
	int i=0,j=0,k=0;
	char argv[256];
	char argv1[256];
	char buf[1024];
	
	while(sli_to_ser->ftp_arg.ftp_put_file[i]!=' ')
	{
		i++;
	}
	if(sli_to_ser->ftp_arg.ftp_put_file[i]==' ')
	{
		i++;
	}
	while(sli_to_ser->ftp_arg.ftp_put_file[i]!=' ')
	{
		i++;
	}
	i++;
	while(sli_to_ser->ftp_arg.ftp_put_file[i]!='\0')
	{
		argv[j]=sli_to_ser->ftp_arg.ftp_get_file[i];
		j++;
		i++;
	}
//	while(sli_to_ser->ftp_arg.ftp_pit_file[i])
		int fd;
		printf("argv:%s\n",argv);
		fd = open(argv,O_RDWR|O_CREAT,0666);
				read(sli_to_ser->sockfd,buf,sizeof(buf));
				write(fd,buf,sizeof(buf));
		
		close(fd);
	
}
