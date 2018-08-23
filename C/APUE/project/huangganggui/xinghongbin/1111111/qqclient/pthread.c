#include "qqclient.h"
Thread_Data * tell_addfriend(int mode,char* destAddr)
{
		int fd = open(destAddr,O_CREAT|O_APPEND);
		char buf[1024];
		bzero(buf,sizeof(buf));
		sprintf(buf,"发出好友请求(%s)\n",destAddr);
		write(fd,buf,sizeof(buf));

		Thread_Data *pTemp;
		chain_init(&pTemp);
		sData_package dataPackage = Sendinit[mode](NULL,destAddr);
		pTemp->data = dataPackage;
		pTemp->id = pthread_self();
		close(fd);
		return pTemp;
		
}
Thread_Data * tell_file(int mode,char* destAddr)
{
		Thread_Data *pTemp;
		chain_init(&pTemp);
		Thread_Data *pFile;
		chain_init(&pFile);
		int ret ;
		char buf_file[200];
		sData_package dataPackage;
		printf("put your fileName \n");
		char fileName[20];
		bzero(fileName,sizeof(fileName));
		scanf("%s",fileName);
		int fd = open(fileName,O_RDONLY);
		if(fd == -1)
		{
				perror("open");
				return(NULL);
		}
		bzero(buf_file,sizeof(buf_file));
		bzero(&dataPackage,sizeof(dataPackage));
		dataPackage = Sendinit[mode](buf_file,destAddr);
		sprintf(dataPackage.fileName,"$%s",fileName);
		int fd1 = open(destAddr,O_CREAT|O_APPEND);
		char buf[1024];
		bzero(buf,sizeof(buf));
		sprintf(buf,"发文件(%s)\n",fileName);
		write(fd1,buf,sizeof(buf));
		close(fd1);
		pFile->data = dataPackage;
		pFile->id = pthread_self();
		while(1)
		{
				chain_init(&pTemp);
				bzero(buf_file,sizeof(buf_file));
				bzero(&dataPackage,sizeof(dataPackage));
				ret = read(fd,buf_file,sizeof(buf_file)-1);
				if(ret == 0)
				{
						break;
				}
				sData_package dataPackage = Sendinit[mode](buf_file,destAddr);
				sprintf(dataPackage.fileName,"%s",fileName);
				pTemp->data = dataPackage;
				pTemp->id = pthread_self();
				chain_insert(pFile,pTemp);

		}
		bzero(&dataPackage,sizeof(dataPackage));
		dataPackage.mode = REQUES_EXIT;
		sprintf(dataPackage.fileName,"%s",fileName);
		sprintf(dataPackage.destAddr,"%s",destAddr);
		pTemp->data = dataPackage;
		pTemp->id = pthread_self();
		chain_insert(pFile,pTemp);
		return pFile;

}
Thread_Data * tell_tell(int mode,char* destAddr)
{
		Thread_Data *pTemp;
		chain_init(&pTemp);
		sData_package dataPackage;
		char buf_tell[200];
		printf("tell:");
		fflush(stdout);
		bzero(buf_tell,sizeof(buf_tell));
		scanf("%s",buf_tell);

		int fd = open(destAddr,O_CREAT|O_APPEND);
		char buf[1024];
		bzero(buf,sizeof(buf));
		sprintf(buf,"发谈话(%s)\n",buf_tell);
		write(fd,buf,sizeof(buf));
		close(fd);

		bzero(&dataPackage,sizeof(dataPackage));
		dataPackage = Sendinit[mode](buf_tell,destAddr);
		pTemp->data = dataPackage;
		pTemp->id = pthread_self();
		return pTemp;

}
int chain_insert(Thread_Data *pHead,Thread_Data *pInsert)
{
		Thread_Data *pInsert_taill;
		pInsert_taill = pInsert->prev;
		pInsert_taill->next = pHead;
		pInsert->prev = pHead->prev;
		pHead->prev->next = pInsert;
		pHead->prev = pInsert_taill;
		return 0;

}
int chain_init(Thread_Data **p)
{
		*p = (Thread_Data *)malloc(sizeof(Thread_Data));
		(*p)->next = (*p);
		(*p)->prev = (*p);
}

