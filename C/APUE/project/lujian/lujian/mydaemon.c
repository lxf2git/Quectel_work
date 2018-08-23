


#include"../apue.h" 


int main() 
{
	
	pid_t pid;
	if ((pid = fork()) < 0)
	{
		perror("fork");
		_exit(-1);
	}
	else if (pid==0)
	{
			sleep(1);

			setsid();
			int fd_log;
			int fd_null;
			int re, count =0;
			time_t tm;
			char timebuf[256];

			bzero(timebuf, sizeof(timebuf));

			chdir("/");

			umask(0);
			if ((fd_log = open("/tmp/time_log", O_RDWR|O_CREAT|O_TRUNC, 0666)) <= 0)
			{
					perror("open");
					_exit(-1);
			}

			if (fd_null = open("/dev/null", O_RDWR) < 0)
			{
					perror("open");
					_exit(-1);
			}

			dup2(fd_null, 0);
			dup2(fd_null, 1);
			dup2(fd_null, 2);

			while(1)
			{
					tm = time(NULL);
					sprintf(timebuf, "%s", ctime(&tm));
					if ((re = write(fd_log, timebuf, sizeof(timebuf))) < 0)
					{
							_exit(-1);
					}
					if (count == (60*60*24*7))
					{	
						ftruncate(fd_log, 0L);
						count=0;
					}
					bzero(timebuf, sizeof(timebuf));
					sleep(1);
					count++;
			}
	}

	else
	{
		exit(0);
	}

}
