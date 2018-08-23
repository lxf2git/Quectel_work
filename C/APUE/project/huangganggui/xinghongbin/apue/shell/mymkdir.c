#include <stdio.h>
#include <sys/stat.h>
int main(int argc ,char**argv)
{

		int ret;
		int i;
		if (argc ==1)
		{
				printf("mkdir: user------error\n");
				return -1;
		}
		for(i=1;i<argc;i++)
		{
				ret=mkdir(argv[i],0777);
				if(ret ==-1)
				{
						perror("mkdir");
						return -1;
				}
		}

		return 0;
}
