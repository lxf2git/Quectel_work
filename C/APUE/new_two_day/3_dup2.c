#include"../apue.h"

int main()
{
	char buf[20] = {'\0'};
	int fd = open("file",O_RDWR);	
	//if err
	
	dup2(fd,0);
	read(0,buf,sizeof(buf)-1);
	printf("**%s",buf);


	return 0;

}
