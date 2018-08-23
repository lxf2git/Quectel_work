#include "../apue.h"

int main()
{
	int i;
	char ch;
	pid_t fork_ret;
	int fid_pid = open("pid", O_RDWR|O_TRUNC);

	for (i=0; i<3; i++){
		fork_ret = fork();
		if (fork_ret == 0){
			while(1){
				ch = i + 97;
				sleep(1);
				printf("%c ", ch);
				fflush(NULL);
			}
		}
		write(fid_pid, &fork_ret, sizeof(fork_ret));
	}
	close(fid_pid);
}
