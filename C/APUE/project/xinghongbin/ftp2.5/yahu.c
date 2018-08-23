#include"/home/zll/zuoye/APUE/apue.h"
#include<sys/time.h>
int main()
{
	int pfd[2];
	char c = 'a';
	int ret = pipe(pfd);
	if(ret == -1)
	{
		perror("pipe");
	}
	close(pfd[1]);
	int n = write(pfd[0],&c,1);
	printf("write:%d\n",n);
	for(;;)
	{	
		;		
	}
}
