#include"../apue.h"
int main()
{
	printf("a.out:%d\n",getpid());	
	setenv("USER","u6",0);	
	 char *str = getenv("USER");
	 puts(str);
	return 0;

}
