#include"apue.h"	
int cd(char *argv);
int my_cd(struct show_err self)
{
		char buf[1024];
		char ch[1024];
		int i=0,j=0;
		bzero(buf,sizeof(buf));
		bzero(ch,sizeof(ch));
		strcpy(buf,self.ftp_arg.ftp_cd_path);
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
		printf("ch:%s\n",ch);
		cd_(ch,self.sockfd);
}
int cd_(char *argv,int confd)
{
	char buf[1024];
	getcwd(buf,sizeof(buf));
	printf("%s\n",buf);
	if(strcmp(argv,"..")==0)
	{
		bzero(argv,sizeof(argv));
		strcpy(argv,"../");
	}

	printf("%s\n",argv);

	int ret;
	ret = chdir(argv);
	if(ret<0)
	{
		show_err("chdir");
	}

	getcwd(buf,sizeof(buf));
	write(confd,buf,strlen(buf)+1);
	return 0;	
}
