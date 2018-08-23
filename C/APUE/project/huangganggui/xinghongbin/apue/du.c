#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
int file_information(char *fileName);
int find_fileName(char *pathName);
int main(int argc ,char**argv)
{
		char buf[1024];
		printf("%s\n",__FUNCTION__);
		if(argc > 2)
		{
				printf("error use.........\n");
				exit (-1);

		}
		if(argc == 1)
		{
				memset(buf,0,sizeof(buf));
				strcpy(buf,".");
				find_fileName(buf);
		}

		else
			find_fileName(argv[1]);
}
int find_fileName(char *pathName)
{
		char buf[1024];
		char path_srt[1024];
		DIR * pDir;
		pDir = opendir(pathName);
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
				if(strcmp(".",pathName) == 0)
				{
					memset(buf,0,sizeof(buf));
					strcpy(pathName , getcwd(buf,sizeof(buf)));

				}
				if(strcmp("..",pathName) == 0)
				{
					memset(path_srt,0,sizeof(buf));
					getcwd(path_srt,sizeof(buf));
					
					chdir("..");
					memset(buf,0,sizeof(buf));
					strcpy(pathName , getcwd(buf,sizeof(buf)));
					chdir(path_srt);

				}
				

				memset(buf,0,sizeof(buf));	
				sprintf(buf,"%s/%s",pathName,pDirent->d_name);
				file_information(buf);

		}
		closedir(pDir);
		return 0;

}
int file_information(char *fileName)
{
		int ret;

		struct stat stat;
		ret = lstat(fileName,&stat);
		if(ret == -1)
		{
				perror("lstat");
				return -1;
		}	
		if(S_ISDIR(stat.st_mode))
		{
				printf("\ncd-> > >");
				printf("%s/\n\n",fileName);
				find_fileName(fileName);
				printf("<..>\n");	
		}
		else
		printf("                              file:--------------->%s\n",fileName);
		
		return 0;
}
