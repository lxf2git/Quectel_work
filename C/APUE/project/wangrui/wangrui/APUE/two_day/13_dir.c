#include "../apue.h"

int main(int argc, char **argv)
{
		int ret;
		int fid;
		char file_name[1024];

		ret=mkdir(argv[1], 0777);
		if(ret<0)
		{
				perror("mkdir");
				return -1;
		}

		//memset(file_name, 0, sizeof(file_name));
		//sprintf(file_name, "%s/%s", argv[1], "file");
		//工作目录：程序运行的目录 /home/APUE/two_day/
		//切换工作目录
		chdir("/root");//cd tmpdir
		fid=open("file", O_CREAT);
		close(fid);

		

		return 0;
}




