#include<stdio.h>
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
		if(argc != 2)
		{
				printf("error use.........\n");
				exit (-1);

		}
#if 0
		struct stat stat;
		lstat(argv[1],&stat);
		puts(ctime(&stat.st_mtime));
		puts(asctime(gmtime(&stat.st_mtime)));
		puts(asctime(localtime(&stat.st_mtime)));
#endif

			find_fileName(argv[1]);
}
int find_fileName(char *pathName)
{
		int max;
		char buf[1024];
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
				sprintf(buf,"%s/%s",pathName,pDirent->d_name);
				max =file_information(buf);

		}
		printf("max:%d\n",max);
		closedir(pDir);
		return 0;

}
int file_information(char *fileName)
{
		static int max=0;

		struct stat stat;
		lstat(fileName,&stat);
		printf("size:%-50d name:%s\n",stat.st_size,fileName);
		if(max<stat.st_size)
				max = stat.st_size;
		
		return max;
}
