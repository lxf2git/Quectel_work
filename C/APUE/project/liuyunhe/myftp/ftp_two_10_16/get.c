#include"apue.h"

void get(struct show_err *sli_to_ser)
{
		int i=0,j=0;
		int ret = 0;
		char argv[256];
		char a[2]={'\0'};
		char buf[1024];
		printf("**:%s\n",sli_to_ser->ftp_arg.ftp_get_file);
		while(sli_to_ser->ftp_arg.ftp_get_file[i]!=' ')
		{
				i++;
		}
		i++;
		printf("i:%d\n",i);
		while(sli_to_ser->ftp_arg.ftp_get_file[i]!=' ')
		{
				argv[j]=sli_to_ser->ftp_arg.ftp_get_file[i];
				j++;
				i++;
		}
		printf("argv:%s\n",argv);
		printf("*\n");
		DIR *pdir;
		struct dirent *rdir;
		pdir = opendir("./");
		while(1)
		{
				rdir = readdir(pdir);
				if(rdir==NULL)
				{
						break;
				}
				printf("rdir:%s\n",rdir->d_name);
				if(strcmp(rdir->d_name,argv)==0)
				{
						a[0]='1';
						write(sli_to_ser->sockfd,&a,sizeof(a));
						int fd;
						fd = open(rdir->d_name,O_RDWR);
						if(fd <0)
						{
								show_err("read");
						}
						while(1)
						{
								bzero(buf,sizeof(buf));
								ret = read(fd,buf,sizeof(buf)-3);
								if(ret ==0)
								{
										bzero(buf,sizeof(buf));
										strcpy(buf,"#*#");
										printf("buf:%s\n",buf);
										write(sli_to_ser->sockfd,buf,strlen(buf)+1);
										break;
								}
								printf("buf:%s\n",buf);
								write(sli_to_ser->sockfd,buf,strlen(buf)+1);
								printf("**\n");
						}
						return;
				}
				printf("***\n");

		}
		if(rdir==NULL)
		{	
				a[0]='0';
				write(sli_to_ser->sockfd,&a,sizeof(a));
		}
}
