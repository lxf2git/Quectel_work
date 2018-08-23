#include"apue.h"

char filename[1024];

void func(int sig, siginfo_t *info, void *p)
{
	int i;
	char str[4];
	char str1[5];
//	printf("%d\n",info->si_value.sival_int);
	if(0 != info->si_value.sival_int)
	{
		memset(str1, 0, sizeof(str1));
	//	printf("%d\n",info->si_value.sival_int);
		for(i = 3; i >= 0; i--)
		{
			str1[i] = info->si_value.sival_int&0xff;
	//		printf("%d\n",str[i]);
			info->si_value.sival_int >>=8;
		}
	//	str1[4] = '\0';
		strcat(filename, str1);

	//	printf("%s\n",filename);
	}
	else
	{
	//	printf("dsadasdasd\n");
		union sigval val;
		int fd = open(filename, O_RDONLY);
		if(fd < 0)
		{
			perror("open");
			exit(-1);
		}
		while(1)
		{
			memset(str, 0 , sizeof(str));
			int ret = read(fd, str, sizeof(str));
			if(0 == ret)
			{
				val.sival_int = 0;
				sigqueue(info->si_pid, SIGUSR2, val);
				close(fd);
				exit(0);
			}
			val.sival_int = 0;
			for(i = 0; i < 4; i++)
			{
				val.sival_int<<=8;
				val.sival_int = val.sival_int|str[i];
			}
			sigqueue(info->si_pid, SIGUSR2, val);
			usleep(1);
		}
	}
}

int main()
{
	int fd = open("pid.txt",O_WRONLY);
	if(fd < 0)
	{
		perror("open");
		return -1;
	}
	pid_t pid = getpid();
//	printf("%d\n",pid);
	write(fd, &pid, sizeof(pid));
	close(fd);
	struct sigaction act;
	act.sa_sigaction = func;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	for(;;);
	return 0;
}
