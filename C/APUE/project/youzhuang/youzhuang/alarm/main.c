#include"main.h"

int i;

int main()
{
		char ch;
		signal(SIGALRM, fun);
		alarm(5);
		while(1)
		{
				read(0,&ch,1);
				i++;
				printf("%d",i);
		}
		return 0;
}

void fun(int sig)
{
		printf("%d",i);
		exit(0);
}
