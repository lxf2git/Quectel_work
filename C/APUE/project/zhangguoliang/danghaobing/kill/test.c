#include "../apue.h"
int main()
{
		int a=100;
		int fd = open("record.txt",O_RDWR|O_TRUNC);
		char b[20];
		sprintf(b,"%d",a);
		sprintf(b,"%d",a);
		sprintf(b,"%d",a);
		write(fd,b,strlen(b));
		close(fd);
}
