#include"apue.h"	
void ls(char *argv0,char *argv1);
void ls_nul(char *argv);
#if 0
int main()	
{
	char argv0[1024],argv1[1024];
	bzero(argv0,sizeof(argv0));
	bzero(argv1,sizeof(argv1));
	strcpy(argv0,"-l");
	strcpy(argv1,"/root/Desktop");
	ls(argv0,argv1);
	return 0;	
}
#endif
#if 1
struct show_err senfd;
int ls_ftp(struct show_err confd)
{
				char argv[3][1024],buf[1024];
				bzero(argv[0],1024*sizeof(char));
				bzero(argv[1],1024*sizeof(char));
				bzero(argv[2],1024*sizeof(char));

				strcpy(buf,confd.ftp_arg.ftp_ls_path);
				senfd.sockfd=confd.sockfd;

int len,len_num=0,x=0,y=0;
char tmp[1024];
len = strlen(buf);
while(1)
{
				if(len_num==len)
				{   
								strcpy(argv[x],tmp);
								bzero(tmp,sizeof(tmp));
								break;
				}else
								if(buf[len_num]==' ')
								{   
												strcpy(argv[x],tmp);
												bzero(tmp,sizeof(tmp));
												x++;
												len_num++;
												y=0;
								}else
								{   
												tmp[y]=buf[len_num];
												len_num++;
												y++;
								}   
}

if(strcmp(argv[0],"ls")==0)
{
				ls(argv[1],argv[2]);
				bzero(argv[0],sizeof(argv[0]));
}else
{
				printf("%s\n",argv[0]);
				char buf_send[1024];
				printf("byebye\n");
				strcpy(buf_send,"open refuse-_-\n");
				write(senfd.sockfd,buf_send,sizeof(buf_send)-3);
}
return 0;	
}
#endif

/*遍历指定目录并仅列举出目录所含文件名称 函数*/
void ls_nul(char *argv)
{
	DIR *pdir = NULL;
	struct dirent *pdirent = NULL;
	char buf[1024] = {'\0'};

	pdir = opendir(argv);
	if(pdir==NULL)
	{
		show_err("opendir");
	}

	while(1)
	{
		pdirent = readdir(pdir);
		if(pdirent==NULL)
		{
			break;
		}
		if(pdirent->d_name[0]=='.')
		{
			continue;
		}else
		{
			strcat(buf,pdirent->d_name);
			strcat(buf," ");
		}
	}
	strcat(buf,"*");
	write(senfd.sockfd,buf,sizeof(buf)-3);
	printf("writeout:%s\n",buf);
#if 0
	int n=0,len;
	len = strlen(buf);
	while(1)
	{
		if(n==len)
		{
			break;
		}else
			if(buf[n]=='*')
			{
				printf("\n");
				n++;
			}else
				{
					printf("%c",buf[n]);
					n++;
				}
	}
#endif
}

void ls(char *argv0,char *argv1)
{
	printf("%s\n",argv0);
	printf("%s\n",argv1);

	DIR *pdir = NULL;
	struct dirent *pdirent = NULL;
	char buf[1024] = {'\0'};
	char argv[4] = {'\0'};
	int m,len;

	if(strlen(argv0)==0)
	{
		strcpy(argv0,"./");
		ls_nul(argv0);
		return;
	}
	if(strlen(argv1)==0&&argv0[0]!='-')
	{
		ls_nul(argv0);
		return;
	}else
	{
		if(strlen(argv1)==0)
		{
			strcpy(argv1,"./");
		}
		//ail	/*将命令分析整理成“ail”的格式*/

		len = strlen(argv0);
		printf("argv0_len:%d\n",len);
		for(m=0;m<len;m++)
		{
			if('a'==argv0[m])
			{
				strcat(argv,"a");
				break;
			}
		}
		for(m=0;m<len;m++)
		{
			if('i'==argv0[m])
			{
				strcat(argv,"i");
				break;
			}
		}
		for(m=0;m<len;m++)
		{
			if('l'==argv0[m])
			{
				strcat(argv,"l");
				break;
			}
		}
		printf("%s\n",argv);

		/*将整理好的命令与包含相应绝对地址的变量传递给ls功能函数处理*/
		//argv + path
		if(chdir(argv1)!=0)
		{
			exit(-1);
		}
		pdir = opendir(argv1);
		if(pdir==NULL)
		{
			show_err("opendir");
		}
		/*将“ail”转换为标号，方便文件筛选遍历*/
		int n,a=0,i=0,l=0;
		for(n=0;n<len;n++)
		{
			if('a'==argv[n])
			{
				a=1;
			}else
					if('i'==argv[n])
					{
						i=1;
					}else
							if('l'==argv[n])
							{
								l=1;
							}
		}
		printf("a:%d i:%d l:%d\n",a,i,l);
		/*遍历目录并打包目录下各文件名*/
		struct stat stat;
		int ret;
		char buf_tmp[1024];
		chdir(argv1);
		while(1)
		{
			pdirent = readdir(pdir);
			if(pdirent==NULL)
			{
				break;
			}

			ret = lstat(pdirent->d_name,&stat);
			if(ret<0)
			{
				strcpy(buf,"sorry open refuse\n");
				exit(-1);
			//	write(sockfd,buf_tmp,sizeof(buf));
				//show_err("lstat");
			}

			if(a==0)//ls -a
			{
				if(pdirent->d_name[0]=='.')
				{
					continue;
				}
			}

			if(i==1)//ls -i
			{
				sprintf(buf_tmp,"%d",stat.st_ino);
				strcat(buf,buf_tmp);
				strcat(buf," ");
			}

			if(l==1)//ls -l
			{
				char mode[11];
				int ret;
				int i;
				int mode_num=0;
				char mode_str[][4]={"---","--x","-w-","-wx","r--","r-x","rw-","rwx"};

				memset(mode,0,sizeof(mode));
				if(S_ISREG(stat.st_mode))
				{
								mode[0]='-';
				}else
					if(S_ISDIR(stat.st_mode))
					{
							mode[0]='d';
					}else
						if(S_ISCHR(stat.st_mode))
							{
											mode[0]='c';
							}else
								if(S_ISBLK(stat.st_mode))
								{
												mode[0]='b';
								}else
									if(S_ISFIFO(stat.st_mode))
									{
													mode[0]='p';
									}else
										if(S_ISLNK(stat.st_mode))
										{
														mode[0]='i';
										}/*else
											if(S_ISSOCK(stat.st_mode))
		  								{
															mode[0]='s';
											}*/
				for(i=6;i>=0;i=i-3)
			  {
							mode_num=(stat.st_mode>>i)&0x7;
							strcat(mode,mode_str[mode_num]);
				}
#if 1			
				strcat(buf,mode);
				strcat(buf," ");

				sprintf(buf_tmp,"%d",stat.st_nlink);
				strcat(buf,buf_tmp);
				strcat(buf," ");

				sprintf(buf_tmp,"%d",stat.st_uid);
				strcat(buf,buf_tmp);
				strcat(buf," ");

				sprintf(buf_tmp,"%d",stat.st_size);
				strcat(buf,buf_tmp);
				strcat(buf," ");
#endif	
			}
			strcat(buf,pdirent->d_name);
			strcat(buf,"*");
		}
	}

	printf("1:%s\n",buf);	
#if 0
	/*将打包存储的遍历信息重新打开并显示*/
	int n=0,lenth;
	lenth = strlen(buf);
	printf("buf_len:%d\n",lenth);
	while(1)
	{
		if(n==lenth)
		{
			break;
		}else
			if(buf[n]=='*')
			{
				printf("\n");
				n++;
			}else
			{
				printf("%c",buf[n]);
				n++;
			}	
	}
#endif
	write(senfd.sockfd,buf,sizeof(buf)-3);
	printf("write_ok:%s\n",buf);
	return;
}
