#include"apue.h"

int fork_3()
{
		int i;
		pid_t pid;
		int fd = open("file",O_RDWR);
		for(i=0;i<3;i++)
		{
		pid_t pid = fork();
				if(0 == pid)
				{
						sleep(1+i);
						printf("%c\n",'a'+i);
						pid = getpid();
						write(fd,&pid,4);
						printf("getpid:%dgetppid:%d\n",getpid(),getppid());
						while(1);
						exit(0);
				}
						printf("pre_getpid:%dgetppid:%d\n",getpid(),getppid());
		}
		sleep(8);
		close(fd);
	//	return 0;
}


waitpid_3()
{
		printf("wait\n");
		system("./a.out");
}

int main()
{
		fork_3();

		waitpid_3();
		return 0;
}

