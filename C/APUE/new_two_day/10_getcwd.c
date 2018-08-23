#include"../apue.h"
int main()
{
	mkdir("hi",0777);	
	chdir("hi");
	char buf[100];	
	getcwd(buf,sizeof(buf));
	puts(buf);
	return 0;

}
