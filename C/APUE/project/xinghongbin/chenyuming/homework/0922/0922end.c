#include "../apue.h"

int main()
{
	int pid_buf;
	char com_buf[1024];
	int fid_pid = open("pid", O_RDONLY);
	int i;

	for (i=0; i<3; i++){
		memset(com_buf, 0, sizeof(com_buf));
		read(fid_pid, &pid_buf, sizeof(int));
		sprintf(com_buf, "kill %d", pid_buf);
		system(com_buf);
	}
	close(fid_pid);

	return 0;
}
