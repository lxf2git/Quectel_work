#include"../apue.h"
//mycp src des
int main(int argc,char **argv)
{
	char string[20];	
	if(argc!=3)
	{
		sprintf(string,"%s file_name ",argv[0]);
	}

	char buf[50];
	int n;
	int fd_s = open(argv[1],O_RDONLY);
	if(fd_s<0)
	{
		perror("open_source");
		return -1;
	}
	int fd_d = open(argv[2],O_CREAT|O_EXCL|O_WRONLY,0777);
	if(fd_d<0)
	{
		perror("open_des");
		goto ERR1;
		//return -1;
	}
	
	while(1)
	{
		n = read(fd_s,buf,sizeof(buf));
		if(0==n)
		{
			break;
		}
	
		if(n<0)
		{
			perror("read");
			goto ERR;
			//return -1;
		}
		write(fd_d,buf,n);
	}

	close(fd_s);
	close(fd_d);
	return 0;

ERR:
	printf("ERR\n");//close(fd_d);	
ERR1:
	printf("ERR1\n");//close(fd_s);
	return -1;
}

	
