#include"apue.h"

void func(int sig, siginfo_t *info, void *p)
{
	char str[5];
	int i;
	memset(str, 0, sizeof(str));
	if(0 != info->si_value.sival_int)
	{
		for(i = 3; i >= 0; i--)
		{
			str[i] = info->si_value.sival_int&0xff;
			info->si_value.sival_int>>=8;
		}
		str[4] = '\0';
		printf("%s",str);
		fflush(stdout);
	}
	else
	{
		exit(0);
	}
}

int main(int argc, char **argv)
{
	if(argc < 2)
	{
	//	printf("%s filename\n",argv[0]);
		return -1;
	}
	system("gcc sig_cat_b.c -o exe");
	system("./exe");
	int i;
	int fd = open("pid.txt", O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		return -1;
	}
	pid_t pid = 0;
	read(fd, &pid, sizeof(pid));
	close(fd);
//	printf("%d\n",pid);
	union sigval val;
	val.sival_int =0;
	for(i = 0; i < strlen(argv[1]); i++)
	{
		if(0 == i%4&&0 != i)
		{
			usleep(1);
	//		printf("%d\n",val.sival_int);
			sigqueue(pid, SIGUSR1, val);
			val.sival_int =0;
		}
		val.sival_int<<=8;
		val.sival_int = val.sival_int|argv[1][i];
	}
	val.sival_int<<=(8*(4-strlen(argv[1])%4));
	sigqueue(pid, SIGUSR1, val);
	usleep(1);
	val.sival_int = 0;
	sigqueue(pid, SIGUSR1, val);
	struct sigaction act;
	act.sa_sigaction = func;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR2, &act, NULL);
	for(;;);
	return 0;
}
