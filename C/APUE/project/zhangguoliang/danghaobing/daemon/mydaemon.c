#include "../apue.h"

void dup_err(int a)
{
	if(a<0)
	{
			show_err("dup2");
	}
}

void set_err(int a)
{
		if(a<0)
	show_err("setsid");
}

int mydaemon(int nochdir,int noclose)
{
		pid_t pid = fork();
		fork_err(pid);
		int i=0;
		if(pid==0)
		{
			if(nochdir==0) chdir("/");
			set_err(setsid());
			umask(0);
			int c = open("/dev/null",O_WRONLY);
			if(c<0)	show_err("open");
			if(noclose==0)
			{
				for(i=0;i<3;i++)
				dup_err(dup2(c,i)); //重定向
			}
			return 0;

		}
	printf("echo /zgl.txt to see background process by youself!\n");
#if 1
		int a;
		char ka[50];
		sprintf(ka,"kill %d",pid);
		do
		{
			printf("1 close background process\n");
			printf("2 exit main function!\n");
			scanf("%d",&a);
			if(a==1)
			{
					system(ka);
					printf("close complete!\n");
					break;
			}
			i++;
		}while(i<2&&printf("another chance!\n"));
#endif	
		exit(0);
}
