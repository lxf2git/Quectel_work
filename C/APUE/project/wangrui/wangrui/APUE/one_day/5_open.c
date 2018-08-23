#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
int main()
{

		
	int fid = open("bc.txt",O_CREAT|O_EXCL);	
#if 0
	if(fid<0)
	{
		perror("open");
		return -1;
	}
#endif

#if 1
	if(fid<0)
	{
		if(errno==EEXIST)
		{
			fid = open("b.txt",O_RDWR);
			if(fid<0)
			{
				perror("open");
				return -1;
			}
		}
		else
		{
			return -1;
		
		}
	}
#endif



	close(fid);

	return 0;

}
