#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char**argv)
{
		int i=0;
		int ret;
		int fd;

//		printf("%d\n",sizeof(argv));
#if 1
		if(0==fork())
		{
				umask(0);
				fd = open("./temp",O_WRONLY|O_CREAT|O_TRUNC);
				if(fd == -1)
				{
						perror("open");
				}
//				dup2();
				while(1)
				{
						sleep(5);
						for(i=0;argv[i] != NULL;i++)
						{
								ret = write(fd,argv[i],sizeof(argv));
								if(ret <0)
										perror("read");
								write(fd," ",1);

						}
						write(fd,"\n",1);

				}
		}
		exit(0);
#endif

}
