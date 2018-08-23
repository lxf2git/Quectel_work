#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
void change(char *mode,int start_i,int mode_num)
{
	int num;
	if((num=(mode_num&0x01))==0)
	{
		mode[start_i+2]='-';
	}
	else
		mode[start_i+2]='x';
	if((num=(mode_num>>1)&0x01)==0)
	{
		mode[start_i+1]='-';
	}
	else
		mode[start_i+1]='w';
	if((num=(mode_num>>2)&0x01)==0)
	{
		mode[start_i]='-';
	}
	else
		mode[start_i]='r';
}
int main(int argc, char **argv)
{
	struct stat stat;
	char mode[11];

	if(argc!=2)
	{
			printf("%s name", argv[0]);
			return -1;
	}

	memset(mode, 0, sizeof(mode));
	lstat(argv[1], &stat);
	if(S_ISREG(stat.st_mode))
	{
		mode[0]='-';
	}
	else 
		if(S_ISDIR(stat.st_mode))
		{
			mode[0]='d';
		}
		else
			if(S_ISCHR(stat.st_mode))
			{
					mode[0]='c';
			}
			else
				if(S_ISBLK(stat.st_mode))
				{
						mode[0]='b';
				}
				else
					if(S_ISFIFO(stat.st_mode))
					{
							mode[0]='p';
					}
					else
						if(S_ISLNK(stat.st_mode))
						{
								mode[0]='l';
						}
						else
							if(S_ISSOCK(stat.st_mode))
							{
									mode[0]='s';
							}

	int mode_num=0;
	mode_num=(stat.st_mode>>6)&0x7;
	change(mode,1,mode_num);

	mode_num=(stat.st_mode>>3)&0x7;
	change(mode,4,mode_num);

	mode_num=stat.st_mode&0x7;
	change(mode,7,mode_num);
	printf("mode=%s\n", mode);

	return 0;
}












