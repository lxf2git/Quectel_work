#include "../apue.h"

int main()
{
	int pipe_fd[2];
	int pid;

	if ((pipe(pipe_fd)) < 0){
		//ysy_err("create pipe error");
	}

	if ((pid = fork()) < 0){
//		sys_err("fork error");
	}

	if (pid == 0){
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		execlp("grep", "grep", "c", NULL);
	}
	else{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		close(pipe_fd[1]);
		execlp("ls", "ls", NULL);
	}

	return 0;
}
