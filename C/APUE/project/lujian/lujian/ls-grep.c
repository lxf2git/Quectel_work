
#include"../../apue.h" 

int main(int argc, char** argv)
{
		assert(argc == 2); //./a.out ".c"

		int fd[2];

		char buf[1024];
		memset(buf, 0, sizeof(buf));

		if (pipe(fd) < 0)
		{
				myperror("pipe");
		}

		pid_t pid;

		if ((pid = fork()) < 0)
		{
				myperror("fork");
		}
		else if (pid == 0)
		{
				close(fd[1]);
				read(fd[0], buf, sizeof(buf));	
				printf("%s", buf);
		}

		else 
		{	
				close(fd[0]);
				dup2(fd[1], 1);
				sprintf(buf,"ls | grep " "%s",argv[1]);
				system(buf);
				wait(NULL);
		}

}	
