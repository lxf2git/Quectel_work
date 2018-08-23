#include"../apue.h"

int main()
{
	int i;
	pid_t pid[3];
	pid_t pid_par = getpid();
	pid_t ret;
	int fd = open("file", O_CREAT|O_EXCL|O_WRONLY, 0666);
	if(fd < 0 )
	{
		if(EEXIST == errno)
		{
			fd = open("file", O_WRONLY);
			if(fd < 0)
			{
				perror("open");
				return -1;
			}
		}
	}
	for(i = 0; i < 3; i++)
	{
		if(0 == (ret = fork()))
		{
			pid[i] = getpid();
			write(fd, &pid[i],sizeof(pid[i]));
			break;
		}
	}
	close(fd);
	if(pid_par == getpid())
	{
		exit(0);
	}
#if 1
	while(1)
	{
		if(pid[0] == getpid())
		{
			printf("a ");
			fflush(stdout);
		}
		if(pid[1] == getpid())
		{
			printf("b ");
			fflush(stdout);
		}
		if(pid[2] == getpid())
		{
			printf("c ");
			fflush(stdout);
		}
		sleep(1);
/*		if(access("./stop", F_OK) == 0)
		{
			break;
		}
		wait(NULL);
	*/
	}
#endif
#if 0
	pid_t child;
	for(;;)
	{
		child = wait(NULL);
		if(child == -1)
		{
			break;
		}
		printf("%d结束\n",child);
	}
#endif
	return 0;
}
