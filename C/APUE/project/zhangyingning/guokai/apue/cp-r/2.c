#include"apue.h"

int main(int argc,char **argv)
{
	int ret;
	char buf[1024]={'\0'};
	char buf1[1024]={'\0'};
	char buf2[1024]={'\0'};
	char buf3[1024]={'\0'};

	getcwd(buf,sizeof(buf));
//	puts(buf);

	ret = chdir(argv[2]);
	if(ret<0)
	{
		perror("chdir1");
		return -1;
	}
	getcwd(buf1,sizeof(buf1));
	getcwd(buf2,sizeof(buf2));
//	puts(buf1);
//	puts(buf2);

	ret = chdir(buf);
	if(ret<0)
	{
		perror("chdir2");
		return -1;
	}

	ret = chdir(argv[3]);
	if(ret<0)
	{
		mkdir(argv[3],0777);
		chdir(argv[3]);
		getcwd(buf3,sizeof(buf3));
//		puts(buf3);
	}
	else
	{
		getcwd(buf3,sizeof(buf3));
//		puts(buf3);
	}
	chdir(buf);
//	puts(argv[2]);
	func(buf1,buf2,buf3);
	return 0;
}

int func(char *buf1,char *buf2,char *buf3)
{
	char buf[1024]={'\0'};		//buf1 file1 初始绝对路径	
	char buf4[1024]={'\0'};
	char buf5[1024]={'\0'};
	char temp[1024]={'\0'};		//buf2 file1 当期路径	
	int ret,num,m,n,i;			//buf3 file2 初始绝对路径	
	DIR *pdir = NULL;
	struct stat stat;
	struct dirent *pdirent = NULL;
	ret = chdir(buf2);
	if(ret!=-1)
	{
		pdir = opendir("./");
		if(pdir==NULL)
		{
			perror("opendir");
			return -1;
		}
		while(1)
		{
			pdirent = readdir(pdir);			
			if(pdirent==NULL)
			{
					chdir("..");	
					return 0;
			}
			if(pdirent->d_name[0]!='.')
			{
				lstat(pdirent->d_name,&stat);
				
				if(S_ISREG(stat.st_mode))
				{
					memset(buf,0,sizeof(buf)); 	
					getcwd(buf,sizeof(buf));	//buf  当前绝对路径
			//		printf("buf=%s\n",buf);
			//		printf("buf1=%s\n",buf1);
					memset(temp,0,sizeof(temp)); 	
					m = strlen(buf);
					n = strlen(buf1);
			//		printf("m=%dn=%d\n",m,n);
					if(m!=n)
					{
						for(i=0;i<(m-n);i++)
						{
							temp[i] = buf[n+i];
						}
					}
					
					memset(buf5,0,sizeof(buf5)); 	
					sprintf(buf5,"%s%s/%s",buf3,temp,pdirent->d_name);
			//		printf("%s",buf5);
					cp_file(buf,pdirent->d_name,buf5);	
				}
				
				if(S_ISDIR(stat.st_mode))
				{
					memset(buf,0,sizeof(buf)); 	
					getcwd(buf,sizeof(buf));
					
					memset(temp,0,sizeof(temp)); 	
					m = strlen(buf);
					n = strlen(buf1);
					if(m!=n)
					{
						for(i=0;i<(m-n);i++)
						{
							temp[i] = buf[n+i];
						}
					}
					
					memset(buf4,0,sizeof(buf4)); 	
					sprintf(buf4,"%s%s/%s",buf3,temp,pdirent->d_name);
					mkdir(buf4,0777);
					
					func(buf1,pdirent->d_name,buf3);			
				}
			}	
		}
	}
}
