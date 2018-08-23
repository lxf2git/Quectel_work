#include"../apue.h"

int main()
{
	int status;
	int i;
	char *s = "abc";
	FILE *fp;
	pid_t pid;
	fp = fopen("stop.c","a+");
	for(i = 0; i < 3; i++)
	{
		if(fork() == 0)
		{
			pid = getpid();
			fseek(fp,0,SEEK_END);
			fwrite(&pid,sizeof(pid_t),1,fp);
			fclose(fp);
			for(;;)
			{
				write(1,s+i,1);
				sleep(1);
			}
			break;
		}
	}

	fclose(fp);
	//waitpid(-1,&status,0);
	//printf("%d %d\n",WIFSIGNALED(status),WTERMSIG(status));

	return 0;
}
