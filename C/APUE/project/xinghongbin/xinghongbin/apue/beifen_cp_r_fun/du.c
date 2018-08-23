#include"main.h"
int main(int argc ,char**argv)
{
		char buf[1024];
		printf("%s\n",__FUNCTION__);
		if(argc > 3)
		{
				printf("error use.........\n");
				exit (-1);

		}
		mkdir(argv[2],0721);
#if 0
		if(argc == 1)
		{
				memset(buf,0,sizeof(buf));
				strcpy(buf,".");
				find_fileName(buf);
		}

		else
#endif
				mkdir_destPath(argv[2]);
				printf("%s\n",argv[2]);

				find_fileName(argv[1],argv[2]);
}

int find_fileName(char *srcPath,char *destPath)
{
		char buf[1024];
		char path_srt[1024];
		DIR * pDir;
		pDir = opendir(srcPath);
		if(pDir == NULL)
		{
				perror("opendir");
				return -1;
		}
		struct dirent * pDirent;
		while(1)
		{
				pDirent = readdir(pDir);
				if(pDirent == NULL)
				{
//						printf("error:%d\n",errno);
						if(errno == 0)
								break;
						perror("readdir");
						closedir(pDir);
						return -1;
						
				}
				if(pDirent->d_name[0]=='.')
							continue;
				if(strcmp(".",srcPath) == 0)
				{
					memset(buf,0,sizeof(buf));
					strcpy(srcPath, getcwd(buf,sizeof(buf)));

				}
				if(strcmp("..",srcPath) == 0)
				{
					memset(path_srt,0,sizeof(buf));
					getcwd(path_srt,sizeof(buf));
					
					chdir("..");
					memset(buf,0,sizeof(buf));
					strcpy(srcPath , getcwd(buf,sizeof(buf)));
					chdir(path_srt);

				}
				

				file_information(pDirent->d_name,srcPath,destPath);

		}
		closedir(pDir);
		return 0;

}
int file_information(char *fileName,char*srcPath,char *destPath)
{
		char buf_src[1024];
		char buf_dest[1024];
		memset(buf_src,0,sizeof(buf_src));	
		memset(buf_dest,0,sizeof(buf_dest));	
		sprintf(buf_src,"%s/%s",fileName,srcPath);
		sprintf(buf_dest,"%s/%s",fileName,destPath);

		int ret;

		struct stat stat;
		ret = lstat(buf_src,&stat);
		if(ret == -1)
		{
				perror("lstat");
				return -1;
		}	
		if(S_ISDIR(stat.st_mode))
		{
		//		printf("\ncd-> > >");
		//		printf("%s/\n\n",fileName);
				mkdir_destPath(buf_dest);
				find_fileName(buf_src,buf_dest);

		//		printf("<..>\n");	
		}
		else
		{
				printf("                              file:--------------->%s\n",fileName);
				copy_str(buf_src,buf_dest);
		}
		return 0;
}
