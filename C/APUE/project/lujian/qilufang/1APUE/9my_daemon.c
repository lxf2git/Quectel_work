#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdlib.h>
void my_daemon(int nochdir,int noclose)
{
		pid_t pid;
		int file_describe=0;
		int black_hole;
		black_hole=open("/dev/null",O_RDWR);
		if(black_hole<0)
		{
				perror("open_black");
				exit(-1);
		}
		if(nochdir==0&&noclose==0)
		{
				pid=fork();
				if(pid>0)	
				{
					exit(0);	
				}
				if(pid==0)
				{
						printf("%d\n",file_describe);
						while(file_describe<3)
						{
								dup2(black_hole,file_describe);
								file_describe++;
						}
						
						chdir("/");
						setsid();
						close(black_hole);
				}
				else
				{
						close(black_hole);
						exit(-1);
				}

		}
}
int main()
{
		char c='a';
		int fd;
		my_daemon(0,0);
		fd=open("file",O_CREAT|O_RDWR,umask(0));
		if(fd<0)
		{
				perror("open");
				exit(-1);
		}
		while(1)
		{
				if(write(fd,&c,1)<0)
				{
						perror("write");
						exit(-1);
				}
				write(1,&c,1);
				c++;
				if(c=='z')
				{
						c='a';
				}
				sleep(2);
		}
		close(fd);
		return 0;
}
