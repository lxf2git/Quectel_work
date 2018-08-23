 #include <signal.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
		signal(SIGUSR1,SIG_IGN);
		printf("%d\n",getpid());
		pause();
		printf("21212\n");
}
