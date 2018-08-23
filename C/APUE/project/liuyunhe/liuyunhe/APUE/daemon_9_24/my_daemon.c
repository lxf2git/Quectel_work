#include"apue.h"
#if 0
1.父消子存
2.改当前目录
3./dev/null
4.摆脱 setsid
5.创建文件无权限掩码 uamask(0)
#endif
int my_daemon()
{
		pid_t pid = fork();
		if(pid<0)
		{
				perror("fork");
				exit(-1);
		}
		if(0 == pid)
		{		sleep(1);
				chdir("/");
				setsid();
				int fid = open("/dev/null",O_RDWR);
				dup2(fid,0);
				dup2(fid,1);
				dup2(fid,2);
				umask(0);
				
		}
		if(pid > 0)
		{
				exit(0);
		}
}
