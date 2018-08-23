
#include"../../apue.h" 


int main() 
{

		int fd;
		int re;
		pid_t pid;
		char cmd[256];
		bzero(cmd, sizeof(cmd));

		if ((fd = open("file", O_RDWR)) < 0)
		{
				perror("open");
		}

		//lseek(fd,0, SEEK_SET);

		/*****读取子进程pid*****/

		while(1)
		{

				if ((re = read(fd, &pid, sizeof(pid))) < 0)
				{
						printf("re == %d\n", re) ;
						perror("read");
				}
				if (re == 0)
				{
						break;
				}
				/*****kill -9 pid****/

				printf("pid: %d\n", pid);
				sprintf(cmd,"kill -9 %d",pid);
				puts(cmd);
				system(cmd);
				bzero(cmd, sizeof(cmd));
		}

#if 0
		/*****父进程收尸****/
		while(1)
		{
				pid = wait(&sta);
				if (pid == -1)
				{
						break;
				}
				printf("child->pid:%d, status:%d %d %d %d \n",
								pid, WIFEXITED(sta),
								WEXITSTATUS(sta), WIFSIGNALED(sta),WTERMSIG(sta));
		}
#endif 
}
