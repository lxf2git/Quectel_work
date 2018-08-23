#include "../apue.h"

int main()
{
	umask(0);
	int fid, i;
	char buf[100];

	if (fork() == 0){
		sleep(1);

		if (setsid() < 0){
			perror("setsid");
			return -1;
		}

		if (fork() == 0){
			sleep(1);
			if (chdir("/") < 0){
				perror("chdir");
				return -1;
			}
			
			for (i=0; i<3; i++){
				close(i);
			}

			fid = open("/tmp/daemon", O_CREAT|O_EXCL|O_TRUNC|O_RDWR, 0777);
			if (fid < 0){
				perror("open");
				return -1;
			}
			
			while(1){
				memset(buf, 0, sizeof(buf));
				sprintf(buf, "%d this is a daemon process running\n", getpid());
				write(fid, buf, sizeof(buf));
				sleep(10);
			}
		}
		exit(0);
	}
	exit(0);

	return 0;
}
