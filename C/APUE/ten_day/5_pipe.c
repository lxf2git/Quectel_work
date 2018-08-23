#include"../apue.h"

void sig_fun(int sig)
{
	printf("sig:%d\n",sig);
}

int main()
{
	int pfd[2];
	int ret,n;
	signal(SIGPIPE,sig_fun);
	char c = 'a';
	ret = pipe(pfd);
	if(ret==-1)
	{
		show_err("pipe");
	}
	close(pfd[0]);
	 n = write(pfd[1],&c,1);
	printf("write:%d\n",n);
	

#if 0
	close(pfd[1]);
	n = read(pfd[0],&c,1);
	printf("read:%d\n",n);
#endif
	for(;;)
	{
		;
	}
}
