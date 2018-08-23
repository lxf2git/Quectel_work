#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 1024
int mapping(char *fileName,char **p);
int mycp_file(char *p,char *fileName);
int main(int argc, char ** argv)
{
		if(argc < 3)
		{
				printf("using error (a.out fileName)\n");
				exit(0);
		}
		char *p;
		mapping(argv[1],&p);
		mycp_file(p,argv[2]);	
		munmap(p,LENGTH);
}


int mapping(char *fileName,char** p)
{
		int fd,ret;
		fd = open(fileName,O_RDWR);
		if(fd == -1)
		{
				perror("open fileName");
				exit(-1);
		}
		ret = ftruncate(fd,LENGTH);
		if(ret == -1)
		{
				perror("ftruncate");
				exit(-1);
		}
		*p = mmap(NULL,LENGTH,PROT_READ,MAP_SHARED,fd,0);
		close(fd);
				
//		munmap(*p,LENGTH);

}

int mycp_file(char *p,char *fileName)
{
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
