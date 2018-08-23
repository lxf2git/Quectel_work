#include "../apue.h"

char *getFileName(char *fileName);
int main()
{
	printf("inb\n");
	char fileName[256] = {};
	//getFileName(fileName);
	printf("%d\n",getpid());
	printf("b:%s\n",getFileName(fileName));

	int fd;
	union sigval data;
	int ret;
	fd = open(fileName,O_RDONLY);
	for(;;)
	{
		data.sival_int = 0;
		ret = read(fd,&(data.sival_int),1);
		sigqueue(getpid()-1,SIGUSR1,data);
//		printf("o0o0o\n");
		if(ret < 1)
		{
			break;
		}
		usleep(1000);
	}
	kill(getpid()-1,SIGINT);
	return 0;
}
char *getFileName(char *fileName)
{
	int fdName;
	fdName = open("name.txt",O_RDWR);
	read(fdName,fileName,256);
	close(fdName);
	system("rm -rf name.txt");
	return fileName;
}
