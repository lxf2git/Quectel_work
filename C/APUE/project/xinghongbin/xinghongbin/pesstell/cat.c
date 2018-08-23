//#include"/home/apue/apue.h"
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
union u_data
{
		int i_data;
		char c_data[4];
};
void parent_press();
void child_press(char *fileName);
void get_fileName(int sig,siginfo_t * info,void *p);
void getData(int sig);
int get_childPid();
int put_childPid();
void putData();
char name[1024];
int main(int argc,char ** argv)
{
		char fileName[1024];
		memset(fileName,0,sizeof(fileName));
		if(argc < 2)
		{
				printf("user error (a.out filename)\n");
				exit(-1);
		}
		if(fork()== 0)
		{
				put_childPid();
				strcpy(fileName,argv[1]);
				printf("loading");
				child_press(fileName);
				printf("\nGO\n");
				kill(getppid(),SIGUSR2);
				while(1);
		}
		else
		{
				parent_press();
				while(1);
		}

}
void parent_press()
{
		signal(SIGUSR2,getData);
		struct sigaction act;
		act.sa_sigaction = get_fileName;
		act.sa_flags = SA_SIGINFO;
		sigemptyset(&act.sa_mask);
		sigaction(SIGUSR1,&act,NULL);
//		printf("parent\n");
		

}

void child_press(char *fileName)
{
		struct sigaction act;
		act.sa_sigaction = putData;
		act.sa_flags = SA_SIGINFO;
		sigemptyset(&act.sa_mask);
		sigaction(SIGUSR2,&act,NULL);
//		printf("child\n");

		union u_data data;
		data.i_data = 0;
		union sigval v;
		int i;
		for(;*fileName!= '\0';fileName+=3)
		{
				for(i=0;i<3;i++)
				{
						data.c_data[i]=fileName[i];

				}

				v.sival_int = data.i_data;
				sigqueue(getppid(),SIGUSR1,v);
				printf(".");
				fflush(NULL);
				usleep(500*1000);
		}

}
void get_fileName(int sig,siginfo_t * info,void *p)
{
		strcat(name,(char*)&(info->si_value.sival_int));
}

void getData(int sig)
{
		int fd;
		union u_data data;
		data.i_data = 0;
		union sigval v;
		fd = open(name,O_RDONLY);
		if(fd == -1 )
		{
				perror("filename");
				exit(-1);
		}
		while ( read(fd,data.c_data,sizeof(int)-1) >0 )
		{
				v.sival_int= data.i_data;
				sigqueue(get_childPid(),SIGUSR2,v);
				usleep(1000*5);
		}
		printf("\nclosing\n");
		sleep(1);
		kill(get_childPid(),SIGKILL);
		exit(0);
}
void putData(int sig,siginfo_t * info,void *p)
{
		printf("%s",(char*)&(info->si_value.sival_int));
		fflush(NULL);
}

int get_childPid()
{
		int fd,pid,ret;
		fd = open("file",O_RDONLY);
		if(fd == -1)
		{
				perror("get_chilePid");
				exit(-1);
		}
		ret = read(fd,&pid,sizeof(int));
		if(ret <= 0)
		{	
				perror("read childPid");
				exit(-1);
		}
		close(fd);
		return pid;
}
int put_childPid()
{
		int fd,pid,ret;
		pid = getpid();
		fd = open("file",O_WRONLY|O_CREAT|O_TRUNC,0666);
		if(fd == -1)
		{
				perror("put_chilePid");
				exit(-1);
		}
		ret = write(fd,&pid,sizeof(int));
		if(ret <= 0)
		{	
				perror("write childPid");
				exit(-1);
		}
		close(fd);
		return pid;
}









