
#include "../apue.h"
void char_mode(int mode_num,int num,char *mode);

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

//	int mode_num=0;
//	mode_num=(stat.st_mode>>6)&0x7;
	
	char_mode((stat.st_mode>>6)&0x7,1,mode);
//	mode_num=(stat.st_mode>>3)&0x7;
//	printf("2:%d\n", mode_num);
	char_mode((stat.st_mode>>3)&0x7,4,mode);
	char_mode((stat.st_mode)&0x7,7,mode);

//	mode_num=stat.st_mode&0x7;
//	printf("3:%d\n", mode_num);
	printf("%s\n",mode);
	

	return 0;
}
void char_mode(int mode_num,int num,char *mode)
{
		if(mode_num&0x4)
		mode[num]='r';
		else
				mode[num]='-';

		if(mode_num&0x2)
		mode[num+1]='w';
		else
				mode[num+1]='-';
		if(mode_num&0x1)
		mode[num+2]='x';
		else
				mode[num+2]='-';
}
