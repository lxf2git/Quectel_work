#include"../apue.h"
int main()
{
	char *const argv[]={"ls","-ld","/home",NULL};	
	puts("----execute-----");
	execvp("ls",argv);
	//execl("/bin/ls","ls","-ld","/home",NULL);
	//execv("/bin/ls",argv);	//which ls
	puts("----error-------");
	return 0;

}
