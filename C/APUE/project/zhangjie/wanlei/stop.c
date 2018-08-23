#include"../apue.h"

int main()
{
	int fd = open("file", O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		return -1;
	}
	int pid,ret;
	char kill[20]="kill ";
	while(1)
	{
		ret = read(fd, &pid, sizeof(pid));
		if(0 == ret)
		{
			break;
		}
		sprintf(kill,"%s %d ", kill, pid);
	}
	system(kill);
	return 0;
}
