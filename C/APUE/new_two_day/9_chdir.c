#include"../apue.h"

int main()
{
#if 0		
	chdir("/home");	
	mkdir("doudoudoudou",0777);
#endif
	char buf[100]={'\0'};
	 DIR *dp = opendir("/home");
	 mkdir("ruirui",0777);
	 getcwd(buf,sizeof(buf));
	 puts(buf);
}
