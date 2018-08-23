#include<stdio.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>
#include <curses.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void input_char(char* buf);
int length;
void fun(int sig)
{
		system("stty cooked");
		printf("\nalam:%d\n",length);
		exit(0);
}
int main()
{
		char buf[1024];
		memset(buf,0,sizeof(buf));

		signal(SIGALRM,fun);
		alarm(5);
		while(1)
		{
				input_char(buf);
		}
}
void input_char(char *buf)
{
		int a,i;
		char ch;
		int fd;
		system("stty raw ");
		a = getchar();
		system("stty cooked");
		strcat(buf,(char*)&a);
		length = strlen(buf);
}

