#include"cs.h"

int main(int argc, char **argv)
{
		int cpfd, pfd, len, pid = getpid();
		char chpid[10], data[1024];
		memset(chpid, 0, sizeof(chpid));
		sprintf(chpid, "%d", pid);
		mkfifo(chpid, 0666);
		pfd = open("pipe", O_WRONLY);
		write(pfd, chpid, sizeof(chpid));
		write(pfd, argv[1], strlen(argv[1]));
		cpfd = open(chpid, O_RDONLY);
		while(1)
		{
				len = read(cpfd, data, sizeof(data));
				if(len<=0)
				{
						break;
				}
				printf("%s", data);
		}
		unlink(chpid);
		return 0;
}
