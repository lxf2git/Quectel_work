

#include "qqclient.h"

int create_file_chain(Thread_Data *pHead,char *fileName)
{
	
		Thread_Data *pTemp;
		int ret;
		struct stat stat;
		ret = lstat(fileName,&stat);
		if(ret == -1)
		{
				perror(fileName);
				return -1;
		}
		if(S_ISFIFO(stat.st_mode))
			return -1;	
		if(S_ISDIR(stat.st_mode))
		{
			
				printf("%s是文件夹\n",fileName);
				ret = find_fileName(pHead,fileName);
	//			if(ret == -1)
	//			{
	//					printf("find\n");
	//					return -1;
	//			}
		}
		else
		{
				chain_init(&pTemp);
				sprintf(pTemp->data.fileName,"%s",fileName);
				chain_insert(pHead,pTemp);
				printf("%s插入\n",fileName);
				
		}
		return 0;
}
int find_fileName(Thread_Data *pHead,char *path)
{
		char fileName[200];
		bzero(fileName,sizeof(fileName));
		DIR * pDir;
		pDir = opendir(path);
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
						printf("path:%s\n",path);
						perror("readdir");
						closedir(pDir);
						return -1;
						
				}
				if(pDirent->d_name[0]=='.')
							continue;
				sprintf(fileName,"%s/%s",path,pDirent->d_name);
				printf("%s\n",fileName);
				create_file_chain(pHead,fileName);

		}
		closedir(pDir);
		return 0;
}
