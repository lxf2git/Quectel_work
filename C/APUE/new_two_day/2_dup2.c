#include"../apue.h"

int main()
{
	char buf[] = "hi";
	int fd = open("b.txt",O_CREAT|O_EXCL|O_RDWR);	
	//if err
	
	dup2(fd,1);
	write(1,buf,sizeof(buf));


	return 0;

}
