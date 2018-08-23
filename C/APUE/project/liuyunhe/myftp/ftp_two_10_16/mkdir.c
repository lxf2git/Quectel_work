#include"apue.h"
int mymkdir(struct show_err self)
{
		char buf[1024];
		char ch[1024];
		int i=0,j;
		bzero(buf,sizeof(buf));
		bzero(ch,sizeof(ch));
		strcpy(buf,self.ftp_arg.ftp_ls_path);
		int ln = strlen(buf);
		while(buf[i]!=' ')
		{
				i++;
		}
		i++;
		for(j=0;buf[i]!=' '&&i<ln;i++,j++)
		{
				ch[j]=buf[i];
		}
		mkdir_(ch,self.sockfd);
}
int mkdir_(char *argv,int confd)
{
		int ret;
		char buf[1024];
		ret =   mkdir(argv,0777);
		if(ret<0)
		{   
				show_err("mkdir");
		}else
		{   
				strcpy(buf,"mkdir success\n");
				write(confd,buf,sizeof(buf));
		}   

		return 0;   
}

