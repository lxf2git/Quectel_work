#include"../apue.h"

int main()
{
		int i;
		int j=0;
		int arr[3];
		pid_t pid=1;
		int fd = open("file",O_CREAT|O_TRUNC|O_WRONLY,0666);
		if(fd<0)	
		{
				perror("open");
		}
		for(i=0;i<3;i++)
		{
			if(fork()==0)
			{
					arr[i]=getpid();
					write(fd,&arr[i],sizeof(int));
					close(fd);
					break;
			}
			if(i==2)
			{
					close(fd);
					exit(0);
			}
		}
		while(1)
		{
		
				if(arr[0]==getpid())
				{	
						printf(" a ");
						fflush(stdout);
						sleep(1);
				}
				if(arr[1]==getpid())
				{
						printf(" b ");
						fflush(stdout);
						sleep(1);
				}
				if(arr[2]==getpid())
				{
						printf(" c ");
						fflush(stdout);
						sleep(1);
				}
		}
		
}
