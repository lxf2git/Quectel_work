#include "../apue.h"

int main(int argc, char **argv)
{
	struct stat stat;
	char mode[11];//0 1-9 10
	int ret;
	int i;
	int mode_num=0;
	//穷举法
	char mode_str[][4]={"---",
			            "--x",
						"-w-",
						"-wx",
						"r--",
						"r-x",
						"rw-",
						"rwx"};

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
#if 0
	mode_num=(stat.st_mode>>6)&0x7;
	printf("1:%d\n", mode_num);

	mode_num=(stat.st_mode>>3)&0x7;
	printf("2:%d\n", mode_num);

	mode_num=stat.st_mode&0x7;
	printf("3:%d\n", mode_num);
#endif

	for(i=6; i>=0; i=i-3)
	{
		mode_num=(stat.st_mode>>i)&0x7;//7
		strcat(mode,mode_str[mode_num]);
	}
	
	printf("mode=%s\n", mode);

	return 0;
}


