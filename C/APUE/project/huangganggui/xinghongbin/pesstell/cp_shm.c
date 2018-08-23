#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define LENGTH 1024
int mapping(char *fileName);
int mycp_file(char *fileName);
int main(int argc, char ** argv)
{
		if(argc < 3)
		{
				printf("using error (a.out fileName)\n");
				exit(0);
		}
		char *p;
	if(fork()==0)
	{
		sleep(1);	
		mycp_file(argv[2]);	
	}
	else
	{
		mapping(argv[1]);
		wait(NULL);
	}
}


int mapping(char *fileName)
{
		char buf[1024];
		char *p;
		int shmid = shmget (0x8888,1024,IPC_CREAT|0666);
		if(shmid == -1)
		{
				perror("shmget");
				exit(-1);
		}
		p = shmat(shmid,0,0);
		if(p == (char*)-1)
		{
				perror("shmat");
				exit(-1);

		}
		int fd,ret;
		fd = open(fileName,O_RDWR);
		if(fd == -1)
		{
				perror("open fileName");
				exit(-1);
		}
		ret = read(fd,p,1024);
		if(ret == -1)
		{
				perror("read");
				exit(-1);
		}

		close(fd);
				
}

int mycp_file(char *fileName)
{
		char *p;
		int shmid = shmget (0x8888,0,0);
		p = shmat(shmid,0,0);

		char buf[1025];
		memset(buf,0,sizeof(buf));
		sprintf(buf,"%s",p);
		printf("buf:%s",buf);

		int fd,ret;
		fd = open(fileName,O_RDWR|O_CREAT|O_TRUNC,0666);
		if(fd == -1)
		{
				perror("cp_open fileName");
				exit(-1);
		}
		ret = write(fd,buf,strlen(buf));
		if(ret <= 0)
		{
				perror("write");
				exit(-1);
		}
		close(fd);	
			
}
